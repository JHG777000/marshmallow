/*
 Copyright (c) 2019 Jacob Gordon. All rights reserved.

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 #include "marshmallow.h"
 #include "marshmallow_cfg.h"
 #include <tree_sitter/api.h>

 extern const TSLanguage *tree_sitter_marshmallow() ;

 static char* cfggen_readfile_for_tree_sitter( FILE* file ) {

   int c = 0 ;

   int word_size = 1 ;

   char* word = RKMem_CArray(1, char) ;

   word[word_size-1] = '\0' ;

   while ( (c = fgetc(file)) != EOF ) {

     word = RKMem_Realloc(word, word_size+1, word_size, char, 1) ;

     word_size++ ;

     word[word_size-2] = c ;

     word[word_size-1] = '\0' ;

   }

   return word ;

 }

 static char* cfggen_get_string_value_from_node( TSNode node, char* source_code ) {

  int start = ts_node_start_byte(node) ;

  int end = ts_node_end_byte(node) ;

  RKString string = RKString_NewEmptyString((end - start)+1) ;

  char* value = RKString_ConvertToCString(string) ;

  int i = start ;

  int j = 0 ;

  while ( i < end ) {

    value[j] = source_code[i] ;

    i++ ;

    j++ ;

  }

   return value ;

 }

 #define dispatcher(name)  static void dispatcher_##_##name( marshmallow_context context, TSNode node, cfg_module* module, cfg_function_body* function, char* source_code )

 #define get_dispatcher(name) dispatcher_##_##name(context,node,module,function,source_code)

 #define dispatch(name) dispatched = 0 ; if ( strcmp(ts_node_type(node), #name) == 0 ) {dispatched = 1 ; get_dispatcher(name);}

 #define is_node_type(node,type) (strcmp(ts_node_type(node), #type) == 0)

 #define get_line (ts_node_start_point(node).row+1)

 #define get_node(index) ts_node_named_child(node,index)

 dispatcher(module_definition) {

  cfg_module new_module ;

  if ( !is_node_type(get_node(0),identifier) ) {

      printf("On line: %d, %s is not an identifier.\n",get_line,cfggen_get_string_value_from_node(get_node(0),source_code)) ;

      exit(EXIT_FAILURE) ;
  }

  if ( !RKStore_ItemExists(context->modules, cfggen_get_string_value_from_node(get_node(0),source_code)) ) {

      new_module = cfg_new_module(RKString_NewStringFromCString(cfggen_get_string_value_from_node(get_node(0),source_code))) ;

      cfg_add_module_to_context(new_module, context) ;
  }

  new_module = RKStore_GetItem(context->modules, cfggen_get_string_value_from_node(get_node(0),source_code)) ;

  *module = new_module ;

  printf("%s\n",RKString_GetString((*module)->name));

 }

 dispatcher(function_definition) {

   int is_function = 0 ;

   char* name = NULL ;

   if ( is_node_type(get_node(0), is_function ) ) is_function = 1 ;

   if ( !is_node_type(get_node(1), identifier) ) {

       printf("On line: %d, %s is not an identifier.\n",get_line,cfggen_get_string_value_from_node(get_node(1),source_code)) ;

       exit(EXIT_FAILURE) ;
   }

   name = cfggen_get_string_value_from_node(get_node(1),source_code) ;

   cfg_function_signature function_signature = cfg_new_function_signature(RKString_NewStringFromCString(name), is_function) ;

   cfg_function_body new_function = cfg_new_function_body(function_signature) ;

   cfg_add_function_to_module(new_function, *module) ;

   *function = new_function ;

   printf("%s\n",RKString_GetString((*function)->signature->func_name));

 }

 dispatcher(definition) {

  int i = 0 ;

  int dispatched = 0 ;

  TSNode main_node = node ;

  while ( i < ts_node_named_child_count(main_node) ) {

    node = ts_node_named_child(main_node,i) ;

    dispatch(module_definition) ;

    //dispatch(declaration_definition) ;

    dispatch(function_definition) ;

    //dispatch(variable_definition) ;

    //dispatch(enum_definition) ;

    //dispatch(compound_macro) ;

    //dispatch(end_compound_macro) ;

    i++ ;
  }

 }

 dispatcher(source_file) {

  int i = 0 ;

  int dispatched = 0 ;

  TSNode main_node = node ;

  while ( i < ts_node_named_child_count(main_node) ) {

    node = ts_node_named_child(main_node,i) ;

    printf("%s\n",ts_node_type(node));

    dispatch(definition) ;

    i++ ;
  }

 }

 static void cfggen_generate_control_flow_graph( marshmallow_context context, TSNode node, char* source_code ) {

   int dispatched = 0 ;

   cfg_module m = NULL ;

   cfg_module* module = &m ;

   cfg_function_body f = NULL ;

   cfg_function_body* function = &f ;

   dispatch(source_file) ;

   if ( !dispatched ) {

     printf("On line: %d, error parsing source file at root.\n",get_line) ;

     exit(EXIT_FAILURE) ;

   }

 }

 void marshmallow_parse_string_and_gen_cfg( marshmallow_context context, char* source_code ) {

  if ( context->parser == NULL ) {

    context->parser = ts_parser_new() ;

    ts_parser_set_language(context->parser, tree_sitter_marshmallow()) ;

  }

  TSTree *tree = ts_parser_parse_string(context->parser, NULL, source_code, strlen(source_code));

  TSNode root_node = ts_tree_root_node(tree) ;

  cfggen_generate_control_flow_graph(context,root_node,source_code) ;

  ts_tree_delete(tree) ;

 }

 void marshmallow_parse_file_and_gen_cfg( marshmallow_context context, FILE* file ) {

  char* source_code = cfggen_readfile_for_tree_sitter(file) ;

  //printf("%s\n",source_code) ;

  marshmallow_parse_string_and_gen_cfg(context,source_code) ;

  free(source_code) ;

 }

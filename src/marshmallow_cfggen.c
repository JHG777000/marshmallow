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


 #define is_node_type(node,type) (strcmp(ts_node_type(node), #type) == 0)

 #define scmp(s0,s1) (strcmp(s0,s1) == 0)

 #define get_line (ts_node_start_point(node).row+1)

 #define get_node(index) ts_node_named_child(node,index)


 static RKStack cfggen_new_scope_stack( void ) {

  return RKStack_NewStack() ;

 }

 static void cfggen_destroy_scope_stack( RKStack scope_stack ) {

  RKStack_DestroyStack(scope_stack) ;

 }

 static void cfggen_add_to_scope_stack( marshmallow_entity entity, RKStack scope_stack, TSNode node ) {

  switch (entity->entity_type) {

    case entity_module:

        if ( !RKStack_IsEmpty(scope_stack) ) {

            printf("On line: %d, module does not end.\n",get_line) ;

            exit(EXIT_FAILURE) ;
        }

        break;

     case entity_function:

        if ( RKStack_IsEmpty(scope_stack) ) {

            printf("On line: %d, no scope.\n",get_line) ;

            exit(EXIT_FAILURE) ;
        }

        if ( !(((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_module) ) {

            printf("On line: %d, expected module. Function and methods must exist within a module.\n",get_line) ;

            exit(EXIT_FAILURE) ;
        }

        if ( ((cfg_function_body)entity)->signature->is_declared ) {

            cfg_add_declaration_to_module(entity, RKStack_Peek(scope_stack)) ;

        } else {

            cfg_add_function_to_module((cfg_function_body)entity, RKStack_Peek(scope_stack)) ;

            RKStack_Push(scope_stack, entity) ;
        }

        break;

        default:
         break;

  }

 }

 static marshmallow_entity cfggen_generate_control_flow_graph( marshmallow_context context,
  cfg_module module, marshmallow_entity scope, TSNode node, char* source_code ) {

  int i = 0 ;

  int index = 0 ;

  TSNode subnode ;

  char* value = NULL ;

  marshmallow_entity entity = NULL ;

  static marshmallow_entity no_error = NULL ;

  marshmallow_access_control access_control = public ;

  if ( no_error == NULL ) {

    no_error = RKMem_NewMemOfType(struct marshmallow_entity_s) ;

    no_error->entity_type = entity_nothing ;

  }

  if ( is_node_type(node,source_file) || is_node_type(node,definition) ) {

    i = 0 ;

    while ( i < ts_node_named_child_count(node) ) {

      subnode = ts_node_named_child(node,i) ;

      printf("%s\n",ts_node_type(subnode)) ;

      entity = cfggen_generate_control_flow_graph(context, module, scope, subnode, source_code) ;

      if ( entity == NULL ) return NULL ;

      if ( entity->entity_type == entity_module ) module = (cfg_module)entity ;

      if ( entity->entity_type == entity_function ) scope = entity ;

      i++ ;

    }

    return no_error ;

  }

  if ( is_node_type(node,module_definition) ) {

    cfg_module new_module ;

    value = cfggen_get_string_value_from_node(get_node(0),source_code) ;

    if ( !is_node_type(get_node(0),identifier) ) {

        printf("On line: %d, %s is not an identifier.\n",get_line,value) ;

        exit(EXIT_FAILURE) ;
    }

    if ( !RKStore_ItemExists(context->modules, value) ) {

        new_module = cfg_new_module(RKString_NewStringFromCString(value)) ;

        cfg_add_module_to_context(new_module, context) ;
    }

    new_module = RKStore_GetItem(context->modules, value) ;

    printf("%s\n",RKString_GetString(new_module->name));

    free(value) ;

    return (marshmallow_entity)new_module ;

  }

  if ( is_node_type(node,function_definition) ) {

    index = 0 ;

    int is_function = 0 ;

    access_control = public ;

    if ( is_node_type(get_node(index), access_control) ) {

     value = cfggen_get_string_value_from_node(get_node(index),source_code) ;

     if ( scmp(value, "private") ) access_control = private ;

     if ( scmp(value, "protected") ) access_control = protected ;

     if ( scmp(value, "publish") ) access_control = publish ;

     free(value) ;

     index++ ;

    }

    if ( is_node_type(get_node(index), is_function ) ) is_function = 1 ;

   index++ ;

    if ( !is_node_type(get_node(index), identifier) ) {

        printf("On line: %d, %s is not an identifier.\n",get_line,cfggen_get_string_value_from_node(get_node(index),source_code)) ;

        exit(EXIT_FAILURE) ;
    }

    value = cfggen_get_string_value_from_node(get_node(index),source_code) ;

    cfg_function_signature function_signature = cfg_new_function_signature(RKString_NewStringFromCString(value), is_function) ;

    cfg_function_body new_function = cfg_new_function_body(function_signature) ;

    cfg_add_function_to_module(new_function, module) ;

    function_signature->access_control = access_control ;

    index++ ;

    if ( is_node_type(get_node(index), parameter_list) ) {

      i = 0 ;

      subnode = get_node(index) ;

      while ( i < ts_node_named_child_count(subnode) ) {

       if ( is_node_type(get_node(i),variable_definition) ) printf("%s\n", ts_node_type(ts_node_named_child(subnode,i))) ;

       i++ ;

     }

    }

    printf("%s\n",RKString_GetString(new_function->signature->func_name)) ;

    free(value) ;

    return (marshmallow_entity)new_function ;

  }


  return NULL ;

 }

 void marshmallow_parse_string_and_gen_cfg( marshmallow_context context, marshmallow_entity module, marshmallow_entity scope, char* source_code ) {

  if ( context->parser == NULL ) {

    context->parser = ts_parser_new() ;

    ts_parser_set_language(context->parser, tree_sitter_marshmallow()) ;

  }

  TSTree *tree = ts_parser_parse_string(context->parser, NULL, source_code, strlen(source_code));

  TSNode root_node = ts_tree_root_node(tree) ;

  marshmallow_entity error = cfggen_generate_control_flow_graph(context, (cfg_module)module, scope, root_node, source_code) ;

  if ( error == NULL ) {

    printf("On line: %d, error parsing source file at root.\n",ts_node_start_point(root_node).row+1) ;

    exit(EXIT_FAILURE) ;

  } else {

    free(error) ;

  }

  ts_tree_delete(tree) ;

 }

 void marshmallow_parse_file_and_gen_cfg( marshmallow_context context, FILE* file ) {

  char* source_code = cfggen_readfile_for_tree_sitter(file) ;

  //printf("%s\n",source_code) ;

  marshmallow_parse_string_and_gen_cfg(context,NULL,NULL,source_code) ;

  free(source_code) ;

 }

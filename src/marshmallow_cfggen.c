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

 static char* cfggen_readfile_for_tree_sitter( RKFile file ) {

   int c = 0 ;

   int word_size = 1 ;

   int* word = RKMem_CArray(1, int) ;

   word[word_size-1] = '\0' ;

   while ( (c = RKFile_GetUTF32Character(file)) != EOF ) {

     if ( c == 8203 ) c = 32  ;

     word = RKMem_Realloc(word, word_size+1, word_size, int, 1) ;

     word_size++ ;

     word[word_size-2] = c ;

     word[word_size-1] = '\0' ;

   }

   return RKString_ConvertToCString(RKString_NewStringFromUTF32(word,word_size-1)) ;

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

 void cfggen_generate_control_flow_graph( marshmallow_context context, TSNode node ) {

   cfg_module module = NULL ;

   cfg_function_body function = NULL ;



 }

 void marshmallow_parse_string_and_gen_cfg( marshmallow_context context, char* string ) {

  char* source_code = string ;

  if ( context->parser != NULL ) {

    context->parser = ts_parser_new() ;

    ts_parser_set_language(context->parser, tree_sitter_marshmallow()) ;

  }

  TSTree *tree = ts_parser_parse_string(context->parser, NULL, source_code, strlen(source_code));

  TSNode root_node = ts_tree_root_node(tree) ;

  cfggen_generate_control_flow_graph(context,root_node) ;

  ts_tree_delete(tree) ;

 }

 void marshmallow_parse_file_and_gen_cfg( marshmallow_context context, RKFile file ) {

  char* source_code = cfggen_readfile_for_tree_sitter(file) ;

  marshmallow_parse_string_and_gen_cfg(context,source_code) ;

  free(source_code) ;

 }

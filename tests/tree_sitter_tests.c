/*
 Copyright (c) 2018-2019 Jacob Gordon. All rights reserved.

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

#include <assert.h>
#include "marshmallow.h"
#include <tree_sitter/api.h>

extern const TSLanguage *tree_sitter_marshmallow() ;

char* readfile_for_tree_sitter( FILE* file ) {

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

int main(int argc, const char **argv) {

  // Create a parser.
  TSParser *parser = ts_parser_new() ;


  ts_parser_set_language(parser, tree_sitter_marshmallow()) ;

  // Build a syntax tree based on source code stored in a string.
  char* source_code = readfile_for_tree_sitter(fopen(argv[1], "r")) ;
  printf("%s\n",source_code) ;
  TSTree *tree = ts_parser_parse_string(
    parser,
    NULL,
    source_code,
    strlen(source_code)
  );

  // Get the root node of the syntax tree.
  TSNode root_node = ts_tree_root_node(tree) ;

  // Get some child nodes.
  //TSNode array_node = ts_node_named_child(root_node, 0);
  //TSNode number_node = ts_node_named_child(array_node, 0);

  // Check that the nodes have the expected types.
  //assert(strcmp(ts_node_type(root_node), "value") == 0);
  //assert(strcmp(ts_node_type(array_node), "array") == 0);
  //assert(strcmp(ts_node_type(number_node), "number") == 0);

  // Check that the nodes have the expected child counts.
  //assert(ts_node_child_count(root_node) == 1);
  //assert(ts_node_child_count(array_node) == 5);
  //assert(ts_node_named_child_count(array_node) == 2);
  //assert(ts_node_child_count(number_node) == 0);

  // Print the syntax tree as an S-expression.
  char *string = ts_node_string(root_node) ;
  printf("Syntax tree: %s\n", string) ;

  // Free all of the heap-allocated memory.
  free(string) ;
  free(source_code) ;
  ts_tree_delete(tree) ;
  ts_parser_delete(parser) ;
}

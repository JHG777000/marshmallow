/*
 Copyright (c) 2019-2020 Jacob Gordon. All rights reserved.

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
#include "marshmallow_mab.h"


mab_node mab_new_node( mab_node_type node_type ) {

  mab_node node = RKMem_NewMemOfType(struct mab_node_s) ;

  node->entity_type = mab_entity_node ;

  node->node_type = node_type ;

  node->array_of_nodes = NULL ;

  node->num_of_nodes = 0 ;

  node->definition = NULL ;

  node->supernode = NULL ;

  node->subnodes[0] = NULL ;

  node->subnodes[1] = NULL ;

  node->value.root_type = mab_type_i8 ;

  node->value.val_i8 = 0 ;

  return node ;

}

void mab_destroy_node( mab_node node ) {

  free(node) ;

}

void mab_set_node_value( mab_node node, mab_value value ) {

  node->value = value ;

}

void mab_set_node_definition( mab_node node, mab_definition definition)  {

}

void mab_add_node_to_supernode( mab_node node, int subnode, mab_node supernode ) {

  supernode->subnodes[subnode] = node ;

}

mab_node mab_add_new_node_to_supernode( mab_node_type node_type, int subnode, mab_node supernode ) {

  return supernode->subnodes[subnode] = mab_new_node(node_type) ;

}

void mab_add_node_to_tree( mab_node node, mab_node last_node ) {

  last_node->subnodes[(last_node->subnodes[0] == NULL) ? 1 : 0] = node ;

}

void mab_add_new_node_to_tree( mab_node_type node_type, mab_node last_node ) {

  last_node->subnodes[(last_node->subnodes[0] == NULL) ? 1 : 0] = mab_new_node(node_type) ;

}

mab_definition mab_new_definition( RKString name, mab_definition_type definition_type ) {

  mab_definition definition = RKMem_NewMemOfType(struct mab_definition_s) ;

  definition->entity_type = mab_entity_definition ;

  definition->definition_type = definition_type ;

  definition->name = name ;

  definition->definitions = NULL ;

  definition->attributes = NULL ;

  definition->properties = NULL ;

  definition->type = NULL ;

  definition->type_tree = NULL ;

  definition->is_evaluating = 0 ;

  definition->is_evaluated = 0 ;

  definition->is_processed = 0 ;

  return definition ;

}

void mab_destroy_definition( mab_definition definition ) {

  RKString_DestroyString(definition->name) ;

  free(definition) ;

}

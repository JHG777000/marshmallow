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

static void DeleteValueInCollection( void* data ) {

    if (((mab_value*)data)->entity_type == mab_entity_value) free(data) ;
}

mab_collection mab_new_collection( void ) {

  mab_collection collection = RKMem_NewMemOfType(struct mab_collection_s) ;

  collection->entity_type = mab_entity_collection ;

  collection->array_of_items = NULL ;

  collection->num_of_items = 0 ;

  return collection ;

}

static void iterate_with( RKMemIteratorFuncType iterator, mab_collection collection ) {

     int i = 0 ;

     void* data = NULL ;

     while ( i < collection->num_of_items ) {

         data = collection->array_of_items[i] ;

         iterator(data) ;

         i++ ;
     }

}

void mab_destroy_collection( mab_collection collection ) {

  iterate_with(DeleteValueInCollection, collection) ;

  free(collection->array_of_items) ;

  free(collection) ;
}

void mab_add_item_to_collection( void* item, mab_collection collection ) {

  collection->num_of_items++ ;

  if ( collection->array_of_items == NULL ) {

     collection->array_of_items = RKMem_CArray(collection->num_of_items,void*) ;

  } else {

    collection->array_of_items = RKMem_Realloc(collection->array_of_items,
      collection->num_of_items,
      collection->num_of_items-1,
      void*,
      1);

  }

   collection->array_of_items[collection->num_of_items-1] = item ;
}

void mab_add_value_to_collection( mab_value value, mab_collection collection ) {

  value.entity_type = mab_entity_value ;

  mab_add_item_to_collection(rkany(value), collection) ;

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

  definition->eval_count = 0 ;

  definition->is_evaluating = 0 ;

  definition->is_evaluated = 0 ;

  definition->is_processed = 0 ;

  definition->id = 0 ;

  return definition ;

}

void mab_destroy_definition( mab_definition definition ) {

  RKString_DestroyString(definition->name) ;

  free(definition) ;

}

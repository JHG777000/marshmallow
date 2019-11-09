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
#include "mab.h"

mab_list mab_new_list( mab_op op ) {

 mab_list new_list = RKMem_NewMemOfType(struct mab_list_s) ;

 new_list->array = NULL ;

 new_list->num_of_elements = 0 ;

 new_list->list_array = NULL ;

 new_list->num_of_elements_list_array = 0 ;

 new_list->string_array = NULL ;

 new_list->num_of_elements_string_array = 0 ;

 new_list->op = op ;

 new_list->scope = NULL ;

 return new_list ;

}

void mab_destroy_list( mab_list list ) {

 int i = 0 ;

 while ( i < list->num_of_elements_list_array ) {

    mab_destroy_list(list->list_array[i]) ;

    i++ ;
 }

 free(list->list_array) ;

 i = 0 ;

 while ( i < list->num_of_elements_string_array ) {

    RKString_DestroyString(list->string_array[i]) ;

    i++ ;
 }

 free(list->string_array) ;

 free(list->array) ;

 free(list) ;

}

void mab_add_to_list( mab_list list, void* item, int item_is_list ) {

 list->num_of_elements++ ;

 if ( list->array == NULL ) {

   list->array = RKMem_CArray(list->num_of_elements,void*) ;

 } else if ( list->array != NULL ) {

   list->array = RKMem_Realloc(list->array,list->num_of_elements,list->num_of_elements-1,void*,1) ;

 }

 if ( list->array != NULL ) list->array[list->num_of_elements-1] = item ;

 if ( item_is_list == -1 ) return ;

 if ( item_is_list ) {

   list->num_of_elements_list_array++ ;

   if ( list->list_array == NULL ) {

     list->list_array = RKMem_CArray(list->num_of_elements_list_array,mab_list) ;

   } else if ( list->list_array != NULL ) {

     list->list_array = RKMem_Realloc(list->list_array,list->num_of_elements_list_array,list->num_of_elements_list_array-1,mab_list,1) ;

   }

   if ( list->list_array != NULL ) list->list_array[list->num_of_elements_list_array-1] = item ;

 } else {

   list->num_of_elements_string_array++ ;

   if ( list->string_array == NULL ) {

     list->string_array = RKMem_CArray(list->num_of_elements_string_array,RKString) ;

   } else if ( list->string_array != NULL ) {

     list->string_array = RKMem_Realloc(list->string_array,list->num_of_elements_string_array,list->num_of_elements_string_array-1,RKString,1) ;

   }

   if ( list->string_array != NULL ) list->string_array[list->num_of_elements_string_array-1] = item ;

 }

}

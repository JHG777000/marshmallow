/*
 Copyright (c) 2017 Jacob Gordon. All rights reserved.
 
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


static void typecheck_type( marshmallow_variable variable, marshmallow_module module ) {
    
    marshmallow_type t = variable->type ;
    
    if ( variable->type->root_type == unknown && variable->type->type_name != NULL ) {
        
        variable->type = RKStore_GetItem(module->types, RKString_GetString(variable->type->type_name)) ;
        
         free(t) ;
        
        if ( variable->type == NULL ) {
            
            printf("Type given to variable: '%s', does not exist.\n",RKString_GetString(variable->name)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
    }
}

static void typecheck_variable( marshmallow_variable variable, marshmallow_module module ) {
    
    
    typecheck_type(variable,module) ;
    
    if ( variable->static_assignment != NULL ) {
    
        if ( variable->static_assignment->type->root_type == hex ) {
            
            variable->static_assignment->type->root_type = u64 ;
        }
        
      if ( variable->type->root_type != variable->static_assignment->type->root_type ) {
        
          printf("variable: '%s', is being statically assigned with a value that is not of its type.\n",RKString_GetString(variable->name)) ;
          
          exit(EXIT_FAILURE) ;
      }
        
    }
}

static void typecheck_module( marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(module->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_variable(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
}

void marshmallow_typecheck( marshmallow_context context ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(context->modules) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            typecheck_module(RKList_GetData(node)) ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }

}

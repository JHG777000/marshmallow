/*
 Copyright (c) 2018 Jacob Gordon. All rights reserved.
 
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
#include "marshmallow_codegen.h"

mlb_statement mlb_add_statement( mlb_op_type op, cg_routine routine, RKString A, RKString B, RKString C ) {
    
    mlb_statement statement = RKMem_NewMemOfType(struct mlb_statement_s) ;
    
    statement->op = op ;
    
    statement->A = ( A != NULL ) ? RKStore_GetItem(routine->variables, RKString_GetString(A)) : NULL ;
    
    statement->B = ( B != NULL ) ? RKStore_GetItem(routine->variables, RKString_GetString(B)) : NULL ;
    
    statement->C = ( C != NULL ) ? RKStore_GetItem(routine->variables, RKString_GetString(C)) : NULL ;
    
    if ( routine->mlb_code == NULL ) routine->mlb_code = RKList_NewList() ;
    
    RKList_AddToList(routine->mlb_code, statement) ;
    
    statement->routine = routine ;
    
    return statement ;
}

void mlb_destroy_statement( mlb_statement statement ) {
    
    free(statement) ;
}

void mlb_validate_context( cg_context context ) {
    
    RKList_node node = RKList_GetFirstNode(RKStore_GetList(context->modules)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_module(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
}

void mlb_validate_module( cg_module module ) {
    
    RKList_node node = RKList_GetFirstNode(RKStore_GetList(module->variables)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_variable(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(module->variable_declarations)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_variable(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(module->routines)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_routine(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(module->routine_declarations)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_routine(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
}

void mlb_validate_routine( cg_routine routine ) {
    
    RKList_node node = RKList_GetFirstNode(RKStore_GetList(routine->parameters)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_variable(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(routine->variables)) ;
    
    while ( node != NULL ) {
        
        mlb_validate_variable(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    node = RKList_GetFirstNode(routine->mlb_code) ;
    
    while ( node != NULL ) {
        
        mlb_validate_statement(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
}

void mlb_validate_variable( cg_variable variable ) {
    
    if ( (variable->mlb_return_value < 0 && variable->mlb_get_return_value < 0) || variable->num_of_items < 0 ) {
        
        printf("codegen error: failed to validate a cg variable.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->values != NULL ) {
        
        RKList_node node = RKList_GetFirstNode(variable->values) ;
        
        while ( node != NULL ) {
            
         mlb_validate_variable(RKList_GetData(node)) ;
            
         node = RKList_GetNextNode(node) ;
            
        }
    }
}

void mlb_validate_statement( mlb_statement statement ) {
    
    if ( statement->A != NULL ) mlb_validate_variable(statement->A) ;
    
    if ( statement->B != NULL ) mlb_validate_variable(statement->B) ;
    
    if ( statement->C != NULL ) mlb_validate_variable(statement->C) ;
    
    switch (statement->op) {
       
      case mlb_struct_access:
      
            if (statement->A == NULL || statement->B == NULL || statement->C == NULL || statement->C->value == NULL || statement->B->type != class
                || statement->B->values_struct == NULL
                || RKStore_GetItem(statement->B->values_struct, RKString_GetString(statement->C->value)) == NULL
                || statement->A->type != ((cg_variable)RKStore_GetItem(statement->B->values_struct, RKString_GetString(statement->C->value)))->type) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
      break;
            
      case mlb_array_index:
            
            if (statement->A == NULL || statement->B == NULL || statement->C == NULL || statement->B->type != array || statement->B->ptr == NULL
                || statement->A->type != ((cg_variable)statement->B->ptr)->type
                || !(statement->C->type == u32 || statement->C->type == u64) ) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
      break;
            
       case mlb_cast:
            
            if (statement->A == NULL || statement->B == NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
       break;
            
       case mlb_sizeof:
            
            if (statement->A == NULL || statement->B == NULL || statement->A->type != pointer || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
        case mlb_deref:
            
            if (statement->A == NULL || statement->B == NULL || statement->B->type != ptr || statement->B->ptr == NULL
                || statement->A->type != ((cg_variable)statement->B->ptr)->type || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
        case mlb_addrof:
            
            if (statement->A == NULL || statement->B == NULL || statement->A->ptr == NULL || statement->A->type != ptr
                || ((cg_variable)statement->A->ptr)->type != statement->B->type || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
            
            
        case mlb_set:
            
            if (statement->A == NULL || statement->B == NULL || statement->A->type != statement->B->type || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
        
        case mlb_if:
        case mlb_else_if:
        case mlb_while:
        case mlb_switch:
        case mlb_goto:
        case mlb_section:
        case mlb_memcpy:
        case mlb_call:
            
            if (statement->A == NULL || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
        case mlb_else:
        case mlb_endif:
        case mlb_endwhile:
        case mlb_endswitch:
        case mlb_endcase:
        case mlb_default:
        case mlb_break:
        case mlb_continue:
        case mlb_return:
            
            if (statement->A != NULL || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
            
        default:
            
            if (statement->A == NULL || statement->B == NULL || statement->C == NULL
                || statement->A->type != statement->B->type || statement->A->type != statement->C->type) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
    }
}

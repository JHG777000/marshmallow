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

#include "marshmallow.h"
#include "marshmallow_codegen.h"

static cg_variable mlb_get_variable( cg_routine routine, RKString var ) {
    
    cg_variable variable = RKStore_GetItem(routine->variables, RKString_GetString(var)) ;
    
    if ( variable == NULL ) variable = RKStore_GetItem(routine->parameters, RKString_GetString(var)) ;
    
    if ( variable == NULL ) variable = RKStore_GetItem(routine->module->variables, RKString_GetString(var)) ;
    
    return variable ;
}

static void mlb_add_call_to_routine( cg_variable call, cg_routine routine ) {
    
    RKList list = NULL ;
    
    cg_routine routine_to_call = NULL ;
    
    list = call->values ;
    
    if ( list != NULL ) {
        
        routine_to_call = RKList_GetData(RKList_GetFirstNode(list)) ;
    }
    
    if ( routine_to_call != NULL ) {
        
        RKStore_AddItem(routine->calls, routine_to_call, RKString_GetString(routine_to_call->name)) ;
    }
}

mlb_statement mlb_add_statement( cg_op_type op, cg_routine routine, cg_variable A, cg_variable B, cg_variable C ) {
    
    mlb_statement statement = RKMem_NewMemOfType(struct mlb_statement_s) ;
    
    statement->op = op ;
    
    statement->entity_type = cg_entity_mlb_statement ;
    
    statement->A = ( A != NULL ) ? (A->is_literal) ? A : mlb_get_variable(routine, A->name) : NULL ;
    
    statement->B = ( B != NULL ) ? (B->is_literal) ? B : mlb_get_variable(routine, B->name) : NULL ;
    
    statement->C = ( C != NULL ) ? (C->is_literal) ? C : mlb_get_variable(routine, C->name) : NULL ;
    
    if ( routine->mlb_code == NULL ) routine->mlb_code = RKList_NewList() ;
    
    if ( statement->op == cg_call ) mlb_add_call_to_routine(statement->A, routine) ;
    
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
    
    RKList_node node = RKList_GetFirstNode(routine->return_types) ;
    
    while ( node != NULL ) {
        
        mlb_validate_variable(RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(routine->parameters)) ;
    
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
    
    if ( variable->entity_type != cg_entity_variable ) return ;
    
    if ( variable->class_element != NULL && variable->index >= 0 ) {
        
        printf("codegen error: failed to validate a cg variable. A.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( (variable->mlb_return_value >= 0 && variable->mlb_get_return_value >= 0) ) {
        
        printf("codegen error: failed to validate a cg variable. B.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->ptr == NULL && (variable->mlb_return_value < 0 && variable->mlb_get_return_value < 0) &&
        (variable->type == ptr || variable->type == array || (variable->type == class && variable->class_values == NULL) 
        || variable->class_element != NULL || variable->index >= 0)) {
        
        printf("codegen error: failed to validate a cg variable. C.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->ptr != NULL && variable->type != ptr && variable->type != array && variable->type != class
        && variable->class_element == NULL && variable->index == -1) {
        
        printf("codegen error: failed to validate a cg variable. D.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->values != NULL && variable->type != array && variable->type != collection ) {
        
        printf("codegen error: failed to validate a cg variable. E.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->class_values != NULL && variable->type != class ) {
        
        printf("codegen error: failed to validate a cg variable. F.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->ptr != NULL  ) mlb_validate_variable(variable->ptr) ;
    
    if ( variable->values != NULL ) {
        
        RKList_node node = RKList_GetFirstNode(variable->values) ;
        
        while ( node != NULL ) {
            
         mlb_validate_variable(RKList_GetData(node)) ;
            
         node = RKList_GetNextNode(node) ;
            
        }
    }
    
    if ( variable->class_values != NULL ) {
        
        RKList_node node = RKList_GetFirstNode(RKStore_GetList(variable->class_values)) ;
        
        while ( node != NULL ) {
            
            mlb_validate_variable(RKList_GetData(node)) ;
            
            node = RKList_GetNextNode(node) ;
            
        }
    }
}

static cg_variable mlb_get_var( cg_variable variable ) {
    
    if ( variable->class_element != NULL ) {
        
        return mlb_get_var(((cg_variable)RKStore_GetItem(variable->ptr->ptr->class_values, RKString_GetString(variable->class_element)))) ;
    }
    
    if ( variable->index >= 0 ) {
        
        return mlb_get_var(variable->ptr) ;
    }
    
    return variable ;
}

static cg_variable mlb_get_array( cg_variable variable ) {
    
    if ( variable->type == array ) {
        
        return variable->ptr ;
    }
    
    return variable ;
}

void mlb_validate_statement( mlb_statement statement ) {
    
    if ( statement->A != NULL ) mlb_validate_variable(statement->A) ;
    
    if ( statement->B != NULL ) mlb_validate_variable(statement->B) ;
    
    if ( statement->C != NULL ) mlb_validate_variable(statement->C) ;
    
    switch (statement->op) {
       
        case cg_array_copy:
            
            if (statement->A == NULL || statement->B == NULL || mlb_get_var(statement->A)->type != mlb_get_var(statement->B)->type
                || mlb_get_var(statement->A)->type != array || mlb_get_var(statement->A)->ptr == NULL || mlb_get_var(statement->B)->ptr == NULL
                || mlb_get_var(statement->A)->num_of_elements <= 0
                || mlb_get_var(statement->A)->num_of_elements != mlb_get_var(statement->B)->num_of_elements
                || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. A.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
            
       case cg_cast:
            
            if (statement->A == NULL || statement->B == NULL || statement->C == NULL) {
                
                printf("codegen error: failed to validate a mlb statement. B.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
       break;
            
       case cg_sizeof:
            
            if (statement->A == NULL || statement->B == NULL || mlb_get_var(statement->A)->type != ptrsize || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. C.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
        case cg_deref:
            
            if (statement->A == NULL || statement->B == NULL || mlb_get_var(statement->B)->type != ptr || mlb_get_var(statement->B)->ptr == NULL
                || mlb_get_var(statement->A)->type != ((cg_variable)mlb_get_var(statement->B)->ptr)->type || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. D.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
        case cg_addrof:
            
            if (statement->A == NULL || statement->B == NULL || mlb_get_var(statement->A)->ptr == NULL || mlb_get_var(statement->A)->type != ptr
                || ((cg_variable)mlb_get_var(statement->A)->ptr)->type != mlb_get_var(statement->B)->type || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. E.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
            
            
        case mlb_set:
        case cg_not:
        case cg_logic_not:
            
            if (statement->A == NULL || statement->B == NULL
                || mlb_get_array(mlb_get_var(statement->A))->type != mlb_get_array(mlb_get_var(statement->B))->type
                || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. F.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
        
        case mlb_external_return:
            
            if (statement->A == NULL || statement->B != NULL || statement->C != NULL || !statement->routine->is_external) {
                
                printf("codegen error: failed to validate a mlb statement. G.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
            
        case cg_case:
        case cg_goto:
        case cg_section:
            
            if (statement->A == NULL || !statement->A->is_literal || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. H.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
           break;
            
            
        case cg_call:
            
            if (statement->A == NULL || !statement->A->is_literal || statement->A->type != collection
                || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. I.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
            
        case cg_if:
        case cg_else_if:
        case cg_switch:
        
            if (statement->A == NULL || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. J.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
           break;
            
        case cg_else:
        case cg_endif:
        case cg_endswitch:
        case cg_endcase:
        case cg_default:
        case cg_return:
            
            if (statement->A != NULL || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement. K.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
           break;
            
            
        default:
            
            if (statement->A == NULL || statement->B == NULL || statement->C == NULL
                || mlb_get_var(statement->A)->type != mlb_get_var(statement->B)->type
                || mlb_get_var(statement->A)->type != mlb_get_var(statement->C)->type) {
                
                printf("codegen error: failed to validate a mlb statement. L.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
           break;
    }
}

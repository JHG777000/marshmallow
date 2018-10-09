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

static RKString get_name_for_tempvar( int* tempvars ) {
    
    char string[100] ;
    
    marshmallow_uitoa(*tempvars, string) ;
    
    RKString name = rkstr(string) ;
    
    RKString retname = RKString_AppendString(rkstr("_V"), name) ;
    
    RKString_DestroyString(name) ;
    
    (*tempvars)++ ;
    
    return retname ;
}

static RKString get_name_for_retvar( int* retvars ) {
    
    char string[100] ;
    
    marshmallow_uitoa(*retvars, string) ;
    
    RKString name = rkstr(string) ;
    
    RKString retname = RKString_AppendString(rkstr("_R"), name) ;
    
    RKString_DestroyString(name) ;
    
    (*retvars)++ ;
    
    return retname ;
}

static RKString get_name_for_getretvar( int* getretvars ) {
    
    char string[100] ;
    
    marshmallow_uitoa(*getretvars, string) ;
    
    RKString name = rkstr(string) ;
    
    RKString retname = RKString_AppendString(rkstr("_GR"), name) ;
    
    RKString_DestroyString(name) ;
    
    (*getretvars)++ ;
    
    return retname ;
}

static int is_var_array( cg_variable var ) {
    
loop:
    
    if ( var->type == array ) return 1 ;
    
    if ( var->class_element != NULL || var->index >= 0 ) {
        
        var = var->ptr ;
        
        goto loop ;
    }
    
    return 0 ;
}

static void mob_process_statement( cg_routine routine, cg_statement statement, int* tempvars, int* getretvar) {
    
    cg_variable variable = NULL ;
    
    cg_variable type = NULL ;
    
    cg_variable A = NULL ;
    
    cg_variable B = NULL ;
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    int retvar = 0 ;
    
    switch (statement->op) {
            
        case cg_else:
        case cg_endif:
        case cg_endwhile:
        case cg_break:
        case cg_continue:
        case cg_default:
        case cg_endcase:
        case cg_endswitch:
            
            mlb_add_statement(statement->op, routine, NULL, NULL, NULL) ;
            
            break;
            
        case mob_push:
            
            RKStack_Push(routine->mob_stack, statement->var) ;
            
            break;
            
        case mob_drop:
            
            RKStack_Pop(routine->mob_stack) ;
            
            break;
            
        case cg_call:
        
           mlb_add_statement(statement->op, routine, statement->var, NULL, NULL) ;
        
           RKStack_Push(routine->mob_call_stack, RKList_GetData(RKList_GetFirstNode(statement->var->values))) ;
            
           *getretvar = 0 ;
        
           break;
            
        case cg_return:
            
            if ( !routine->is_external ) {
                
                list = RKStack_GetList(routine->mob_stack) ;
                
                if ( list != NULL ) {
                    
                    retvar = 0 ;
                    
                    node = RKList_GetFirstNode(list) ;
                    
                    while ( node != NULL ) {
                    
                        type = RKList_GetData(node) ;
                        
                        variable = cg_new_variable(get_name_for_retvar(&retvar), type->type, retvar-1, -1, type->num_of_elements, 0) ;
                        
                        variable->is_temporary = 1 ;
                        
                        cg_add_variable_to_routine(variable, routine) ;
                        
                        if (!is_var_array(type)) mlb_add_statement(mlb_set, routine, variable, RKList_GetData(node), NULL) ;
                        
                        if (is_var_array(type)) mlb_add_statement(cg_array_copy, routine, variable, RKList_GetData(node), NULL) ;
                        
                        node = RKList_GetNextNode(node) ;
                    }
                    
                    RKList_DeleteAllNodesInList(list) ;
                }
                
                mlb_add_statement(cg_return, routine, NULL, NULL, NULL) ;
                
            } else {
                
                mlb_add_statement(mlb_external_return, routine, RKStack_Pop(routine->mob_stack), NULL, NULL) ;
            }
            
             break;
        
        case cg_get_return:
        
           type = ((cg_variable)RKList_GetData(RKList_GetNode(((cg_routine)RKStack_Peek(routine->mob_call_stack))->return_types, *getretvar))) ;
        
           variable = cg_new_variable(get_name_for_getretvar(getretvar), type->type, -1, *getretvar-1, type->num_of_elements, 0) ;
        
           variable->is_temporary = 1 ;
        
           cg_add_variable_to_routine(variable, routine) ;
            
           RKStack_Push(routine->mob_stack, variable) ;
        
           break;
        
        case cg_if:
        case cg_else_if:
        case cg_while:
        case cg_switch:
        case cg_case:
        case cg_goto:
        case cg_section:
            
            mlb_add_statement(statement->op, routine, RKStack_Pop(routine->mob_stack), NULL, NULL) ;
            
            break;
        
        case cg_assignment:
            
            B = RKStack_Pop(routine->mob_stack) ;
            
            A = RKStack_Pop(routine->mob_stack) ;
            
            mlb_add_statement(mlb_set, routine, A, B, NULL) ;
            
            RKStack_Push(routine->mob_stack, A) ;
            
            break;
            
        case cg_array_copy:
        case cg_sizeof:
        case cg_deref:
        case cg_addrof:
        case cg_not:
        case cg_logic_not:
            
            variable = cg_new_variable(get_name_for_tempvar(tempvars), ((cg_variable)RKStack_Peek(routine->mob_stack))->type, -1, -1, 0, 0) ;
            
            variable->is_temporary = 1 ;
            
            cg_add_variable_to_routine(variable, routine) ;
            
            mlb_add_statement(statement->op, routine, variable, RKStack_Pop(routine->mob_stack),NULL) ;
            
            cg_add_variable_to_routine(variable, routine) ;
            
            RKStack_Push(routine->mob_stack, variable) ;
            
            break;
            
        case cg_add:
        case cg_sub:
        case cg_mult:
        case cg_div:
        case cg_rem:
        case cg_rshift:
        case cg_lshift:
        case cg_and:
        case cg_or:
        case cg_xor:
        case cg_cast:
        case cg_equals:
        case cg_not_equals:
        case cg_lessthan:
        case cg_greaterthan:
        case cg_lessthan_or_equals:
        case cg_greaterthan_or_equals:
            
            variable = cg_new_variable(get_name_for_tempvar(tempvars), ((cg_variable)RKStack_Peek(routine->mob_stack))->type, -1, -1, 0, 0) ;
            
            variable->is_temporary = 1 ;
            
            cg_add_variable_to_routine(variable, routine) ;
            
            B = RKStack_Pop(routine->mob_stack) ;
            
            A = RKStack_Pop(routine->mob_stack) ;
            
            mlb_add_statement(statement->op, routine, variable, A, B) ;
            
            cg_add_variable_to_routine(variable, routine) ;
            
            RKStack_Push(routine->mob_stack, variable) ;
            
            break;
            
        default:
            break;
    }
}

void mob_generate_mlb( cg_routine routine ) {
    
    RKList list = routine->mob_code ;
    
    RKList_node node = RKList_GetFirstNode(list) ;
    
    int tempvars = 0 ;
    
    int getretvar = 0 ;
    
    if ( list != NULL ) {
        
        while ( node != NULL ) {
            
            mob_process_statement(routine,RKList_GetData(node),&tempvars,&getretvar) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
}
    
cg_statement mob_add_statement( cg_op_type op, cg_routine routine, cg_variable var ) {
    
    cg_statement statement = RKMem_NewMemOfType(struct cg_statement_s) ;
    
    statement->op = op ;
    
    statement->entity_type = cg_entity_statement ;
    
    statement->var = ( var != NULL ) ? (var->is_literal) ? var : cg_get_variable(routine, var->name) : NULL ;
    
    if ( routine->mib_code == NULL ) routine->mob_code = RKList_NewList() ;
    
    RKList_AddToList(routine->mob_code, statement) ;
    
    statement->routine = routine ;
    
    if ( op == mib_group ) {
        
        printf("codegen error: failed to validate a mob statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( op == mib_endgroup ) {
        
        printf("codegen error: failed to validate a mob statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( op == mib_var ) {
        
        printf("codegen error: failed to validate a mob statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( op == mib_const ) {
        
        printf("codegen error: failed to validate a mob statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    return statement ;
}

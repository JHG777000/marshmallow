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

static RKList_node mib_process_statement( cg_routine routine, RKList_node node, int* group_balance ) {
    
    cg_statement statement = NULL ;
    
    cg_op_type operator_for_group = cg_noop ;
    
    while ( node != NULL ) {
        
        statement = RKList_GetData(node) ;
        
        switch (statement->op) {
                
            case mib_group:
                
                (*group_balance)++ ;
                
                node = mib_process_statement(routine, RKList_GetNextNode(node),group_balance) ;
                
                break;
                
            case mib_endgroup:
                
                (*group_balance)-- ;
                
                mob_add_statement(operator_for_group, routine, NULL) ;
                
                return node ;
                
                break;
                
            case mib_exitgroup:
                
                (*group_balance)-- ;
                
                mob_add_statement(operator_for_group, routine, NULL) ;
                
                mob_add_statement(mob_drop, routine, NULL) ;
                
                return node ;
                
                break;
                
            case mib_var:
            case mib_const:
                
                mob_add_statement(mob_push, routine, statement->var) ;
                
                break;
            
            case cg_call:
            case cg_case:
            case cg_goto:
            case cg_section:
                
                 mob_add_statement(statement->op, routine, statement->var) ;
            
                break;
                
            case cg_noop:
                    
                    printf("codegen error: failed to validate a mib statement. There should be no noop.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                
                break;
                
            case cg_else:
            case cg_endif:
            case cg_default:
            case cg_endcase:
            case cg_endswitch:
            case cg_get_return:
                
                mob_add_statement(statement->op, routine, NULL) ;
                
                break;
                
            default:
                
                operator_for_group = statement->op ;
                
                break;
        }
        
        if ( node != NULL )  node = RKList_GetNextNode(node) ;
        
    }
    
    return NULL ;
}

void mib_generate_mob( cg_routine routine ) {
    
    int group_balance = 0 ;
    
    RKList list = routine->mib_code ;
    
    if ( list != NULL ) {
        
        mib_process_statement(routine,RKList_GetFirstNode(list),&group_balance) ;
        
    }
    
    if ( group_balance != 0  ) {
        
        printf("codegen error: failed to validate a mib statement. Groups are not balanced.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
}

cg_statement mib_add_statement( cg_op_type op, cg_routine routine, cg_variable var ) {
    
    cg_statement statement = RKMem_NewMemOfType(struct cg_statement_s) ;
    
    statement->op = op ;
    
    statement->entity_type = cg_entity_statement ;
    
    statement->var = ( var != NULL ) ? (var->is_literal) ? var : cg_get_variable(routine, var->name) : NULL ;
    
    if ( routine->mib_code == NULL ) routine->mib_code = RKList_NewList() ;
    
    RKList_AddToList(routine->mib_code, statement) ;
    
    statement->routine = routine ;
    
    if ( op == mib_var && var->is_literal ) {
        
        printf("codegen error: failed to validate a mib statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( op == mib_const && !var->is_literal ) {
        
        printf("codegen error: failed to validate a mib statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( op == mob_push ) {
        
        printf("codegen error: failed to validate a mib statement.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    return statement ;
}

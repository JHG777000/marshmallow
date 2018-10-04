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

static void mob_process_statement( cg_routine routine, RKList_node node ) {
    
    
}

void mob_generate_mlb( cg_routine routine ) {
    
    RKList list = routine->mob_code ;
    
    if ( list != NULL ) {
        
        mob_process_statement(routine,RKList_GetFirstNode(list)) ;
        
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

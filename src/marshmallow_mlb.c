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

void mlb_validate_statement( mlb_statement statement ) {
    
    switch (statement->op) {
         
        case mlb_set:
            
            if (statement->A->type != statement->B->type || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
        break;
            
        case mlb_return:
            
            if (statement->A != NULL || statement->B != NULL || statement->C != NULL) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
            
            
        default:
            
            if (statement->A->type != statement->B->type || statement->A->type != statement->C->type) {
                
                printf("codegen error: failed to validate a mlb statement.\n") ;
                
                exit(EXIT_FAILURE) ;
            }
            
            break;
    }
}

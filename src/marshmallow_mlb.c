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
#include "marshmallow_backend.h"

void mlb_add_instruction( mlb_routine routine, mlb_block_type block, mlb_root_type type, mlb_opcode op, RKInt a, RKInt b, RKInt c ) {
    
    if ( block->code == NULL ) block->code = RKList_NewList() ;
    
    if ( block->gos == NULL ) block->gos = RKList_NewList() ;
    
    mlb_instruction instruction = RKMem_NewMemOfType(struct mib_instruction_s) ;
    
    instruction->type = type ;
    
    instruction->routine = routine ;
    
    instruction->a = a ;
    
    instruction->b = b ;
    
    instruction->c = c ;
    
    RKList_AddToList(block->code, instruction) ;
    
    if ( op == mlb_go || op == mlb_go_equals || op == mlb_go_not_equals ||
        op == mlb_go_lessthan || op == mlb_go_greaterthan) RKList_AddToList(block->gos, instruction) ;
}

void mlb_generate_assembly( mlb_routine routine, codegen_architecture architecture ) {
    
    RKList_node node = RKList_GetFirstNode(routine->mlb_code) ;
    
    mlb_instruction instruction = NULL ;
    
    while ( node != NULL ) {
        
        instruction = RKList_GetData(node) ;
        
        architecture->mlb_opcode_func[instruction->opcode](instruction->routine, node, architecture->arch_ptr, instruction->type, instruction->opcode,
                                                           instruction->a, instruction->b, instruction->c) ; 
        node = RKList_GetNextNode(node) ;
        
    }
}




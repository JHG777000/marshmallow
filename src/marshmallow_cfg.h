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

#ifndef marshmallow_cfg_h
#define marshmallow_cfg_h

typedef void* cfg_node ;

typedef enum { statement_block, if_block, while_block, switch_block, case_block } cfg_block_type ;

typedef struct cfg_type_s { marshmallow_entity_type entity_type ; RKString type_name ; int is_literal ;
    
int is_temporary ; int is_typedef ; int is_cast ; int is_readonly ; marshmallow_root_type root_type ;
    
void* base_type ; RKULong num_of_elements ; int pointers ; } *cfg_type ;

typedef struct cfg_statement_s { marshmallow_entity_type entity_type ; int is_expression ; marshmallow_op_type op ;
    
marshmallow_entity var_a ; marshmallow_entity var_b ; marshmallow_entity var_c ;
    
struct cfg_statement_s* parent ; marshmallow_function_body function ; } *cfg_statement ;

typedef struct cfg_block { cfg_block_type block_type ; cfg_node node ; } *cfg_block ;

typedef struct if_node { cfg_statement conditional ; cfg_block block ; } *if_node ;

#endif /* marshmallow_cfg_h */

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

typedef enum { statement_block, if_block, while_block, switch_block, case_block } cfg_block_type ;

typedef struct cfg_type_s { marshmallow_entity_type entity_type ; RKString type_name ;

int is_typedef ; int is_readonly ; int is_constexpr ; marshmallow_root_type root_type ;
    
void* base_type ; RKULong num_of_elements ; int pointers ; } *cfg_type ;

typedef struct cfg_variable_s { marshmallow_entity_type entity_type ; cfg_type type ;
    
RKString name ; void* data ; int is_persistent ; int is_declared ; int is_literal ; int is_temporary ; int is_external ; int is_global ;

marshmallow_access_control access_control ; struct cfg_variable_s* static_assignment ; } *cfg_variable ;

typedef struct cfg_function_signature_s { marshmallow_access_control access_control ; int is_method ; int is_overridable ; int is_override ;
    
int is_declared ; int is_external ; RKString func_name ; marshmallow_class class ;
    
RKStore parameters ; RKList returns ; } *cfg_function_signature ;

typedef struct cfg_function_body_s { marshmallow_entity_type entity_type ; RKList statements ; RKStore variables ;
    
cfg_function_signature signature ; marshmallow_module module ; } *cfg_function_body ;

typedef struct cfg_statement_s { marshmallow_entity_type entity_type ;
    
int is_expression ; marshmallow_op_type op ; cfg_variable var_a ; cfg_variable var_b ;
    
cfg_variable retvar ; struct cfg_statement_s* parent ; cfg_function_body function ; } *cfg_statement ;

typedef struct cfg_block_s { cfg_block_type block_type ; struct cfg_block_s* block ; } *cfg_block ;

typedef struct cfg_statements_block_s { cfg_block_type block_type ; RKList statements ; cfg_block next_block ;  } *cfg_statements_block ;

typedef struct cfg_if_block { cfg_block_type block_type ; cfg_block conditional ;
    
cfg_block next_block ; cfg_block then_block ; cfg_block else_block ;  } *cfg_if_block ;

typedef struct cfg_while_block { cfg_block_type block_type ; cfg_block conditional ;
    
cfg_block next_block ; cfg_block then_block ;  } *cfg_while_block ;

typedef struct cfg_case_block { cfg_block_type block_type ; cfg_block conditional ;
    
cfg_block next_block ; cfg_block then_block ;  } *cfg_case_block ;

typedef struct cfg_switch_block { cfg_block_type block_type ; cfg_block conditional ;
    
cfg_block next_block ; cfg_block then_block ; RKStore switch_store ; } *cfg_switch_block ;

#endif /* marshmallow_cfg_h */

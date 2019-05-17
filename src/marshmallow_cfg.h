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

#ifndef marshmallow_cfg_h
#define marshmallow_cfg_h

typedef enum { entry_block, terminate_block, statement_block, if_block, while_block, switch_block, case_block } cfg_block_type ;

typedef struct cfg_class_s *cfg_class ;

typedef struct cfg_enum_s *cfg_enum ;

typedef struct cfg_type_s *cfg_type ;

typedef struct cfg_variable_s *cfg_variable ;

typedef struct cfg_function_signature_s *cfg_function_signature ;

typedef struct cfg_function_body_s *cfg_function_body ;

typedef struct cfg_module_s *cfg_module ;

typedef struct cfg_block_s { marshmallow_entity_type entity_type ; cfg_block_type block_type ; cfg_variable retvar ;

marshmallow_op_type op ; struct cfg_block_s* input_block ; RKStore output_blocks ; } *cfg_block ;


struct cfg_class_s { marshmallow_entity_type entity_type ; RKString class_name ;

marshmallow_access_control access_control ; RKStore variables ;

cfg_function_body init_function ; } ;


struct cfg_enum_s { RKList enum_names ; RKStore enums ; } ;


struct cfg_type_s { marshmallow_entity_type entity_type ; RKString type_name ;

int is_typedef ; int is_readonly ; int is_constexpr ; marshmallow_root_type root_type ;

void* base_type ; RKULong num_of_elements ; int pointers ; } ;


struct cfg_variable_s { marshmallow_entity_type entity_type ; RKString type_name ; cfg_type type_ptr ;

RKString name ; void* data ; int is_instance ; int is_persistent ; int is_declared ; int is_literal ;

int is_temporary ; int is_external ; int is_global ; marshmallow_access_control access_control ; cfg_variable static_assignment ; } ;


struct cfg_function_signature_s { marshmallow_access_control access_control ; int is_method ; int is_overridable ; int is_override ;

int is_declared ; int is_external ; RKString func_name ; marshmallow_class class ;

RKStore parameters ; RKList returns ; } ;


struct cfg_function_body_s { marshmallow_entity_type entity_type ; cfg_block entry_block ; RKStore variables ;

cfg_function_signature signature ; cfg_module module ; } ;


struct cfg_module_s { marshmallow_entity_type entity_type ; RKStore variables ; RKStore declarations ;

RKStore types ; RKStore unprocessed_types ; RKStore enums ; RKStore modules ;

RKStore functions_and_methods ; RKString name ; marshmallow_context context ; } ;


cfg_module cfg_new_module( RKString name ) ;

void cfg_destroy_module( cfg_module module ) ;

void cfg_add_module_to_context( cfg_module module, marshmallow_context context ) ;

cfg_function_signature cfg_new_function_signature( RKString name, int is_method ) ;

void cfg_destroy_function_signature( cfg_function_signature signature ) ;

void cfg_add_parameter_to_function( cfg_function_signature signature, cfg_variable parameter, int is_first_parameter ) ;

void cfg_add_return_to_function_return_list( cfg_function_signature signature, cfg_variable a_return ) ;

cfg_function_body cfg_new_function_body( cfg_function_signature signature ) ;

void cfg_destroy_function_body( cfg_function_body function ) ;

void cfg_add_variable_to_function( cfg_variable variable, cfg_function_body function ) ;

void cfg_add_variable_instance_to_function( cfg_variable variable, cfg_function_body function )  ;

cfg_block cfg_new_block( cfg_block_type block_type ) ;

void cfg_destroy_block( cfg_block block ) ;

void cfg_set_block_statement( cfg_block block, marshmallow_op_type op_type ) ;

void cfg_add_block_to_block_output( cfg_block block_to_add, cfg_block block, const char* output_name ) ;

cfg_block cfg_get_block_from_block_output( cfg_block block, const char* output_name ) ;

cfg_variable cfg_new_variable( void ) ;

void cfg_destroy_variable( cfg_variable variable ) ;

cfg_type cfg_new_type( RKString type_name ) ;

void cfg_destroy_type( cfg_type type ) ;

cfg_class cfg_new_class( RKString class_name ) ;

void cfg_destroy_class( cfg_class class ) ;

RKString cfg_get_name_from_entity( marshmallow_entity entity ) ;

void cfg_add_variable_to_module( cfg_variable variable, cfg_module module ) ;

void cfg_add_function_to_module( cfg_function_body function, cfg_module module ) ;

void cfg_add_declaration_to_module( marshmallow_entity entity, cfg_module module ) ;

void cfg_add_type_to_module( cfg_type type, cfg_module module ) ;

cfg_type cfg_get_type_from_module( const char* type_name, cfg_module module ) ;

void cfg_add_enums_to_module( cfg_type type, cfg_module module ) ;

#endif /* marshmallow_cfg_h */

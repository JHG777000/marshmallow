/*
 Copyright (c) 2019-2020 Jacob Gordon. All rights reserved.

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

#ifndef marshmallow_mab_h
#define marshmallow_mab_h

//packages, modules, blocks, definitions, values

typedef enum { mab_noop, mab_define, mab_assignment, mab_static_assignment, mab_add, mab_sub, mab_mult, mab_div, mab_rem, mab_rshift,

mab_lshift, mab_and, mab_or, mab_xor, mab_not, mab_logic_and, mab_logic_or, mab_logic_not, mab_deref, mab_addrof,

mab_sizeof, mab_itemsof, mab_cast, mab_reinterpret, mab_convert, mab_force_type, mab_if, mab_then, mab_else, mab_else_if,

mab_while, mab_switch, mab_case, mab_default, mab_goto, mab_section, mab_equals, mab_not_equals,

mab_greaterthan, mab_lessthan, mab_greaterthan_or_equals, mab_lessthan_or_equals,

mab_inc, mab_dec, mab_call, mab_return } mab_op ;


typedef enum { mab_notype, mab_type_i8, mab_type_u8, mab_type_i16, mab_type_u16, mab_type_i32, mab_type_u32, mab_type_i64,

mab_type_u64, mab_type_f32, mab_type_f64, mab_type_ptrsize, mab_type_s8, mab_type_s16, mab_type_s32,

mab_non_root, mab_block_address } mab_root_types ;


typedef enum { mab_flag_no_value, mab_flag_literal, mab_flag_string, mab_flag_identifier, mab_flag_result, mab_flag_exit,

mab_flag_zero, mab_flag_one, mab_flag_two, mab_flag_type }  mab_value_flags ;


typedef struct { union { void* val_ptr ; RKSByte val_i8 ; RKByte val_u8 ; RKShort val_i16 ;

RKUShort val_u16 ; RKInt val_i32 ; RKUInt val_u32 ; RKLong val_i64 ;

RKULong val_u64 ;  RKFloat val_f32 ; RKDouble val_f64 ; RKInt val_block_address[2] ; } ;

mab_value_flags flags ; mab_root_types root_type ; } mab_value ;


typedef struct { mab_op op ; mab_value value ; } mab_statement ;


typedef struct mab_package_s* mab_package ;

typedef struct mab_module_s* mab_module ;

typedef struct mab_block_s* mab_block ;

typedef struct mab_definition_s* mab_definition ;

typedef enum {mab_entity_package,mab_entity_module,mab_entity_block,mab_entity_definition} mab_entity_type ;

typedef enum {mab_declare,mab_external,mab_protocol,mab_type,

mab_code,mab_override_code,mab_overridable_code,mab_omega_code,

mab_scope,mab_module_scope,mab_local_variable,mab_global_variable} mab_definition_type ;


struct mab_package_s { mab_entity_type entity_type ; RKString name ; RKStore properties ; RKStore attributes ;

RKList source_files ; RKList used_packages ; RKStore required_packages ; } ;


struct mab_module_s { mab_entity_type entity_type ; RKString name ; RKStore properties ; RKStore attributes ;

mab_package package ; RKList used_modules ; RKStore required_modules ; RKList used_packages ;

RKStore required_packages ; mab_block root_block ; } ;


struct mab_block_s { mab_entity_type entity_type ; RKString name ; mab_definition definition ;

mab_block* blocks ; mab_statement* code ; } ;


struct mab_definition_s { mab_entity_type entity_type ; RKString name ; RKStore properties ; RKStore attributes ;

mab_definition_type definition_type ; RKStore definitions ; RKString type_string ; mab_value val ; } ;

#endif /* marshmallow_mab_h */

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

//mab_package, mab_module, mab_function, mab_method, mab_procedure, mab_extension

//containers, blocks, values

typedef enum { mab_noop, mab_define, mab_assignment, mab_static_assignment, mab_add, mab_sub, mab_mult, mab_div, mab_rem, mab_rshift,

mab_lshift, mab_and, mab_or, mab_xor, mab_not, mab_logic_and, mab_logic_or, mab_logic_not, mab_deref, mab_addrof,

mab_sizeof, mab_itemsof, mab_cast, mab_reinterpret, mab_convert, mab_force_type, mab_if, mab_then, mab_else, mab_else_if,

mab_while, mab_switch, mab_case, mab_default, mab_goto, mab_section, mab_equals, mab_not_equals,

mab_greaterthan, mab_lessthan, mab_greaterthan_or_equals, mab_lessthan_or_equals,

mab_inc, mab_dec, mab_call, mab_return } mab_op ;


typedef enum { mab_notype, mab_type_i8, mab_type_u8, mab_type_i16, mab_type_u16,

mab_type_i32, mab_type_u32, mab_type_i64, mab_type_u64, mab_type_f32,

mab_type_f64, mab_type_ptrsize, mab_type_s8,

mab_type_s16, mab_type_s32, mab_type_class,

mab_type_enum, mab_type_lambda } mab_root_types ;


typedef struct { enum {base_readability,readonly,writelimited,private_write,protected_write,

system_readwrite,thread_readwrite} readability ; RKULong affect_index ; } mab_readability ;


typedef struct mab_flags { enum {mab_package,mab_module,mab_class,mab_enum,mab_code} definition_type ;

enum {mab_public,mab_private,mab_protected,mab_inherit} access_control ; union { enum {final,abstract,protocol} class_flags ;

struct { RKByte is_export ; RKByte is_in_union ; mab_readability readability ; } variable_flags ;

struct { RKStore parameters ; RKList returns ; } code_flags ; struct { RKByte is_preserved ; RKByte is_persistent ;

enum {base_inoutpass,in,out,inout,pass} inoutpass ; } local_variable_flags ; } ; } mab_flags ;


typedef struct { enum { mab_flag_literal, mab_flag_identifier, mab_flag_result, mab_flag_exit,

mab_flag_zero, mab_flag_one, local_variable } value_flag ; mab_root_types root_type ; } mab_value_flags ;


typedef struct { union { void* val_ptr ; struct { RKList statements ; } code ;

struct { mab_root_types root_type ; RKULong num_of_elements ; void* base_type ; } type ; RKSByte val_i8 ; RKByte val_u8 ; RKShort val_i16 ;

RKUShort val_u16 ; RKInt val_i32 ; RKUInt val_u32 ; RKLong val_i64 ;

RKULong val_u64 ;  RKFloat val_f32 ; RKDouble val_f64 ; } ;

mab_value_flags flags ; } mab_value ;


typedef struct mab_container_s* mab_container;

typedef struct mab_active_block_s* mab_active_block;

typedef struct mab_passive_block_s* mab_passive_block;

typedef struct mab_statement_s { mab_op op ; mab_value value ; }* mab_statement ;


struct mab_container_s { mab_flags flags ; RKString name ; RKStore properties ; RKStore attributes ;

mab_active_block active_block ; mab_value value ; } ;


struct mab_active_block_s { RKByte block_byte ; RKStore definitions ; RKList used_blocks ; RKStore required_blocks ;

mab_passive_block sub_block ; mab_container container ; } ;


struct mab_passive_block_s { RKByte block_byte ; RKStore definitions ; mab_active_block active_block ;

mab_passive_block super_block ; mab_passive_block sub_block ; } ;


mab_container mab_new_module( RKString name ) ;


#endif /* marshmallow_mab_h */

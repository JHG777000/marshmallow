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


typedef enum { mab_flag_none, mab_flag_type_i8, mab_flag_type_u8, mab_flag_type_i16, mab_flag_type_u16,

mab_flag_type_i32, mab_flag_type_u32, mab_flag_type_i64, mab_flag_type_u64, mab_flag_type_f32,

mab_flag_type_f64, mab_flag_type_ptrsize, mab_flag_literal, mab_flag_identifier,

mab_flag_result, mab_flag_exit } mab_flags ;


typedef struct { union { void* val_ptr ; struct { RKStore parameters ; RKList returns ; RKList statements ; } code ;

struct { RKULong num_of_elements ; void* base_type ; } type ; RKSByte val_i8 ; RKByte val_u8 ; RKShort val_i16 ;

RKUShort val_u16 ; RKInt val_i32 ; RKUInt val_u32 ; RKLong val_i64 ;

RKULong val_u64 ;  RKFloat val_f32 ; RKDouble val_f64 ; } ;

RKUInt flags ; } mab_value ;


typedef struct mab_container_s* mab_container;

typedef struct mab_active_block_s* mab_active_block;

typedef struct mab_passive_block_s* mab_passive_block;

typedef struct mab_statement_s { RKUInt op ; mab_value value ; }* mab_statement ;


struct mab_container_s { RKUInt flags ; RKString name ; RKStore properties ; RKStore attributes ;

mab_active_block active_block ; mab_value value ; } ;


struct mab_active_block_s { RKByte block_byte ; RKStore definitions ; RKList used_blocks ; RKStore required_blocks ;

mab_passive_block sub_block ; mab_container container ; } ;


struct mab_passive_block_s { RKByte block_byte ; RKStore definitions ; mab_active_block active_block ;

mab_passive_block super_block ; mab_passive_block sub_block ; } ;


#endif /* marshmallow_mab_h */

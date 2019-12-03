/*
 Copyright (c) 2019 Jacob Gordon. All rights reserved.

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

typedef enum { mab_noop,

mab_use, mab_require, mab_access_control, mab_define, mab_declare, mab_external, mab_scope, mab_type, mab_contains,

mab_class, mab_enum, mab_file, mab_typedef, mab_parameter, mab_literal, mab_identifier,

mab_assignment, mab_array_assignment, mab_static_assignment, mab_add, mab_sub, mab_mult, mab_div, mab_rem,

mab_rshift, mab_lshift, mab_and, mab_or, mab_xor, mab_not, mab_logic_and, mab_logic_or,

mab_logic_not, mab_deref, mab_addrof, mab_sizeof, mab_itemsof, mab_cast, mab_force_type, mab_if, mab_else, mab_else_if,

mab_while, mab_switch, mab_case, mab_default, mab_goto, mab_section, mab_equals, mab_not_equals,

mab_greaterthan, mab_lessthan, mab_greaterthan_or_equals, mab_lessthan_or_equals,

mab_inc, mab_dec, mab_call, mab_return, mab_returns } mab_op ;

typedef enum {

  mab_flag_none,

  mab_flag_type_i8,

  mab_flag_type_u8,

  mab_flag_type_i16,

  mab_flag_type_u16,

  mab_flag_type_i32,

  mab_flag_type_u32,

  mab_flag_type_i64,

  mab_flag_type_u64,

  mab_flag_type_f32,

  mab_flag_type_f64,

  mab_flag_type_ptrsize,

  mab_flag_type_pointer,

  mab_flag_type_blank,

  mab_flag_access_control_public,

  mab_flag_access_control_private,

  mab_flag_access_control_protected,

} mab_flags ;

//mab_package, mab_module, mab_function, mab_method, mab_procedure, mab_extension

typedef struct mab_statement_s { RKULong op ; RKULong data ; struct mab_statement_s* block ; } mab_statement ;

typedef struct mab_variable_s { RKUInt flags ; RKULong data ; } mab_variable ;

typedef struct mab_definition_s { RKList_node mab_statement_node ; void* scope ;

RKIndex arguments ; RKIndex returns ; } mab_definition ;


typedef enum { mab_module, mab_package, mab_function } mab_scope_type ;

typedef struct mab_module_scope_s { mab_scope_type scope_type ; RKStore definitions ;

void* super_scope ; RKStore used_namespaces ; RKStore required_namespaces ; void* package_or_files ; } *mab_module_scope ;


typedef mab_module_scope mab_package_scope ;


typedef struct mab_function_scope_s { mab_scope_type scope_type ; RKStore definitions ;

void* super_scope ; mab_module_scope module ; } *mab_function_scope ;



typedef struct mab_context_s { mab_package_scope package ; } *mab_context ;

#endif /* marshmallow_mab_h */

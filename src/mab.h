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

typedef enum { mab_noop, mab_package, mab_module, mab_function, mab_method, mab_procedure, mab_extension,

mab_use, mab_require, mab_define, mab_declare, mab_external, mab_scope, mab_scope_op, mab_type, mab_contains,

mab_class, mab_enum, mab_file, mab_typedef, mab_variable, mab_parameter, mab_literal, mab_identifier,

mab_assignment, mab_array_assignment, mab_static_assignment, mab_add, mab_sub, mab_mult, mab_div, mab_rem,

mab_rshift, mab_lshift, mab_and, mab_or, mab_xor, mab_not, mab_logic_and, mab_logic_or,

mab_logic_not, mab_deref, mab_addrof, mab_sizeof, mab_itemsof, mab_cast, mab_force_type, mab_if, mab_else, mab_else_if,

mab_while, mab_switch, mab_case, mab_default, mab_goto, mab_section, mab_equals, mab_not_equals,

mab_greaterthan, mab_lessthan, mab_greaterthan_or_equals, mab_lessthan_or_equals,

mab_inc, mab_dec, mab_call, mab_return, mab_i8, mab_i16, mab_i32, mab_i64, mab_i8,

mab_u16, mab_u32, mab_u64, mab_f32, mab_f64  } mab_op ;


typedef struct mab_list_s { mab_op op ; void* scope ; RKUInt num_of_elements ;

void** array ; RKUInt num_of_elements_list_array ; struct mab_list_s** list_array ;

RKUInt num_of_elements_string_array ; RKString* string_array ; } *mab_list ;



typedef struct mab_function_scope_s { RKStore definitions ; void* super_scope ; void* module ; } *mab_function_scope ;


typedef struct mab_module_scope_s { RKStore definitions ; void* super_scope ; RKStore used_namespaces ;

RKStore required_namespaces ; void* package ; } *mab_module_scope ;


typedef struct mab_package_scope_s { RKStore definitions ; void* super_scope ; RKStore used_namespaces ;

RKStore required_namespaces ; RKStore files ; } *mab_package_scope ;


mab_list mab_new_list( mab_op op ) ;

void mab_destroy_list( mab_list list ) ;

void mab_add_to_list( mab_list list, void* item, int item_is_list ) ;

#endif /* marshmallow_mab_h */

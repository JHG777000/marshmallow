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

//packages, modules, nodes, definitions, values

typedef struct mab_package_s* mab_package ;

typedef struct mab_module_s* mab_module ;

typedef struct mab_node_s* mab_node ;

typedef struct mab_type_s* mab_type ;

typedef struct mab_definition_s* mab_definition ;

typedef enum { mab_noop, mab_define, mab_assignment, mab_static_assignment, mab_add, mab_sub, mab_mult, mab_div, mab_rem, mab_rshift,

mab_lshift, mab_and, mab_or, mab_xor, mab_not, mab_logic_and, mab_logic_or, mab_logic_not, mab_deref, mab_addrof,

mab_sizeof, mab_itemsof, mab_cast, mab_reinterpret, mab_convert, mab_force_type, mab_if, mab_then, mab_else, mab_else_if,

mab_while, mab_switch, mab_case, mab_default, mab_goto, mab_section, mab_equals, mab_not_equals,

mab_greaterthan, mab_lessthan, mab_greaterthan_or_equals, mab_lessthan_or_equals,

mab_inc, mab_dec, mab_call, mab_return } mab_op ;


typedef enum { mab_type_notype, mab_type_i8, mab_type_u8, mab_type_i16, mab_type_u16, mab_type_i32, mab_type_u32, mab_type_i64,

mab_type_u64, mab_type_f32, mab_type_f64, mab_type_ptrsize, mab_type_s8, mab_type_s16, mab_type_s32,

mab_type_non_root } mab_root_types ;


typedef enum { mab_non_root_type_notype, mab_non_root_type_typedef, mab_non_root_type_class, mab_non_root_type_enum, mab_non_root_type_enum_element,

mab_non_root_type_array, mab_non_root_type_vector, mab_non_root_type_lambda, mab_non_root_type_static } mab_non_root_types ;


typedef enum { mab_static_type_notype, mab_static_type_datum, mab_static_type_field,

mab_static_type_anyvar, mab_static_type_vardef, mab_static_type_subclass,

mab_static_type_polymorph, mab_static_type_arguments,

mab_static_type_identifier } mab_static_types ;


typedef struct { enum {base_readability, readonly, writelimited, private_write, protected_write,

system_readwrite, thread_readwrite} readability ; RKULong affect_index ; } mab_readability ;

typedef enum { mab_public, mab_private, mab_protected, mab_inherit } mab_access_control ;

typedef enum { mab_function, mab_method, mab_procedure, mab_extension, mab_operator } mab_code_type ;

 struct mab_type_s {
  mab_root_types root_type ;
  mab_non_root_types non_root_type ;
  mab_static_types static_type ;
  mab_readability readability ;
  mab_access_control access_control ;
  RKULong pointers ;
  mab_type base_type ;
  //array
  RKByte is_array_safe ;
  RKULong num_of_elements ;
  //code
  mab_code_type code_type ;
  mab_definition* parameters ;
  RKULong num_of_parameters ;
  mab_type* returns ;
  RKULong num_of_returns ;
  //variable
  RKByte is_local ;
  RKByte is_in_class ;
  RKByte is_in_union ;
  RKByte is_preserved ;
  RKByte is_persistent ;
  enum {
    none,
    in,
    out,
    inout,
    pass
  } inoutpass ;
  //class
  enum {
    mab_basic_class,
    mab_final,
    mab_abstract,
    mab_class_protocol
  } class_type ;
  RKULong num_of_soa_elements ;
  RKByte is_managed ;
  mab_definition manager ;
  mab_definition init_code ;
  //enum
  RKLong base_count ;
} ;

typedef enum { mab_entity_package, mab_entity_module, mab_entity_node, mab_entity_definition, mab_entity_value } mab_entity_type ;

typedef struct { mab_entity_type entity_type ; union { void* val_ptr ; RKSByte val_i8 ; RKByte val_u8 ; RKShort val_i16 ;

RKUShort val_u16 ; RKInt val_i32 ; RKUInt val_u32 ; RKLong val_i64 ;

RKULong val_u64 ;  RKFloat val_f32 ; RKDouble val_f64 ; } ;

mab_root_types root_type ; } mab_value ;


typedef enum { mab_define_declare, mab_define_external, mab_define_protocol, mab_define_type,

mab_define_code, mab_define_override_code, mab_define_overridable_code, mab_define_omega_code,

mab_define_scope, mab_define_module_scope, mab_define_local_variable, mab_define_global_variable } mab_definition_type ;


struct mab_package_s { mab_entity_type entity_type ; RKString name ; RKStore properties ; RKStore attributes ;

RKList source_files ; RKList used_packages ; RKStore required_packages ; } ;


struct mab_module_s { mab_entity_type entity_type ; RKString name ; RKStore properties ; RKStore attributes ;

mab_package package ; RKList used_modules ; RKStore required_modules ; RKList used_packages ;

RKStore required_packages ; mab_node root_node ; } ;


struct mab_node_s { mab_entity_type entity_type ; mab_definition definition ; mab_node supernode ; mab_node nodes[2] ; } ;


struct mab_definition_s { mab_entity_type entity_type ; RKString name ; RKStore properties ; RKStore attributes ;

mab_definition_type definition_type ; RKStore definitions ; mab_type type ; } ;

#endif /* marshmallow_mab_h */

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

//packages, modules, instructions, definitions, values

typedef struct mab_package_s* mab_package ;

typedef struct mab_module_s* mab_module ;

typedef struct mab_instruction_s* mab_instruction ;

typedef struct mab_collection_s* mab_collection ;

typedef struct mab_type_s* mab_type ;

typedef struct mab_definition_s* mab_definition ;

typedef enum { mab_node_no_op, mab_op_module, mab_op_use_module, mab_op_require_module,

mab_op_use_package, mab_op_require_package, mab_op_variable, mab_op_local, mab_op_identifier, mab_op_literal,

mab_op_define, mab_op_generate, mab_op_assignment, mab_op_static_assignment, mab_op_add,

mab_op_sub, mab_op_mult, mab_op_div, mab_op_rem, mab_op_rshift, mab_op_lshift,

mab_op_and, mab_op_or, mab_op_xor, mab_op_not, mab_op_logic_and, mab_op_logic_or,

mab_op_logic_not, mab_op_deref, mab_op_addrof, mab_op_sizeof,

mab_op_itemsof, mab_op_cast, mab_op_reinterpret, mab_op_convert, mab_op_force_type,

mab_op_go, mab_op_to, mab_op_iff, mab_op_loop, mab_op_break_on, mab_op_next, mab_op_section,

mab_op_equals, mab_op_not_equals, mab_op_greaterthan, mab_op_lessthan,

mab_op_greaterthan_or_equals, mab_op_lessthan_or_equals, mab_op_inc, mab_op_dec, mab_op_call,

mab_op_return, mab_op_returns, mab_op_parameter, mab_op_one_word_operator } mab_op_type ;


typedef enum { mab_type_notype, mab_type_i8, mab_type_u8, mab_type_i16, mab_type_u16, mab_type_i32, mab_type_u32, mab_type_i64,

mab_type_u64, mab_type_f32, mab_type_f64, mab_type_ptrsize, mab_type_s8, mab_type_s16, mab_type_s32, mab_type_non_root,

mab_type_value_datum, mab_type_value_field, mab_type_value_polymorph, mab_type_value_definition, mab_type_value_identifier,

mab_type_value_collection } mab_root_types ;


typedef enum { mab_non_root_type_notype, mab_non_root_type_typedef, mab_non_root_type_class, mab_non_root_type_enum, mab_non_root_type_enum_element,

mab_non_root_type_array, mab_non_root_type_vector, mab_non_root_type_lambda, mab_non_root_type_static } mab_non_root_types ;


typedef enum { mab_static_type_notype, mab_static_type_datum, mab_static_type_field, mab_static_type_subclass, mab_static_type_inferred,

mab_static_type_polymorph, mab_static_type_arguments, mab_static_type_identifier } mab_static_types ;


typedef struct { int is_base_readability, is_readonly, is_writelimited, is_private_write, is_protected_write,

is_system_readwrite, is_thread_readwrite ; RKULong affect_index ; } mab_readability ;


typedef enum { mab_public, mab_private, mab_protected, mab_inherit, mab_friend } mab_access_control ;


typedef enum { mab_function, mab_method, mab_procedure, mab_extension, mab_operator } mab_code_type ;


 struct mab_type_s {
  //base
  mab_root_types root_type ;
  mab_non_root_types non_root_type ;
  mab_static_types static_type ;
  mab_readability readability ;
  mab_access_control access_control ;
  RKULong pointers ;
  RKULong pointers_after_array ;
  mab_type base_type ;
  mab_definition base_definition ;
  //array
  RKByte is_array_safe ;
  RKULong num_of_elements ;
  //code
  mab_code_type code_type ;
  mab_definition* parameters ;
  RKULong num_of_parameters ;
  mab_definition* inoutpasses ;
  RKULong num_of_inoutpasses ;
  mab_type* returns ;
  RKULong num_of_returns ;
  //variable
  RKByte is_local ;
  RKByte is_in_class ;
  RKByte is_in_union ;
  RKByte is_preserved ;
  RKByte is_persistent ;
  RKByte is_freeable ;
  enum {
    none,
    in,
    out,
    inout,
    pass
  } inoutpass ;
  //class
  enum {
    mab_basic,
    mab_final,
    mab_abstract,
    mab_protocol
  } class_type ;
  RKULong num_of_soa_elements ;
  RKByte is_managed ;
  mab_definition manager ;
  mab_definition init_code ;
  //enum
  RKLong base_count ;
  //declare as
  RKString true_name ;
} ;

typedef enum { mab_entity_package, mab_entity_module, mab_entity_instruction, mab_entity_collection,

mab_entity_definition, mab_entity_value } mab_entity_type ;


typedef struct { mab_entity_type entity_type ; union { void* val_ptr ; RKSByte val_i8 ; RKByte val_u8 ; RKShort val_i16 ;  RKUShort val_u16 ;

RKInt val_i32 ; RKUInt val_u32 ; RKLong val_i64 ; RKULong val_u64 ;  RKFloat val_f32 ; RKDouble val_f64 ; } ;

RKULong index ; RKByte is_ssa_or_gr ; mab_root_types root_type ; } mab_value ;


typedef enum { mab_define_declare, mab_define_external, mab_define_protocol, mab_define_type,

mab_define_code, mab_define_override_code, mab_define_overridable_code,

mab_define_omega_code, mab_define_scope, mab_define_module,

mab_define_package, mab_define_local_variable,

mab_define_variable } mab_definition_type ;


struct mab_package_s { mab_entity_type entity_type ; RKList source_files ; RKStore modules ;

RKList used_packages ; RKStore required_packages ; } ;


struct mab_module_s { mab_entity_type entity_type ; mab_package package ; RKList used_modules ; RKStore required_modules ;

RKList used_packages ; RKStore required_packages ; mab_collection instructions ; } ;


struct mab_collection_s { mab_entity_type entity_type ; void** array_of_items ; RKULong num_of_items ; } ;


struct mab_instruction_s { mab_entity_type entity_type ; mab_op_type op ;

mab_value a ; mab_value b ; mab_value c ; } ;


struct mab_definition_s { mab_entity_type entity_type ; RKString name ; RKStore properties ;

RKStore attributes ; int is_evaluating ; int is_evaluated ; int is_processed ;

mab_definition_type definition_type ; mab_collection type_tree ;

RKStore definitions ; mab_type type ; } ;

#endif /* marshmallow_mab_h */

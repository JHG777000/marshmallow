/*
 Copyright (c) 2017-2019 Jacob Gordon. All rights reserved.
 
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

#ifndef marshmallow_h
#define marshmallow_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <RKLib/RKMem.h>
#include <RKLib/RKFile.h>

typedef enum { public, private, protected, publish, inherit } marshmallow_access_control ;

typedef enum { arithmetic, arrays, pointers, classes, lambdas, strings, unknowns } marshmallow_type_category ;

typedef enum { i8, u8, i16, u16, i32, u32, i64, u64, f32, f64, blank, ptrsize, macro, type, hex, oct, string, string8, string16, string32, character, class,
    
enum_type, array, ptr, module, function, method, lambda, expression, unknown, arguments, collection, metacollection, nulltype, inittype } marshmallow_root_type ;

typedef enum { noop, assignment, array_assignment, is_equal, is_not_equal, is_greaterthan, is_greaterthan_or_equal, is_lessthan, is_lessthan_or_equal,
    
add, sub, negate, mult, mdiv, rem, not, and, or, bnot, band, bor, xor, lshift, rshift, deref, addrof, msizeof, itemsof, inc, dec, call,
    
slifop, ifop, elseop, ifelseop, whileop, breakop, continueop, switchop, caseop, endcaseop, defaultop, section, gotoop, ret,
    
castop, reinterpretop, convertop } marshmallow_op_type ;

typedef enum { entity_module, entity_class, entity_function, entity_variable, entity_data_type, entity_block, entity_statement, entity_collection,
    
entity_nothing, entity_end } marshmallow_entity_type ;

typedef struct marshmallow_entity_s { marshmallow_entity_type entity_type ; } *marshmallow_entity ;

typedef struct marshmallow_type_s* marshmallow_type ;

typedef struct marshmallow_module_s* marshmallow_module ;

typedef struct marshmallow_variable_s* marshmallow_variable ;

typedef struct marshmallow_function_body_s* marshmallow_function_body ;

#define marshmallow_scope_protocol /*for alignment*/RKList statements ; RKStore variables ;

typedef struct marshmallow_class_s { marshmallow_entity_type entity_type ; marshmallow_access_control access_control ;
    
RKStore variables ; marshmallow_function_body init_function ; } *marshmallow_class ;

typedef struct marshmallow_enum_s { RKList enum_names ; RKStore enums ; } *marshmallow_enum ;

typedef struct marshmallow_type_s { marshmallow_entity_type entity_type ; RKString type_name ; int is_literal ;
    
int is_temporary ; int is_init ; int is_typedef ; int is_cast ; int is_readonly ; marshmallow_root_type root_type ;
    
void* base_type ; RKULong num_of_elements ; int pointers ; } *marshmallow_type ;

typedef struct marshmallow_variable_s { marshmallow_entity_type entity_type ; marshmallow_type type ;
    
RKString name ; void* data ; int is_persistent ; int is_declared ; int is_external ; int is_global ;
    
marshmallow_access_control access_control ; marshmallow_variable static_assignment ; } *marshmallow_variable ;

typedef struct marshmallow_value_s { marshmallow_type type ; RKString value ; RKList array_value ; } *marshmallow_value ;

typedef struct marshmallow_function_signature_s { marshmallow_access_control access_control ; int is_method ; int is_overridable ; int is_override ;
    
int is_declared ; int is_external ; RKString func_name ; marshmallow_class class ;
    
RKStore parameters ; RKList returns ; } *marshmallow_function_signature ;

typedef struct marshmallow_function_body_s { marshmallow_entity_type entity_type ; marshmallow_scope_protocol
    
marshmallow_function_signature signature ; RKStore calls ; marshmallow_module module ; } *marshmallow_function_body ;

typedef struct marshmallow_statement_s { marshmallow_entity_type entity_type ; RKList statements ; int is_expression ; marshmallow_op_type op ;
    
marshmallow_entity var_a ; marshmallow_entity var_b ; marshmallow_function_body function ; } *marshmallow_statement ;

typedef struct marshmallow_module_s { marshmallow_entity_type entity_type ; marshmallow_scope_protocol RKStore declarations ;
    
RKStore types ; RKStore unprocessed_types ; RKStore enums ; RKStore modules ;
    
RKStore functions_and_methods ; RKString name ; } *marshmallow_module ;

typedef struct marshmallow_scope_s { marshmallow_entity_type entity_type ; marshmallow_scope_protocol } *marshmallow_scope ;

typedef struct marshmallow_context_s { RKStore modules ; RKStore words ; RKStore symbols ; int program_has_main ; } *marshmallow_context ;

//keywords and tokens

#define marshmallow_get_keyword(keyword) keyword##_marshmallow_keyword

#define mgk(keyword) marshmallow_get_keyword(keyword)

typedef enum {
    
#define token(word,string) mgk(word),
    
#include "marshmallow_tokens.h"
    
#undef token
    
} marshmallow_keyword ;

typedef struct marshmallow_token_s { marshmallow_keyword keyword ; RKString value ; } *marshmallow_token ;

//debug

void func( void* data ) ;

//context

marshmallow_context marshmallow_new_context( void ) ;

void marshmallow_compile_file( marshmallow_context context, const char* in_file, const char* out_directory ) ;

//ast

void marshmallow_parse_type( marshmallow_type type, marshmallow_token token, int pointers, int* arrays, int num_of_arrays ) ;

void marshmallow_parse_value( marshmallow_token token, marshmallow_variable variable ) ;

marshmallow_type marshmallow_new_type( void ) ;

marshmallow_type marshmallow_copy_type( marshmallow_type t ) ;

marshmallow_variable marshmallow_new_variable( void ) ;

void marshmallow_add_variable_to_scope( marshmallow_scope scope, marshmallow_variable variable ) ;

marshmallow_entity marshmallow_lookup_identifier( marshmallow_function_body function, marshmallow_module module, marshmallow_entity identifier) ;

marshmallow_module marshmallow_new_module( RKString name )  ;

marshmallow_statement marshmallow_new_statement( marshmallow_op_type op_type, int is_expression, marshmallow_entity a, marshmallow_entity b ) ;

marshmallow_function_signature marshmallow_new_function_signature( RKString name, int is_method ) ;

void marshmallow_add_parameter_to_function( marshmallow_function_signature signature, marshmallow_variable parameter, int is_first_parameter ) ;

void marshmallow_add_return_to_function_return_list( marshmallow_function_signature signature, marshmallow_variable a_return ) ;

marshmallow_function_body marshmallow_new_function_body( marshmallow_function_signature signature ) ;

void marshmallow_attach_function_to_statement( marshmallow_function_body function, marshmallow_statement statement ) ;

RKList_node marshmallow_add_statement_to_function( marshmallow_function_body function, marshmallow_statement statement )  ;

void marshmallow_insert_statement_before_statement_to_function( marshmallow_statement new_statement, marshmallow_statement old_statement, marshmallow_function_body function ) ;

void marshmallow_insert_statement_after_statement_to_function( marshmallow_statement new_statement, marshmallow_statement old_statement, marshmallow_function_body function ) ;

void marshmallow_add_function_to_module( marshmallow_function_body function, marshmallow_module module ) ;

void marshmallow_add_function_to_module_declarations( marshmallow_function_body function, marshmallow_module module ) ;

void marshmallow_add_enums_to_module( marshmallow_type type, marshmallow_module module ) ;

void marshmallow_add_typedef_to_module( marshmallow_type type, marshmallow_module module ) ;

//parse

void marshmallow_lex_and_parse_file( marshmallow_context context, RKFile file ) ;

//typecheck

int m_is_type_float( marshmallow_type type ) ;

int m_is_type_signed( marshmallow_type type ) ;

int m_is_type_number( marshmallow_type type ) ;

int m_is_root_type( marshmallow_type type ) ;

marshmallow_type m_get_negate_type( marshmallow_type type ) ;

marshmallow_type typecheck_make_ptr_type_from_type( marshmallow_type type ) ;

marshmallow_type typecheck_get_ptr_type_from_type( marshmallow_type type ) ;

marshmallow_type typecheck_get_type_from_root_type( marshmallow_root_type root ) ;

marshmallow_type_category typecheck_get_type_category( marshmallow_type type ) ;

int m_get_size_of_root_type_in_bytes( marshmallow_type type ) ;

RKULong m_get_size_of_type_in_bytes( marshmallow_type type, marshmallow_root_type* root_type ) ;

RKULong m_get_size_of_type_or_array_in_bytes( marshmallow_type type_or_array, marshmallow_root_type* root_type ) ;

marshmallow_variable typecheck_integer_evaluator( marshmallow_statement statement, marshmallow_module module ) ;

marshmallow_variable typecheck_float_evaluator( marshmallow_statement statement, marshmallow_module module ) ;

void marshmallow_typecheck( marshmallow_context context ) ;

//codegen

const char* marshmallow_ltoa( RKLong val, char* string ) ;

const char* marshmallow_ultoa( RKULong val, char* string ) ;

const char* marshmallow_itoa( int val, char* string ) ;

const char* marshmallow_uitoa( unsigned int val, char* string ) ;

const char* marshmallow_ftoa( float val, char* string ) ;

const char* marshmallow_dtoa( double val, char* string ) ;

void marshmallow_codegen( marshmallow_context context, const char* out_directory) ;

#endif /* marshmallow_h */

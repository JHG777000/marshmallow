/*
 Copyright (c) 2017 Jacob Gordon. All rights reserved.
 
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

typedef enum { public, private, protected, publish, inherit } marshmallow_access_control ;

typedef enum { i8, u8, i16, u16, i32, u32, i64, u64, f32, f64, hex, string, class, array, ptr, module, function, method, lambda, expression,
    
unknown, arguments } marshmallow_root_type ;

typedef enum { noop, assignment, is_equal, is_not_equal, is_greaterthan, is_greaterthan_or_equal, is_lessthan, is_lessthan_or_equal,
    
not, add, sub, negate, mult, mdiv, rem, deref, addrof, msizeof, itemsof, inc, dec, call, slifop, ifop, whileop, ret } marshmallow_op_type ;

typedef enum { entity_module, entity_class, entity_function, entity_variable, entity_data_type, entity_statement, entity_space, entity_end } marshmallow_entity_type ;

typedef struct marshmallow_entity_s { marshmallow_entity_type entity_type ; } *marshmallow_entity ;

typedef struct marshmallow_class_s* marshmallow_class ;

typedef struct marshmallow_type_s* marshmallow_type ;

typedef struct marshmallow_variable_s* marshmallow_variable ;

typedef struct marshmallow_value_s* marshmallow_value ;

typedef struct marshmallow_function_signature_s* marshmallow_function_signature ;

typedef struct marshmallow_function_body_s* marshmallow_function_body ;

typedef struct marshmallow_statement_s* marshmallow_statement ;

typedef struct marshmallow_module_s* marshmallow_module ;

typedef struct marshmallow_scope_s* marshmallow_scope ;

typedef struct marshmallow_context_s* marshmallow_context ;

typedef struct marshmallow_class_s { marshmallow_entity_type entity_type ; RKStore variables ; marshmallow_function_body init_function ; } *marshmallow_class ;

typedef struct marshmallow_type_s { marshmallow_entity_type entity_type ; RKString type_name ;
    
marshmallow_root_type root_type ; void* base_type ; int num_of_elements ; } *marshmallow_type ;

typedef struct marshmallow_variable_s { marshmallow_entity_type entity_type ; marshmallow_type type ;
    
RKString name ; void* data ; int is_hidden ; int is_overridable ; int is_override ; int is_readonly ;
    
int is_persistent ; int is_declared ; int is_external ; marshmallow_access_control access_control ; marshmallow_variable static_assignment ; } *marshmallow_variable ;

typedef struct marshmallow_value_s { marshmallow_type type ; RKString value ; RKList array_value ; } *marshmallow_value ;

typedef struct marshmallow_function_signature_s { int is_method ; int is_declared ; int is_external ; RKString func_name ; marshmallow_class class ;
    
RKStore parameters ; RKList returns ; } *marshmallow_function_signature ;

typedef struct marshmallow_function_body_s { marshmallow_entity_type entity_type ; RKList statements ; RKStore declarations ; RKStore types ; RKStore variables ; RKStore macros ;
    
marshmallow_function_signature signature ; } *marshmallow_function_body ;

typedef struct marshmallow_statement_s { marshmallow_entity_type entity_type ; RKList statements ; int is_expression ; marshmallow_op_type op ;
    
marshmallow_entity var_a ; marshmallow_entity var_b ; marshmallow_function_body function ; } *marshmallow_statement ;

typedef struct marshmallow_module_s { marshmallow_entity_type entity_type ; RKList statements ; RKStore declarations ; RKStore types ; RKStore variables ;
    
RKStore macros ; RKStore modules ;
    
RKStore functions_and_methods ; RKString name ; } *marshmallow_module ;

typedef struct marshmallow_scope_s { marshmallow_entity_type entity_type ; /*for alignment*/RKList statements ; RKStore declarations ; RKStore types ;
    
RKStore variables ; RKStore macros ; } *marshmallow_scope ;

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

void marshmallow_compile_file( marshmallow_context context, const char* in_file, const char* out_file ) ;

//ast

void marshmallow_parse_type( marshmallow_type type, marshmallow_token token, int pointers, int* arrays, int num_of_arrays ) ;

void marshmallow_parse_value( marshmallow_token token, marshmallow_variable variable ) ;

marshmallow_type marshmallow_new_type( void ) ;

marshmallow_variable marshmallow_new_variable( void ) ;

void marshmallow_add_variable_to_scope( marshmallow_scope scope, marshmallow_variable variable ) ;

marshmallow_module marshmallow_new_module( RKString name )  ;

marshmallow_statement marshmallow_new_statement( marshmallow_op_type op_type, int is_expression, marshmallow_entity a, marshmallow_entity b ) ;

marshmallow_function_signature marshmallow_new_function_signature( RKString name, int is_method ) ;

void marshmallow_add_parameter_to_function( marshmallow_function_signature signature, marshmallow_variable parameter, int is_first_parameter ) ;

void marshmallow_add_return_to_function_return_list( marshmallow_function_signature signature, marshmallow_variable a_return ) ;

marshmallow_function_body marshmallow_new_function_body( marshmallow_function_signature signature ) ;

void marshmallow_add_statement_to_function( marshmallow_function_body function, marshmallow_statement statement )  ;

void marshmallow_add_function_to_module( marshmallow_function_body function, marshmallow_module module ) ;

void marshmallow_add_function_to_module_declarations( marshmallow_function_body function, marshmallow_module module ) ;

//parse

void marshmallow_lex_and_parse_file( marshmallow_context context, FILE* file ) ;

//codegen

void marshmallow_codegen( marshmallow_context context, FILE* out_file ) ;

#endif /* marshmallow_h */

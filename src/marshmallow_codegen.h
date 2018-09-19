/*
 Copyright (c) 2018 Jacob Gordon. All rights reserved.
 
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

/*
 INTERNAL HEADER FOR MARSHMALLOW'S CODEGEN
 
 Only codegen files should include this file, and after "marshmallow.h".
 
 The marshmallow codegen infrastructure will consist of:
 
 marshmallow_codegen.c -- Manage the codegen process, provide support and infrastructure that are common to the intermediates,
 provide any needed codegen APIs to the rest of the compiler, and transform the marshmallow ast to mib.
 
 marshmallow_mib.c -- Transform mib into mob, provide support and infrastructure for mib.
 
 marshmallow_mob.c -- Optimize mob per routine, transform mob into mlb, provide support and infrastructure for mob.
 
 marshmallow_mlb.c -- Validate mlb, optimize mlb context wide, send mlb and the cg_context to a backend,
 provide support and infrastructure for mlb.
 
  Backend files:
 
   *marshmallow_C_backend.c -- Transform mlb into C.
 
 -- marshmallow intermediate "bytecode" --
 
 Will be the first intermediate stage in marshmallow's codegen.
 
 Will be a stack based intermediate.
 
 Mib's only purpose is to aid the transformation of the marshmallow ast into mob.
 
 -- marshmallow optimizing bytecode --
 
 Will also be a stack based intermediate, will be taking inspiration from WebAssembly.
 
 Will allow for per routine optimization.
 
 -- marshmallow low-level bytecode --
 
 Will allow for additional optimization, such as inlining.
 
 Will be three-address code.
 
 Will be transformed into C code, or other backend.
 
 --- Overview of codegen -------------------------------------------------------------------------------------------------------
 
 mib(stack based) -> mob(stack based like WebAssembly, optimization) -> mlb(three-address code, inlining) -> C(or other backend)
 
 -------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef marshmallow_codegen_h
#define marshmallow_codegen_h

#define init_backend(name) if (backend_type == marshmallow_##name##_backend) {\
void marshmallow_##name##_backend_func(codegen_backend backend) ;\
marshmallow_##name##_backend_func(backend) ;\
}

#define get_backend_type(name) marshmallow_##name##_backend

#define new_backend(name) void marshmallow_##name##_backend_func(codegen_backend backend)

#define return_pointer_size(name) static RKULong marshmallow_##name##_backend_return_pointer_size(void)

#define get_context(name) static void marshmallow_##name##_backend_get_context(cg_context context, codegen_backend backend)

#define get_builder(name) static void marshmallow_##name##_backend_get_builder(cg_builder builder, cg_context context, codegen_backend backend)

#define get_destroyer(name) static void marshmallow_##name##_backend_get_destroyer(codegen_backend backend)

#define get_callback(name,callback) marshmallow_##name##_backend_##callback

typedef struct cg_context_s* cg_context ;

typedef struct cg_builder_s* cg_builder ;

typedef struct cg_module_s* cg_module ;

typedef struct cg_routine_s* cg_routine ;

typedef struct cg_variable_s* cg_variable ;

typedef struct cg_statement_s* cg_statement ;

typedef struct mlb_statement_s* mlb_statement ;

typedef marshmallow_root_type cg_root_type ; //mib and the other intermediates will only use a subset

typedef enum {cg_entity_variable,cg_entity_mlb_statement,cg_entity_statement,cg_entity_routine,cg_entity_module,cg_entity_context} cg_entity_type ;

struct cg_context_s { cg_entity_type entity_type ; RKStore modules ; RKStore definitions ; } ;

struct cg_module_s { cg_entity_type entity_type ; RKString name ; RKStore routines ; RKStore variables ;
    
RKStore variable_declarations ; RKStore routine_declarations ; RKStore classes ; cg_context context ; } ;

struct cg_routine_s { cg_entity_type entity_type ; RKString name ; int is_global ; int is_external ;
    
RKList return_types ; RKStore parameters ; RKStore variables ; RKStore calls ; RKList mib_code ; RKList mob_code ;
    
RKList mlb_code ; RKStack data_stack ; RKStack op_stack ; cg_module module ; }  ;

struct cg_variable_s { cg_entity_type entity_type ; RKString name ; cg_root_type type ; RKString value ; RKList values ; RKStore class_values ;

int mlb_return_value ; int mlb_get_return_value ; cg_variable ptr ; RKULong num_of_elements ;
    
int is_global ; int is_literal ; int is_temporary ; } ;

typedef enum { mlb_set, mlb_add, mlb_sub, mlb_mult, mlb_div, mlb_rem, mlb_rshift, mlb_lshift, mlb_and, mlb_or, mlb_xor,
    
mlb_not, mlb_logic_and, mlb_logic_or, mlb_logic_not, mlb_deref, mlb_addrof, mlb_sizeof, mlb_cast, mlb_array_index, mlb_array_copy,
    
mlb_class_access, mlb_if, mlb_endif, mlb_else, mlb_else_if, mlb_while, mlb_endwhile, mlb_break, mlb_continue,
    
mlb_switch, mlb_endswitch, mlb_case, mlb_endcase, mlb_default, mlb_goto, mlb_section, mlb_equals, mlb_not_equals,
    
mlb_greaterthan, mlb_lessthan, mlb_greaterthan_or_equals, mlb_lessthan_or_equals,
    
mlb_call, mlb_return, mlb_external_return } mlb_op_type ;

struct mlb_statement_s { cg_entity_type entity_type ; cg_routine routine ; mlb_op_type op ; cg_variable A ; cg_variable B ; cg_variable C ; } ;

typedef struct codegen_backend_s* codegen_backend ;

typedef RKULong (*cg_callback_for_pointer_size)(void) ;

typedef void (*cg_callback_for_context)(cg_context context, codegen_backend backend) ;

typedef void (*cg_callback_for_builder)(cg_builder builder, cg_context context, codegen_backend backend) ;

typedef void (*cg_callback_for_destroyer) (codegen_backend backend);

typedef enum { marshmallow_C_backend } codegen_backend_type ;

struct codegen_backend_s { void* backend_ptr ; FILE* output_file ; cg_callback_for_pointer_size size_callback ;
    
cg_callback_for_context context_callback ; cg_callback_for_builder builder_callback ; cg_callback_for_destroyer destroyer_callback ; } ;

codegen_backend codegen_new_backend( codegen_backend_type backend_type, FILE* out_file ) ;

void codegen_destroy_backend( codegen_backend backend ) ;

void cg_give_context_to_backend( cg_context context, codegen_backend backend ) ;

cg_context cg_new_context( void ) ;

void cg_destroy_context( cg_context context ) ;

void cg_add_module_to_context( cg_module module, cg_context context ) ;

cg_module cg_new_module( RKString name ) ;

void cg_destroy_module( cg_module module ) ;

void cg_add_class_to_module( cg_variable class, cg_module module ) ;

void cg_add_variable_declaration_to_module( cg_variable variable, cg_module module ) ;

void cg_add_routine_declaration_to_module( cg_routine routine, cg_module module ) ;

void cg_add_variable_to_module( cg_variable variable, cg_module module ) ;

void cg_add_routine_to_module( cg_routine routine, cg_module module ) ;

cg_routine cg_new_routine( RKString name, int is_global ) ;

void cg_destroy_routine( cg_routine routine ) ;

void cg_add_parameter_to_routine( cg_variable parameter, cg_routine routine ) ;

void cg_add_return_to_returns_in_routine( cg_variable return_type, cg_routine routine ) ;

void cg_add_variable_to_routine( cg_variable variable, cg_routine routine ) ;

cg_variable cg_new_variable( RKString name, cg_root_type type, int mlb_return_value, int mlb_get_return_value, int num_of_items, int is_global ) ;

void cg_destroy_variable( cg_variable variable ) ;

int cg_variables_are_equal( cg_variable a, cg_variable b ) ;

mlb_statement mlb_add_statement( mlb_op_type op, cg_routine routine, cg_variable A, cg_variable B, cg_variable C ) ;

void mlb_destroy_statement( mlb_statement statement ) ;

void mlb_validate_context( cg_context context ) ;

void mlb_validate_module( cg_module module ) ;

void mlb_validate_routine( cg_routine routine ) ;

void mlb_validate_variable( cg_variable variable ) ;

void mlb_validate_statement( mlb_statement statement ) ;

#endif /* marshmallow_codegen_h */

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
 INTERNAL HEADER FOR MARSHMALLOW'S BACKEND
 
 Only backend files should include this file, and after "marshmallow.h".
 
 The marshmallow backend will consist of:
 
 marshmallow_codegen.c -- Manage the codegen process, and provide any needed codegen APIs to the rest of the compiler.
 
 marshmallow_mib.c -- Transform the marshmallow ast to mib.
 
 marshmallow_mob.c -- Transform mib into mob, then optimize, in a high-level and platform neutral manner.
 
 marshmallow_mlb.c -- Transform mob into mlb, and then transform mlb into C code.
 
 -- marshmallow intermediate "bytecode" --
 
 Will be the first intermediate stage in marshmallow's backend.
 
 Will be a stack based intermediate, taking inspiration from WebAssembly.
 
 Mib's only purpose is to aid the transformation of the marshmallow ast into mob.
 
 -- marshmallow optimizing bytecode --
 
 Will also be a stack based intermediate, but more like WebAssembly.
 
 Will allow for high-level and platform neutral optimization.
 
 -- marshmallow low-level bytecode --
 
 Will allow for low-level and platform specific optimization.
 
 Will be three-address code.
 
 Will be transformed into C code, or other backend.
 
 --- Overview of backend -----------------------------------------------------------------------------------------------------------
 
 mib(stack based) -> mob(stack based, more like WebAssembly, optimization) -> mlb(low-level optimization,TAC) -> C(or other backend)
 
 -----------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef marshmallow_backend_h
#define marshmallow_backend_h

#define new_backend(name) void name##_func(codegen_backend backend)

typedef struct cg_module_s* cg_module ;

typedef struct cg_routine_s* cg_routine ;

typedef struct cg_variable_s* cg_variable ;

typedef struct cg_statement_s* cg_statement ;

typedef struct mlb_statement_s* mlb_statement ;

typedef marshmallow_root_type cg_root_type ; //mib and the other intermediates will only use a subset

struct cg_module_s { RKString name ; RKStore routines ; RKStore variables ; RKStore variable_declarations ; RKStore routine_declarations ; } ;

struct cg_routine_s { RKString name ; int is_global ; int is_external ; RKList return_types ; RKStore parameters ; RKStore variables ;
    
RKList mib_code ; RKList mob_code ; RKList mlb_code ; RKStack data_stack ; RKStack op_stack ; }  ;

struct cg_variable_s { marshmallow_type type ; RKString name ; RKString value ; RKList values ; int mlb_return_value ; int mlb_get_return_value ;
    
void* ptr ; int num_of_items ; int is_global ; } ;

typedef enum { mlb_add, mlb_sub, mlb_mult, mlb_div, mlb_rem, mlb_rshift, mlb_lshift, mlb_and, mlb_or, mlb_xor,
    
mlb_not, mlb_logic_and, mlb_logic_or, mlb_logic_not, mlb_deref, mlb_addrof, mlb_sizeof, mlb_cast, mlb_array_index,
    
mlb_struct_access, mlb_if, mlb_endif, mlb_else, mlb_else_if, mlb_while, mlb_endwhile, mlb_break, mlb_continue,
    
mlb_switch, mlb_endswitch, mlb_case, mlb_endcase, mlb_default, mlb_goto, mlb_section, mlb_equals, mlb_not_equals,
    
mlb_greaterthan, mlb_lessthan, mlb_greaterthan_or_equals, mlb_lessthan_or_equals, mlb_memcpy, mlb_call, mlb_return } mlb_op_type ;

struct mlb_statement_s { cg_routine routine ; mlb_op_type op ; cg_variable A ; cg_variable B ; cg_variable C ; } ;

typedef enum { marshmallow_C_backend } codegen_backend_type ;

typedef struct codegen_backend_s { void* backend_ptr ; } *codegen_backend ;

cg_routine cg_new_routine( RKString name, int is_global, RKList return_types ) ;

void cg_add_parameter_to_routine( cg_variable parameter, cg_routine routine ) ;

void cg_add_return_to_returns_in_routine( cg_root_type return_type, cg_routine routine ) ;

#endif /* marshmallow_backend_h */

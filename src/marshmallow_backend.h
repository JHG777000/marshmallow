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
 
 marshmallow_mib.c -- Transform the marshmallow ast to mib, then transform mib into mob.
 
 marshmallow_mob.c -- Optimize, in a high-level and platform neutral manner.
 
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
 
 Will be transformed into C code.
 
 --- Overview of backend -------------------------------------------------------------------------------------------------------
 
 mib(stack based) -> mob(stack based, more like WebAssembly, optimization) -> mlb(low-level optimization) -> C
 
 -------------------------------------------------------------------------------------------------------------------------------
 
 */


#ifndef marshmallow_backend_h
#define marshmallow_backend_h

#define new_backend(name) void name##_func(codegen_backend backend)

typedef struct cg_module_s* cg_module ;

typedef struct cg_routine_s* cg_routine ;

typedef struct cg_variable_s* cg_variable ;

typedef struct cg_statement_s* cg_statement ;

typedef marshmallow_root_type cg_root_type ; //mib and the other intermediates will only use a subset

struct cg_module_s { RKString name ; RKStore routines ; RKStore variables ; } ;

struct cg_routine_s { RKString name ; int is_global ; int is_external ; RKList return_types ; RKStore parameters ; RKStore variables ;
    
RKList mib_code ; RKList mob_code ; RKList mlb_code ; RKStack data_stack ; RKStack op_stack ; }  ;

struct cg_variable_s { marshmallow_type type ; RKString name ; RKString value ; RKList values ; int alloc_size ; int is_global ; } ;

typedef enum {  mlb_add, mlb_sub, mlb_mult, mlb_div, mlb_rem, mlb_inc, mlb_dec, //12
    
mlb_rshift, mlb_lshift, mlb_and, mlb_or, mlb_xor, mlb_not, mlb_logic_and, mlb_logic_or, mlb_logic_not, //9
    
mlb_load, mlb_store, mlb_move, mlb_upsilon, mlb_phi, mlb_if, mlb_go, mlb_go_equals, mlb_go_not_equals, mlb_go_greaterthan, mlb_go_lessthan, mlb_return } mlb_opcode ; //12

struct cg_instruction_s { cg_root_type type ; cg_routine routine ; mlb_opcode opcode ; cg_variable a ; cg_variable b ; cg_variable c ; } ;

typedef void (*mlb_opcode_func_type)(cg_routine routine, RKList_node node, void* arch_ptr, cg_root_type type, mlb_opcode op, cg_variable a, cg_variable b, cg_variable c) ;

typedef enum { m_C_backend } codegen_backend_type ;

typedef struct codegen_backend_s { void* backend_ptr ; } *codegen_backend ;

cg_routine cg_new_routine( RKString name, int is_global, RKList return_types ) ;

void cg_add_parameter_to_routine( cg_variable parameter, cg_routine routine ) ;

#endif /* marshmallow_backend_h */

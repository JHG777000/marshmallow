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
 
 marshmallow_mlb.c -- Transform mob into mlb, and then with the help from a marshmallow_arch_XXXXX.c file, transform mlb into assembly.
 
  Arch files:
 
   *marshmallow_arch_XXXXX.c -- These files will contain architecture and platform specific information, such as the ABI, assembly syntax, etc.
 
 -- marshmallow intermediate "bytecode" --
 
 Will be the first intermediate stage in marshmallow's backend.
 
 Will be a stack based intermediate, taking inspiration from WebAssembly.
 
 Mib's only purpose is to aid the transformation of the marshmallow ast into mob.
 
 -- marshmallow optimizing bytecode --
 
 Will also be a stack based intermediate, but more like WebAssembly.
 
 Will allow for high-level and platform neutral optimization.
 
 -- marshmallow low-level bytecode --
 
 Will be a SSA based intermediate, taking inspiration from LLVM and QBE.
 
 Will allow for low-level and platform specific optimization, register allocation will be performed on mlb.
 
 Will be transformed into assembly.
 
 --- Overview of backend -------------------------------------------------------------------------------------------------------
 
 mib(stack based) -> mob(stack based, more like WebAssembly, optimization) -> mlb(SSA based, low-level optimization) -> assembly
 
 -------------------------------------------------------------------------------------------------------------------------------
 
 */


#ifndef marshmallow_backend_h
#define marshmallow_backend_h


#define new_architecture(name) void name##_func(codegen_architecture architecture)

#define define_mlb_instructions(name)\
architecture->mlb_opcode_func[mlb_add] = mlb_add_##name ;

typedef struct mib_module_s* mib_module ;

typedef struct mib_routine_s* mib_routine ;

typedef struct mib_variable_s* mib_variable ;

typedef struct mib_instruction_s* mib_instruction ;

typedef marshmallow_root_type mib_root_type ; //mib and the other intermediates will only use a subset

typedef marshmallow_root_type mob_root_type ;

typedef marshmallow_root_type mlb_root_type ;

typedef mib_module mlb_module ;

typedef mib_routine mlb_routine ;

typedef mib_variable mlb_variable ;

typedef mib_instruction mlb_instruction ;

struct mib_module_s { RKString name ; RKStore routines ; RKStore variables ; } ;

struct mib_routine_s { RKString name ; int is_global ; mib_root_type return_type ; RKStore parameters ; RKStore variables ;
    
RKList mib_code ; RKList mob_code ; RKList mlb_code ; RKStack data_stack ; RKStack op_stack ; }  ;

struct mib_variable_s { marshmallow_type type ; RKString name ; RKString value ; int is_global ; } ;

struct mib_instruction_s { mib_root_type type ; mib_routine routine ; void* a ; void* b ; void* c ; } ;

typedef enum { mlb_add, mlb_sub, mlb_mult, mlb_div, mlb_rem, mlb_inc, mlb_dec, mlb_rshift, mlb_lshift, mlb_and, mlb_or, mlb_logic_and, mlb_logic_or,

mlb_load, mlb_store, mlb_move, mlb_if, mlb_go_equals, mlb_go_not_equals, mlb_greaterthan, go_lessthan } mlb_opcode ;

typedef void (*mlb_opcode_func_type)(mlb_routine routine, RKList_node node, mlb_root_type type, mlb_opcode op, void* a, void* b, void* c) ;

typedef enum {m_x86_64} codegen_architecture_type ;

typedef struct codegen_architecture_s { mlb_opcode_func_type mlb_opcode_func[32] ; } *codegen_architecture ;

#endif /* marshmallow_backend_h */

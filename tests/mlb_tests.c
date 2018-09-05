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

#include "marshmallow.h"
#include "marshmallow_codegen.h"

int main(int argc, const char **argv) {

    FILE* output_file = fopen(argv[2], "w") ;
    
    codegen_backend backend = codegen_new_backend(get_backend_type(C),output_file) ;
    
    cg_context my_context = cg_new_context() ;
    
    cg_module my_module = cg_new_module(rkstr("mymod")) ;
    
    cg_add_module_to_context(my_module, my_context) ;
    
    cg_variable E = cg_new_variable(rkstr("E"), i32, -1, -1, 0, 0) ;
    
    cg_add_variable_declaration_to_module(E, my_module) ;
    
    cg_routine my_routine = cg_new_routine(rkstr("myroutine"), 0) ;
    
    my_routine->is_external = 0 ;
    
    cg_add_routine_declaration_to_module(my_routine, my_module) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;
    
    cg_add_routine_to_module(my_routine, my_module) ;
    
    cg_variable A = cg_new_variable(rkstr("A"), i32, -1, -1, 0, 0) ;
    
    cg_variable B = cg_new_variable(rkstr("B"), i32, -1, -1, 0, 0) ;
    
    cg_variable C = cg_new_variable(rkstr("C"), i32, -1, -1, 0, 0) ;
    
    cg_variable R0 = cg_new_variable(rkstr("R0"), i32, 0, -1, 0, 0) ;
    
    cg_add_variable_to_routine(A, my_routine) ;
    
    cg_add_variable_to_routine(B, my_routine) ;
    
    cg_add_variable_to_routine(C, my_routine) ;
    
    cg_add_variable_to_routine(R0, my_routine) ;
    
    mlb_add_statement(mlb_add, my_routine, A->name, B->name, C->name) ;
    
    mlb_add_statement(mlb_set, my_routine, R0->name, A->name, NULL) ;
    
    mlb_add_statement(mlb_return, my_routine, NULL, NULL, NULL) ;
    
    cg_give_context_to_backend(my_context, backend) ;
    
    cg_destroy_context(my_context) ;
    
    codegen_destroy_backend(backend) ;
    
    fclose(output_file) ;
    
    return 0 ;
}

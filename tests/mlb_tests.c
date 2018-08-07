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

    cg_module my_module = cg_new_module(rkstr("mymod")) ;
    
    cg_routine my_routine = cg_new_routine(rkstr("mroutine"), 0) ;
    
    cg_add_return_to_returns_in_routine(i32, my_routine) ;
    
    cg_variable A = cg_new_variable(rkstr("A"), i32, -1, -1, 0, 0) ;
    
    cg_variable B = cg_new_variable(rkstr("B"), i32, -1, -1, 0, 0) ;
    
    cg_variable C = cg_new_variable(rkstr("C"), i32, -1, -1, 0, 0) ;
    
    cg_add_variable_to_routine(A, my_routine) ;
    
    cg_add_variable_to_routine(B, my_routine) ;
    
    cg_add_variable_to_routine(C, my_routine) ;
    
    mlb_new_statement(mlb_add, my_routine, A->name, B->name, C->name) ;
    
    cg_destroy_module(my_module) ;
    
    return 0 ;
}

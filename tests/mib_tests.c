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
    
    FILE* output_file = fopen(argv[1], "w") ;
    
    codegen_backend backend = codegen_new_backend(get_backend(C),output_file) ;
    
    cg_context my_context = cg_new_context() ;
    
    cg_module my_module = cg_new_module(rkstr("mymod")) ;
    
    cg_add_module_to_context(my_module, my_context) ;
    
    cg_variable my_class = cg_new_class( rkstr("myclass"), my_module ) ;
    
    cg_variable var_a = cg_new_variable(rkstr("var_a"), i32, -1, -1, 0, 0) ;
    
    cg_variable var_b = cg_new_variable(rkstr("var_b"), i64, -1, -1, 0, 0) ;
    
    cg_variable var_c = cg_new_variable(rkstr("var_c"), u64, -1, -1, 0, 0) ;
    
    cg_variable var_d = cg_new_variable(rkstr("var_d"), array, -1, -1, 10, 0) ;
    
    var_d->ptr = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;
    
    cg_add_class_element(var_a, my_class) ;
    
    cg_add_class_element(var_b, my_class) ;
    
    cg_add_class_element(var_c, my_class) ;
    
    cg_add_class_element(var_d, my_class) ;
    
    
    cg_routine my_routine = cg_new_routine(rkstr("myroutine"), 1) ;
    
    cg_add_routine_declaration_to_module(my_routine, my_module) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;
    
    cg_add_routine_to_module(my_routine, my_module) ;
    
    cg_variable x = cg_new_variable(rkstr("x"), i32, -1, -1, 0, 0) ;
    
    cg_variable y = cg_new_variable(rkstr("y"), i32, -1, -1, 0, 0) ;
    
    
    cg_variable one = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;
    
    one->value = rkstr("1") ;
    
    one->is_literal = 1 ;
    
    cg_variable two = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;
    
    two->value = rkstr("2") ;
    
    two->is_literal = 1 ;
    
    
    cg_add_variable_to_routine(x, my_routine) ;
    
    cg_add_variable_to_routine(y, my_routine) ;
    
    cg_add_variable_to_routine(one, my_routine) ;
    
    cg_add_variable_to_routine(two, my_routine) ;
    
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(mib_var, my_routine, x) ;
    
    mib_add_statement(cg_assignment, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(mib_var, my_routine, y) ;
    
    mib_add_statement(cg_add, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(mib_const, my_routine, one) ;
    
    mib_add_statement(cg_add, my_routine, NULL) ;
    
    mib_add_statement(mib_var, my_routine, x) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_add_statement(mib_exitgroup, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(cg_if, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(mib_var, my_routine, x) ;
    
    mib_add_statement(cg_greaterthan, my_routine, NULL) ;
    
    mib_add_statement(mib_var, my_routine, y) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_add_statement(cg_else, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_add_statement(cg_endif, my_routine, NULL) ;
    
    mib_add_statement(mib_group, my_routine, NULL) ;
    
    mib_add_statement(cg_return, my_routine, NULL) ;
    
    mib_add_statement(mib_const, my_routine, one) ;
    
    mib_add_statement(mib_const, my_routine, two) ;
    
    mib_add_statement(mib_endgroup, my_routine, NULL) ;
    
    mib_generate_mob(my_routine) ;
    
    mob_generate_mlb(my_routine) ;
    
    
    cg_routine main = cg_new_routine(rkstr("main"), 1) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), main) ;
    
    cg_add_routine_to_module(main, my_module) ;
    
    main->is_external = 1 ;
    
    cg_variable zero = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;
    
    zero->value = rkstr("0") ;
    
    zero->is_literal = 1 ;
    
    cg_add_variable_to_routine(zero, main) ;
    
    mib_add_statement(mib_group, main, NULL) ;
    
    mib_add_statement(cg_return, main, NULL) ;
    
    mib_add_statement(mib_const, main, zero) ;
    
    mib_add_statement(mib_endgroup, main, NULL) ;
    
    mib_generate_mob(main) ;
    
    mob_generate_mlb(main) ;
    
    cg_give_context_to_backend(my_context, backend) ;
    
    cg_destroy_context(my_context) ;
    
    codegen_destroy_backend(backend) ;
    
    fclose(output_file) ;
    
    return 0 ;
    
}

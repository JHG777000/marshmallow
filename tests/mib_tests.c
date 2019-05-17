/*
 Copyright (c) 2018-2019 Jacob Gordon. All rights reserved.

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

    codegen_backend backend = codegen_new_backend(get_backend(C),argv[1]) ;

    cg_context my_context = cg_new_context() ;

    cg_module my_module = cg_new_module(rkstr("mymod_mib")) ;

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


    cg_routine other_routine = cg_new_routine(rkstr("other_routine"), 1) ;

    cg_add_routine_declaration_to_module(other_routine, my_module) ;

    cg_variable A = cg_new_variable(rkstr("A"), i32, -1, -1, 0, 0) ;

    cg_variable B = cg_new_variable(rkstr("B"), i32, -1, -1, 0, 0) ;

    cg_variable C = cg_new_variable(rkstr("C"), i32, -1, -1, 0, 0) ;

    cg_variable D = cg_new_variable(rkstr("D"), i32, -1, -1, 0, 0) ;

    cg_variable E = cg_new_variable(rkstr("E"), array, -1, -1, 10, 0) ;

    E->ptr = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;

    cg_variable F = cg_new_variable(rkstr("F"), array, -1, -1, 10, 0) ;

    F->ptr = cg_new_variable(NULL, array, -1, -1, 22, 0) ;

    F->ptr->ptr = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;

    cg_variable G = cg_new_variable(rkstr("G"), class, -1, -1, 0, 0) ;

    G->ptr = my_class ;

    RKStore_AddItem(other_routine->parameters, A, "A") ;

    RKStore_AddItem(other_routine->parameters, B, "B") ;

    RKStore_AddItem(other_routine->parameters, C, "C") ;

    RKStore_AddItem(other_routine->parameters, D, "D") ;

    cg_add_variable_to_routine(E, other_routine) ;

    cg_add_variable_to_routine(F, other_routine) ;

    cg_add_variable_to_routine(G, other_routine) ;

    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), other_routine) ;

    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), other_routine) ;

    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), other_routine) ;

    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), other_routine) ;

    cg_variable ERet = cg_new_variable(NULL, array, -1, -1, 10, 0) ;

    ERet->ptr = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;

    cg_add_return_to_returns_in_routine(ERet, other_routine) ;

    cg_add_routine_to_module(other_routine, my_module) ;

    cg_variable section_var = cg_new_variable(NULL, i8, -1, -1, 0, 0) ;

    section_var->is_literal = 1 ;

    section_var->value = rkstr("loop") ;

    cg_add_variable_to_routine(section_var, other_routine) ;

    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(cg_if, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, A) ;

    mib_add_statement(mib_endgroup, other_routine, NULL) ;


    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(cg_section, other_routine, section_var) ;

    mib_add_statement(cg_if, other_routine, NULL) ;

    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, A) ;

    mib_add_statement(cg_lessthan, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, B) ;

    mib_add_statement(mib_endgroup, other_routine, NULL) ;

    mib_add_statement(mib_endgroup, other_routine, NULL) ;


    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, A) ;

    mib_add_statement(cg_assignment, other_routine, NULL) ;

    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, A) ;

    mib_add_statement(cg_add, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, B) ;

    mib_add_statement(mib_endgroup, other_routine, NULL) ;

    mib_add_statement(mib_exitgroup, other_routine, NULL) ;


    mib_add_statement(mib_endgroup, other_routine, NULL) ;

    mib_add_statement(cg_goto, other_routine, section_var) ;


    mib_add_statement(cg_endif, other_routine, NULL) ;

    mib_add_statement(cg_endif, other_routine, NULL) ;


    mib_add_statement(mib_group, other_routine, NULL) ;

    mib_add_statement(cg_return, other_routine, NULL) ;

    mib_add_statement(mib_var, other_routine, A) ;

    mib_add_statement(mib_var, other_routine, B) ;

    mib_add_statement(mib_var, other_routine, C) ;

    mib_add_statement(mib_var, other_routine, D) ;

    mib_add_statement(mib_var, other_routine, E) ;

    mib_add_statement(mib_endgroup, other_routine, NULL) ;

    mib_generate_mob(other_routine) ;

    mob_generate_mlb(other_routine) ;


    cg_routine my_routine = cg_new_routine(rkstr("myroutine"), 1) ;

    cg_add_routine_declaration_to_module(my_routine, my_module) ;

    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;

    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;

    cg_add_routine_to_module(my_routine, my_module) ;

    cg_variable x = cg_new_variable(rkstr("x"), i32, -1, -1, 0, 0) ;

    x->value = rkstr("0") ;

    cg_variable y = cg_new_variable(rkstr("y"), i32, -1, -1, 0, 0) ;

    y->value = rkstr("0") ;

    cg_variable z = cg_new_variable(rkstr("z"), i32, -1, -1, 0, 0) ;

    z->value = rkstr("0") ;

    cg_variable z2 = cg_new_variable(rkstr("z2"), i32, -1, -1, 0, 0) ;

    z2->value = rkstr("0") ;

    cg_variable z3 = cg_new_variable(rkstr("z3"), i32, -1, -1, 0, 0) ;

    z3->value = rkstr("0") ;

    cg_variable z4 = cg_new_variable(rkstr("z4"), i32, -1, -1, 0, 0) ;

    z4->value = rkstr("0") ;

    cg_variable call = cg_new_variable(NULL, collection, -1, -1, 0, 0) ;

    call->values = RKList_NewList() ;

    call->is_literal = 1 ;

    cg_variable one = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;

    one->value = rkstr("1") ;

    one->is_literal = 1 ;

    cg_variable two = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;

    two->value = rkstr("2") ;

    two->is_literal = 1 ;


    cg_add_variable_to_routine(x, my_routine) ;

    cg_add_variable_to_routine(y, my_routine) ;

    cg_add_variable_to_routine(z, my_routine) ;

    cg_add_variable_to_routine(z2, my_routine) ;

    cg_add_variable_to_routine(z3, my_routine) ;

    cg_add_variable_to_routine(z4, my_routine) ;

    cg_add_variable_to_routine(call, my_routine) ;

    cg_add_variable_to_routine(one, my_routine) ;

    cg_add_variable_to_routine(two, my_routine) ;


    RKList_AddToList(call->values, other_routine) ;

    RKList_AddToList(call->values, one) ;

    RKList_AddToList(call->values, two) ;

    RKList_AddToList(call->values, x) ;

    RKList_AddToList(call->values, y) ;


    mib_add_statement(cg_call, my_routine, call) ;

    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z) ;

    mib_add_statement(cg_assignment, my_routine, NULL) ;

    mib_add_statement(cg_get_return, my_routine, NULL) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;


    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z2) ;

    mib_add_statement(cg_assignment, my_routine, NULL) ;

    mib_add_statement(cg_get_return, my_routine, NULL) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;


    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z3) ;

    mib_add_statement(cg_assignment, my_routine, NULL) ;

    mib_add_statement(cg_get_return, my_routine, NULL) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;


    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z4) ;

    mib_add_statement(cg_assignment, my_routine, NULL) ;

    mib_add_statement(cg_get_return, my_routine, NULL) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;


    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(cg_switch, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z) ;

    mib_add_statement(mib_endgroup, my_routine, NULL) ;


    mib_add_statement(cg_case, my_routine, one) ;

    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z2) ;

    mib_add_statement(cg_mult, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;

    mib_add_statement(cg_endcase, my_routine, NULL) ;


    mib_add_statement(cg_case, my_routine, two) ;

    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z2) ;

    mib_add_statement(cg_div, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;

    mib_add_statement(cg_endcase, my_routine, NULL) ;


    mib_add_statement(cg_default, my_routine, NULL) ;

    mib_add_statement(mib_group, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z2) ;

    mib_add_statement(cg_rem, my_routine, NULL) ;

    mib_add_statement(mib_var, my_routine, z) ;

    mib_add_statement(mib_exitgroup, my_routine, NULL) ;

    mib_add_statement(cg_endcase, my_routine, NULL) ;


    mib_add_statement(cg_endswitch, my_routine, NULL) ;

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

    cg_variable call2 = cg_new_variable(NULL, collection, -1, -1, 0, 0) ;

    call2->values = RKList_NewList() ;

    call2->is_literal = 1 ;

    RKList_AddToList(call2->values, my_routine) ;

    cg_add_variable_to_routine(zero, main) ;

    cg_add_variable_to_routine(call2, main) ;

    mib_add_statement(cg_call, main, call2) ;

    mib_add_statement(mib_group, main, NULL) ;

    mib_add_statement(cg_return, main, NULL) ;

    mib_add_statement(mib_const, main, zero) ;

    mib_add_statement(mib_endgroup, main, NULL) ;

    mib_generate_mob(main) ;

    mob_generate_mlb(main) ;


    cg_give_context_to_backend(my_context, backend) ;

    cg_destroy_context(my_context) ;

    codegen_destroy_backend(backend) ;

    return 0 ;

}

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
    
    cg_variable E = cg_new_variable(rkstr("E"), i32, -1, -1, 0, 1) ;
    
    cg_add_variable_declaration_to_module(E, my_module) ;
    
    cg_add_variable_to_module(E, my_module) ;
    
    cg_variable F = cg_new_variable(rkstr("F"), class, -1, -1, 0, 1) ;
    
    F->ptr = my_class ;
    
    cg_add_variable_declaration_to_module(F, my_module) ;
    
    cg_add_variable_to_module(F, my_module) ;
    
    cg_routine my_routine = cg_new_routine(rkstr("myroutine"), 1) ;
    
    cg_add_routine_declaration_to_module(my_routine, my_module) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), my_routine) ;
    
    cg_add_routine_to_module(my_routine, my_module) ;
    
    cg_variable A = cg_new_variable(rkstr("A"), i32, -1, -1, 0, 0) ;
    
    A->value = rkstr("0") ;
    
    cg_variable B = cg_new_variable(rkstr("B"), i32, -1, -1, 0, 0) ;
    
    B->value = rkstr("0") ;
    
    cg_variable C = cg_new_variable(rkstr("C"), i32, -1, -1, 0, 0) ;
    
    C->value = rkstr("0") ;
    
    cg_variable D = cg_new_variable(rkstr("D"), i32, -1, -1, 0, 0) ;
    
    D->value = rkstr("0") ;
    
    cg_variable R0 = cg_new_variable(rkstr("R0"), i32, 0, -1, 0, 0) ;
    
    RKStore_AddItem(my_routine->parameters, D, "D") ;
    
    cg_add_variable_to_routine(A, my_routine) ;
    
    cg_add_variable_to_routine(B, my_routine) ;
    
    cg_add_variable_to_routine(C, my_routine) ;
    
    cg_add_variable_to_routine(R0, my_routine) ;
    
    cg_variable class_element = cg_new_variable(NULL, i8, -1, -1, 0, 0) ;
    
    class_element->class_element = rkstr("var_d") ;
    
    class_element->is_literal = 1 ;
    
    class_element->ptr = F ;
    
    cg_variable array_element = cg_new_variable(NULL, i8, -1, -1, 0, 0) ;
    
    array_element->index = 1 ;
    
    array_element->is_literal = 1 ;
    
    array_element->ptr = class_element ;
    
    cg_add_variable_to_routine(array_element, my_routine) ;
    
    mlb_add_statement(mlb_set, my_routine, B, array_element, NULL) ;
    
    mlb_add_statement(mlb_add, my_routine, A, B, C) ;
    
    mlb_add_statement(mlb_set, my_routine, R0, A, NULL) ;
    
    mlb_add_statement(mlb_return, my_routine, NULL, NULL, NULL) ;
    
    cg_variable A2 = cg_new_variable(rkstr("A"), i32, -1, -1, 0, 0) ;
    
    A2->value = rkstr("0") ;
    
    cg_variable B2 = cg_new_variable(rkstr("B"), i32, -1, -1, 0, 0) ;
    
    B2->value = rkstr("0") ;
    
    cg_variable zero2 = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;
    
    zero2->value = rkstr("0") ;
    
    zero2->is_literal = 1 ;
    
    cg_routine main2 = cg_new_routine(rkstr("main2"), 1) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), main2) ;
    
    cg_add_routine_to_module(main2, my_module) ;
    
    main2->is_external = 1 ;
    
    RKStore_AddItem(main2->parameters, B2, "B") ;
    
    cg_add_variable_to_routine(zero2, main2) ;
    
    mlb_add_statement(mlb_add, main2, B2, B2, zero2) ;
    
    mlb_add_statement(mlb_external_return, main2, B2, NULL, NULL) ;
    
    cg_routine main = cg_new_routine(rkstr("main"), 1) ;
    
    cg_add_return_to_returns_in_routine(cg_new_variable(NULL,i32,-1,-1,0,0), main) ;
    
    cg_add_routine_to_module(main, my_module) ;
    
    main->is_external = 1 ;
    
    cg_variable GR0 = cg_new_variable(rkstr("GR0"), i32, -1, 0, 0, 0) ;
    
    cg_variable GR02 = cg_new_variable(rkstr("GR0"), i32, -1, 0, 0, 0) ;
    
    cg_variable call = cg_new_variable(NULL, collection, -1, -1, 0, 0) ;
    
    call->values = RKList_NewList() ;
    
    call->is_literal = 1 ;
    
    RKList_AddToList(call->values, my_routine) ;
    
    RKList_AddToList(call->values, GR02) ;
    
    cg_variable call2 = cg_new_variable(NULL, collection, -1, -1, 0, 0) ;
    
    call2->values = RKList_NewList() ;
    
    call2->is_literal = 1 ;
    
    RKList_AddToList(call2->values, main2) ;
    
    cg_variable zero = cg_new_variable(NULL, i32, -1, -1, 0, 0) ;
    
    zero->value = rkstr("0") ;
    
    zero->is_literal = 1 ;
    
    RKList_AddToList(call2->values, zero) ;
    
    cg_add_variable_to_routine(call, main) ;
    
    cg_add_variable_to_routine(call2, main) ;
    
    cg_add_variable_to_routine(GR0, main) ;
    
    cg_add_variable_to_routine(A2, main) ;
    
    mlb_add_statement(mlb_call,main,call2,NULL,NULL) ;
    
    mlb_add_statement(mlb_set,main,A2,GR0,NULL) ;
    
    mlb_add_statement(mlb_call,main,call,NULL,NULL) ;
    
    mlb_add_statement(mlb_external_return, main, GR0, NULL, NULL) ;
    
    cg_give_context_to_backend(my_context, backend) ;
    
    cg_destroy_context(my_context) ;
    
    codegen_destroy_backend(backend) ;
    
    fclose(output_file) ;
    
    return 0 ;
}

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
#include "marshmallow_cfg.h"

int main(int argc, const char **argv) {

    marshmallow_context context = marshmallow_new_context() ;

    cfg_module my_module = cfg_new_module(rkstr("my_module")) ;

    cfg_add_module_to_context(my_module, context) ;

    cfg_function_signature my_function_signature = cfg_new_function_signature(rkstr("my_function"), 0) ;

    cfg_function_body my_function = cfg_new_function_body(my_function_signature) ;

    cfg_add_function_to_module(my_function, my_module) ;

    my_function->entry_block = cfg_new_block(entry_block) ;

    cfg_type int_type = cfg_new_type(rkstr("i32")) ;

    int_type->root_type = i32 ;

    cfg_add_type_to_module(int_type, my_module) ;

    cfg_variable x = cfg_new_variable() ;

    x->type_ptr = cfg_get_type_from_module("i32",my_module) ;

    x->name = rkstr("x") ;

    cfg_add_variable_to_function(x, my_function) ;

    cfg_variable y = cfg_new_variable() ;

    y->type_ptr = cfg_get_type_from_module("i32",my_module) ;

    y->name = rkstr("y") ;

    cfg_add_variable_to_function(y, my_function) ;

    cfg_variable one = cfg_new_variable() ;

    one->data = rkstr("1") ;

    one->type_ptr = int_type ;

    one->is_literal = 1 ;

    cfg_add_variable_to_function(one, my_function) ;

    // x := ( y + ( 1 + x ) ) ;

    cfg_block b0 = cfg_new_block(statement_block) ;

    b0->op = assignment ;

    cfg_add_block_to_block_output((cfg_block)x, b0, "lhs") ;

    cfg_add_block_to_block_output(b0, my_function->entry_block, "next") ;

    cfg_block b1 = cfg_new_block(statement_block) ;

    b1->op = add ;

    cfg_add_block_to_block_output((cfg_block)y, b1, "lhs") ;

    cfg_add_block_to_block_output(b1, b0, "rhs") ;

    cfg_block b2 = cfg_new_block(statement_block) ;

    b2->op = add ;

    cfg_add_block_to_block_output((cfg_block)one, b2, "lhs") ;

    cfg_add_block_to_block_output((cfg_block)x, b2, "rhs") ;

    cfg_add_block_to_block_output(b2, b1, "rhs") ;

    marshmallow_destroy_context(context) ;

    return 0 ;
}

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

typedef struct c_backend_s { RKStore declarations ; RKStore symbols ; } *c_backend ;

static void add_to_declarations( cg_routine routine, cg_variable variable ) {
    
    
}

static int is_symbol_used( RKString symbol ) {
    
    return 0 ;
}

return_pointer_size(C) {
    
    return 8 ;
}

get_context(C) {
    
    
}

get_builder(C) {
    
    
}

new_backend(C) {
    
    backend->size_callback = get_callback(C,return_pointer_size) ;
    
    backend->context_callback = get_callback(C,get_context) ;
    
    backend->builder_callback = get_callback(C,get_builder) ;
    
    c_backend c = RKMem_NewMemOfType(struct c_backend_s) ;
    
    c->declarations = RKStore_NewStore() ;
    
    c->symbols = RKStore_NewStore() ;
    
    backend->backend_ptr = c ;
    
    cg_routine memcpy_routine = cg_new_routine(rkstr("memcpy"), 1) ;
    
    cg_variable dest = cg_new_variable(rkstr("dest"), blank, -1, -1, 0, 0) ;
    
    cg_variable src = cg_new_variable(rkstr("src"), blank, -1, -1, 0, 0) ;
    
    cg_variable n = cg_new_variable(rkstr("n"), pointer, -1, -1, 0, 0) ;
    
    cg_add_parameter_to_routine(dest, memcpy_routine) ;
    
    cg_add_parameter_to_routine(src, memcpy_routine) ;
    
    cg_add_parameter_to_routine(n, memcpy_routine) ;
    
    mlb_validate_routine(memcpy_routine) ;
    
    add_to_declarations(memcpy_routine,NULL) ;
}

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
#include "marshmallow_backend.h"


mib_routine mib_new_routine( RKString name, int is_global, mib_root_type return_type ) {
    
    mib_routine routine = RKMem_NewMemOfType(struct mib_routine_s) ;
    
    routine->name = name ;
    
    routine->is_global = is_global ;
    
    routine->return_type = return_type ;
    
    routine->parameters = NULL ;
    
    routine->variables = NULL ;
    
    routine->mib_code = NULL ;
    
    routine->mob_code = NULL ;
    
    routine->mlb_code = NULL ;
    
    routine->data_stack = NULL ;
    
    routine->op_stack = NULL ;
    
    return routine ;
}

void mib_add_parameter_to_routine( mib_variable parameter, mib_routine routine ) {
    
    RKList_AddToList(RKStore_GetList(routine->parameters), parameter) ;
}
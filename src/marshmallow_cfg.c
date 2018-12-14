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
#include "marshmallow_cfg.h"


cfg_module cfg_new_module( RKString name ) {
    
    cfg_module module = RKMem_NewMemOfType(struct cfg_module_s) ;
    
    module->entity_type = entity_module ;
    
    module->declarations = RKStore_NewStore() ;
    
    module->functions_and_methods = RKStore_NewStore() ;
    
    module->modules = RKStore_NewStore() ;
    
    module->types = RKStore_NewStore() ;
    
    module->unprocessed_types = RKStore_NewStore() ;
    
    module->enums = RKStore_NewStore() ;
    
    module->variables = RKStore_NewStore() ;
    
    module->name = RKString_CopyString(name) ;
    
    return module ;
}

void cfg_destroy_module( cfg_module module ) {
    
    RKStore_DestroyStore(module->declarations) ;
    
    RKStore_DestroyStore(module->functions_and_methods) ;
    
    RKStore_DestroyStore(module->modules) ;
    
    RKStore_DestroyStore(module->types) ;
    
    RKStore_DestroyStore(module->unprocessed_types) ;
    
    RKStore_DestroyStore(module->enums) ;
    
    RKStore_DestroyStore(module->variables) ;
    
    RKString_DestroyString(module->name) ;
    
    free(module) ;
}

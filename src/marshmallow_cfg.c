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


static void DeleteVariableInListOrStore(void* data) {
    
    if ( ((cfg_variable)data)->entity_type != entity_variable ) return ;
    
    cfg_destroy_variable(data) ;
}

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

cfg_function_signature cfg_new_function_signature( RKString name, int is_method ) {
    
    cfg_function_signature signature = RKMem_NewMemOfType(struct cfg_function_signature_s) ;
    
    signature->parameters = RKStore_NewStore() ;
    
    signature->class = NULL ;
    
    signature->func_name = RKString_CopyString(name) ;
    
    signature->access_control = public ;
    
    signature->is_method = is_method ;
    
    signature->returns = RKList_NewList() ;
    
    signature->is_overridable = 0 ;
    
    signature->is_override = 0 ;
    
    signature->is_declared = 0 ;
    
    signature->is_external = 0 ;
    
    return signature ;
}

void cfg_destroy_function_signature( cfg_function_signature signature ) {
    
    RKString_DestroyString(signature->func_name) ;
    
    RKStore_IterateStoreWith(DeleteVariableInListOrStore, signature->parameters) ;
    
    RKStore_DestroyStore(signature->parameters) ;
    
    RKList_IterateListWith(DeleteVariableInListOrStore, signature->returns) ;
    
    RKList_DeleteList(signature->returns) ;
    
    free(signature) ;
}

void cfg_add_parameter_to_function( cfg_function_signature signature, cfg_variable parameter, int is_first_parameter ) {
    
    RKStore_AddItem(signature->parameters, parameter, RKString_GetString(parameter->name)) ;
}

void cfg_add_return_to_function_return_list( cfg_function_signature signature, cfg_variable a_return ) {
    
    RKList_AddToList(signature->returns, a_return) ;
}

cfg_function_body cfg_new_function_body( cfg_function_signature signature ) {
    
    cfg_function_body function = RKMem_NewMemOfType(struct cfg_function_body_s) ;
    
    function->entity_type = entity_function ;
    
    function->signature = signature ;
    
    function->entry_block = NULL ;
    
    function->variables = RKStore_NewStore() ;
    
    function->module = NULL ;
    
    return function ;
}

void cfg_destroy_function_body( cfg_function_body function ) {
    
    cfg_destroy_function_signature(function->signature) ;
    
    RKStore_IterateStoreWith(DeleteVariableInListOrStore, function->variables) ;
    
    RKStore_DestroyStore(function->variables) ;
    
    free(function) ;
}

cfg_block cfg_new_block( cfg_block_type block_type ) {
    
    cfg_block block = RKMem_NewMemOfType(struct cfg_block_s) ;
    
    block->entity_type = entity_block ;
    
    block->block_type = block_type ;
    
    block->is_expression = 0 ;
    
    block->retvar = NULL ;
    
    block->op = noop ;
    
    block->input_block = NULL ;
    
    block->output_blocks = NULL ;
    
    return block ;
}

void cfg_destroy_block( cfg_block block ) {
    
    if ( block->output_blocks != NULL ) RKStore_DestroyStore(block->output_blocks) ;
    
    free(block) ;
}

void cfg_set_block_statement( cfg_block block, marshmallow_op_type op_type, int is_expression ) {
    
    block->op = op_type ;
    
    block->is_expression = is_expression ;
}

void cfg_add_block_to_block_output( cfg_block block_to_add, cfg_block block, const char* output_name ) {
    
    if ( block_to_add == NULL ) return ;
    
    if ( block == NULL ) return ;
 
    block_to_add->input_block = block ;
    
    if ( block->output_blocks != NULL ) block->output_blocks = RKStore_NewStore() ;
    
    RKStore_AddItem(block->output_blocks, block_to_add, output_name) ;
}

cfg_variable cfg_new_variable( void ) {
    
    cfg_variable variable = RKMem_NewMemOfType(struct cfg_variable_s) ;
    
    variable->entity_type = entity_variable ;
    
    variable->access_control = public ;
    
    variable->name = NULL ;
    
    variable->data = NULL ;
    
    variable->is_declared = 0 ;
    
    variable->is_external = 0 ;
    
    variable->is_global = 0 ;
    
    variable->is_persistent = 0 ;
    
    variable->is_literal = 0 ;
    
    variable->is_temporary = 0 ;
    
    variable->type = NULL ;
    
    variable->static_assignment = NULL ;
    
    return variable ;
}

void cfg_destroy_variable( cfg_variable variable ) {
    
    if ( variable->name != NULL ) RKString_DestroyString(variable->name) ;
    
    if ( variable != NULL ) cfg_destroy_variable(variable->static_assignment) ;
    
    free(variable) ;
}

cfg_type cfg_new_type( void ) {
    
    cfg_type type = RKMem_NewMemOfType(struct cfg_type_s) ;
    
    type->entity_type = entity_data_type ;
    
    type->base_type = NULL ;
    
    type->root_type = unknown ;
    
    type->type_name = rkstr("unknown") ;
    
    type->is_typedef = 0 ;
    
    type->is_readonly = 0 ;
    
    type->num_of_elements = -1 ;
    
    type->pointers = 0 ;
    
    return type ;
}

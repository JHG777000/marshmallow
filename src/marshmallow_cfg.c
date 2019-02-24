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

static int cfg_verify_identifier( cfg_function_body function, cfg_module module, marshmallow_entity identifier ) ;

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

void cfg_add_module_to_context( cfg_module module, marshmallow_context context ) {
    
    module->context = context ;
    
    RKStore_AddItem(context->modules, module, RKString_GetString(module->name)) ;
}

cfg_function_signature cfg_new_function_signature( RKString name, int is_method ) {
    
    cfg_function_signature signature = RKMem_NewMemOfType(struct cfg_function_signature_s) ;
    
    signature->parameters = RKStore_NewStore() ;
    
    signature->class = NULL ;
    
    signature->func_name = name ;
    
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

void cfg_add_variable_to_function( cfg_variable variable, cfg_function_body function ) {
    
    
    if ( variable->name != NULL ) if (!cfg_verify_identifier(function, function->module, (marshmallow_entity)variable)) {
        
        printf("Attempt to use: %s, as a variable name failed, already used in this module.\n", RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( variable->name != NULL ) RKStore_AddItem(function->variables, variable, RKString_GetString(variable->name)) ;
    
    if ( variable->name == NULL ) RKStore_AddItemToList(function->variables, variable) ;
}

cfg_block cfg_new_block( cfg_block_type block_type ) {
    
    cfg_block block = RKMem_NewMemOfType(struct cfg_block_s) ;
    
    block->entity_type = entity_block ;
    
    block->block_type = block_type ;
    
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

void cfg_set_block_statement( cfg_block block, marshmallow_op_type op_type ) {
    
    block->op = op_type ;
}

void cfg_add_block_to_block_output( cfg_block block_to_add, cfg_block block, const char* output_name ) {
    
    if ( block_to_add == NULL ) return ;
    
    if ( block == NULL ) return ;
 
    block_to_add->input_block = block ;
    
    if ( block->output_blocks == NULL ) block->output_blocks = RKStore_NewStore() ;
    
    RKStore_AddItem(block->output_blocks, block_to_add, output_name) ;
}

cfg_block cfg_get_block_from_block_output( cfg_block block, const char* output_name ) {
    
    if ( block == NULL ) return NULL ;
    
    if ( block->output_blocks == NULL ) block->output_blocks = RKStore_NewStore() ;
    
    return RKStore_GetItem(block->output_blocks, output_name) ;
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

void cfg_destroy_type( cfg_type type ) {
    
    if ( type->type_name != NULL ) RKString_DestroyString(type->type_name) ;
    
    free(type) ;
}

RKString cfg_get_name_from_entity( marshmallow_entity entity ) {
 
    switch (entity->entity_type) {
            
        case entity_variable:
            
            return ((cfg_variable)entity)->name ;
            
            break;
            
        case entity_function:
            
            return ((cfg_function_body)entity)->signature->func_name ;
            
            break;
            
        case entity_data_type:
            
            return ((cfg_type)entity)->type_name ;
            
            break;
            
        case entity_class:
            
            return ((cfg_class)entity)->class_name ;
            
            break;
            
        default:
            break;
    }
    
    return NULL ;
}

static int cfg_verify_identifier( cfg_function_body function, cfg_module module, marshmallow_entity identifier ) {
    
    RKUInt flag = 0 ;
    
    if ( RKStore_ItemExists(module->context->words, RKString_GetString(cfg_get_name_from_entity(identifier))) ) {
    
        printf("Attempt to use: %s, as an identifier failed, is a keyword.\n", RKString_GetString(function->signature->func_name)) ;
        
        printf("Keywords can not be used as identifiers.\n") ;
        
        return 0 ;
    }
    
    if ( function != NULL ) {
       
        if ( RKStore_ItemExists(function->variables, RKString_GetString(cfg_get_name_from_entity(identifier))) ) {
            
            printf("Identifier: %s, already used in this function or method, as a variable.\n", RKString_GetString(cfg_get_name_from_entity(identifier))) ;
        }
    }
    
    if ( function == NULL ) {
        
        if ( RKStore_ItemExists(module->variables, RKString_GetString(cfg_get_name_from_entity(identifier))) ) flag |= 0x1 ;
        
        if ( RKStore_ItemExists(module->functions_and_methods, RKString_GetString(cfg_get_name_from_entity(identifier))) ) flag |= 0x2 ;
        
        if ( RKStore_ItemExists(module->declarations, RKString_GetString(cfg_get_name_from_entity(identifier))) ) flag |= 0x4 ;
        
        if ( RKStore_ItemExists(module->types, RKString_GetString(cfg_get_name_from_entity(identifier))) ) flag |= 0x8 ;
        
        if ( ( flag == 0x3 || flag == 0x7 ) || flag >= 0x9 ) {
        
          if ( flag & 0xFE ) printf("Identifier: %s, already used in this module, as a variable.\n", RKString_GetString(cfg_get_name_from_entity(identifier))) ;
            
          if ( flag & 0xFD ) printf("Identifier: %s, already used in this module, as a functions or method.\n",
                                    RKString_GetString(cfg_get_name_from_entity(identifier))) ;
            
          if ( flag & 0xFB ) printf("Identifier: %s, already used in this module, as a declaration.\n", RKString_GetString(cfg_get_name_from_entity(identifier))) ;
            
          if ( flag & 0xF7 ) printf("Identifier: %s, already used in this module, as a type.\n", RKString_GetString(cfg_get_name_from_entity(identifier))) ;
            
            return 0 ;
        }
    }
    
    return 1 ;
}

void cfg_add_variable_to_module( cfg_variable variable, cfg_module module ) {
    
    if (!cfg_verify_identifier(NULL, module, (marshmallow_entity)variable)) {
        
        printf("Attempt to use: %s, as a variable name failed, already used in this module.\n", RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(module->variables, variable, RKString_GetString(variable->name)) ;
}

void cfg_add_function_to_module( cfg_function_body function, cfg_module module ) {
    
    if (!cfg_verify_identifier(NULL, module, (marshmallow_entity)function)) {
        
        printf("Attempt to use: %s, as a function name failed, already used in this module.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(module->functions_and_methods, function, RKString_GetString(function->signature->func_name)) ;
    
    function->module = module ;
}

void cfg_add_declaration_to_module( marshmallow_entity entity, cfg_module module ) {
    
    if (!cfg_verify_identifier(NULL, module, entity)) {
        
        printf("Attempt to use: %s, as a declaration name failed, already used in this module.\n", RKString_GetString(cfg_get_name_from_entity(entity))) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(module->declarations, entity, RKString_GetString(cfg_get_name_from_entity(entity))) ;
    
}

void cfg_add_type_to_module( cfg_type type, cfg_module module ) {
    
    if (!cfg_verify_identifier(NULL, module, (marshmallow_entity)type)) {
        
        printf("Attempt to use: %s, as a type name failed, already used in this module.\n", RKString_GetString(type->type_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(module->declarations, type, RKString_GetString(type->type_name)) ;
    
}

void cfg_add_enums_to_module( cfg_type type, cfg_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( type->root_type != enum_type ) return ;
    
    list = ((cfg_enum)type->base_type)->enum_names ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            if ( RKStore_ItemExists(module->enums, RKString_GetString(RKList_GetData(node))) ) {
                
                printf("Enum: %s, already used in this module.\n", RKString_GetString(RKList_GetData(node))) ;
                
                exit(EXIT_FAILURE) ;
            }
            
            RKStore_AddItem(module->enums, type, RKString_GetString(RKList_GetData(node))) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
}

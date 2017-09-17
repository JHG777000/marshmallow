/*
 Copyright (c) 2017 Jacob Gordon. All rights reserved.
 
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

void marshmallow_parse_type( marshmallow_type type, marshmallow_token token, int pointers, int* arrays, int num_of_arrays ) {
    
    int i = 0 ;
    
    marshmallow_type a = NULL ;
    
    marshmallow_type ptrs = NULL ;
    
    switch (token->keyword) {
            
        case mgk(i8type):
            
            type->root_type = i8 ;
            
            break;
            
        case mgk(u8type):
            
            type->root_type = u8 ;
            
            break;
            
        case mgk(i16type):
            
            type->root_type = i16 ;
            
            break;
            
        case mgk(u16type):
            
            type->root_type = u16 ;
            
            break;
            
        case mgk(i32type):
            
            type->root_type = i32 ;
            
            break;
            
        case mgk(u32type):
            
            type->root_type = u32 ;
            
            break;
            
        case mgk(i64type):
            
            type->root_type = i64 ;
            
            break;
            
        case mgk(u64type):
            
            type->root_type = u64 ;
            
            break;
            
        case mgk(hex):
            
            type->root_type = hex ;
            
            break;
            
        case mgk(string):
            
            type->root_type = string ;
            
            break;
            
        case mgk(floattype):
            
            type->root_type = f32 ;
            
            break;
            
        case mgk(doubletype):
            
            type->root_type = f64 ;
            
            break;
            
        default:
            break;
    }
    
    while (i < pointers) {
        
        ptrs = marshmallow_new_type() ;
        
        ptrs->type_name = (type->type_name == NULL) ? NULL : RKString_CopyString(type->type_name) ;
        
        ptrs->root_type = type->root_type ;
        
        ptrs->base_type = type->base_type ;
        
        RKString_DestroyString(type->type_name) ;
        
        type->type_name = NULL ;
        
        type->root_type = ptr ;
        
        type->base_type = ptrs ;
        
        i++ ;
    }
    
    i = num_of_arrays-1 ;
    
    while (i >= 0) {
        
        if ( arrays[i] > -1 ) {
            
            a = marshmallow_new_type() ;
            
            a->type_name = (type->type_name == NULL) ? NULL : RKString_CopyString(type->type_name) ;
            
            a->root_type = type->root_type ;
            
            a->base_type = type->base_type ;
            
            a->num_of_elements = type->num_of_elements ;
            
            RKString_DestroyString(type->type_name) ;
            
            type->type_name = NULL ;
            
            type->root_type = array ;
            
            type->base_type = a ;
            
            type->num_of_elements = arrays[i] ;
            
        }
        
        i-- ;
    }
    
}

void marshmallow_parse_value( marshmallow_token token, marshmallow_variable variable ) {
    
    marshmallow_value value = RKMem_NewMemOfType(struct marshmallow_value_s) ;
    
    value->type = marshmallow_new_type() ;
    
    marshmallow_parse_type(value->type, token, 0, NULL, 0) ;
    
    value->value = RKString_CopyString(token->value) ;
    
    variable->data = value ;
}

marshmallow_type marshmallow_new_type( void ) {
    
    marshmallow_type type = RKMem_NewMemOfType(struct marshmallow_type_s) ;
    
    type->entity_type = entity_data_type ;
    
    type->base_type = NULL ;
    
    type->root_type = unknown ;
    
    type->type_name = rkstr("unknown") ;
    
    type->num_of_elements = -1 ;
    
    return type ;
}

marshmallow_variable marshmallow_new_variable( void ) {
    
    marshmallow_variable variable = RKMem_NewMemOfType(struct marshmallow_variable_s) ;
    
    variable->entity_type = entity_variable ;
    
    variable->access_control = public ;
    
    variable->name = NULL ;
    
    variable->data = NULL ;
    
    variable->is_declared = 0 ;
    
    variable->is_external = 0 ;
    
    variable->is_hidden = 0 ;
    
    variable->is_overridable = 0 ;
    
    variable->is_override =  0 ;
    
    variable->is_persistent = 0 ;
    
    variable->is_readonly = 0 ;
    
    variable->type = NULL ;
    
    variable->static_assignment = NULL ;
    
    return variable ;
}

void marshmallow_add_variable_to_scope( marshmallow_scope scope, marshmallow_variable variable ) {
    
    if ( RKStore_ItemExists(scope->variables, RKString_GetString(variable->name)) ) {
        
        printf("Variable name: '%s', already used in this scope. \n",RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(scope->variables, variable, RKString_GetString(variable->name)) ;
}

marshmallow_module marshmallow_new_module( RKString name ) {
    
    marshmallow_module module = RKMem_NewMemOfType(struct marshmallow_module_s) ;
    
    module->entity_type = entity_module ;
    
    module->declarations = RKStore_NewStore() ;
    
    module->functions_and_methods = RKStore_NewStore() ;
    
    module->macros = RKStore_NewStore() ;
    
    module->modules = RKStore_NewStore() ;
    
    module->types = RKStore_NewStore() ;
    
    module->variables = RKStore_NewStore() ;
    
    module->name = RKString_CopyString(name) ;
    
    return module ;
}

marshmallow_statement marshmallow_new_statement( marshmallow_op_type op_type, int is_expression, marshmallow_entity a, marshmallow_entity b ) {
    
    marshmallow_statement statement = RKMem_NewMemOfType(struct marshmallow_statement_s) ;
    
    statement->entity_type = entity_statement ;
    
    statement->is_expression = is_expression ;
    
    statement->statements = RKList_NewList() ;
    
    statement->function = NULL ;
    
    statement->op = op_type ;
    
    statement->var_a = a ;
    
    statement->var_b = b ;
    
    return statement ;
}

marshmallow_function_signature marshmallow_new_function_signature( RKString name, int is_method ) {
    
    marshmallow_function_signature signature = RKMem_NewMemOfType(struct marshmallow_function_signature_s) ;
    
    signature->parameters = RKStore_NewStore() ;
    
    signature->class = NULL ;
    
    signature->func_name = RKString_CopyString(name) ;
    
    signature->is_method = is_method ;
    
    signature->returns = RKList_NewList() ;
    
    return signature ;
}

void marshmallow_add_parameter_to_function( marshmallow_function_signature signature, marshmallow_variable parameter, int is_first_parameter ) {
    
    RKStore_AddItem(signature->parameters, parameter, RKString_GetString(parameter->name)) ;
}

void marshmallow_add_return_to_function_return_list( marshmallow_function_signature signature, marshmallow_variable a_return ) {
    
    RKList_AddToList(signature->returns, a_return) ;
}

marshmallow_function_body marshmallow_new_function_body( marshmallow_function_signature signature ) {
    
    marshmallow_function_body function = RKMem_NewMemOfType(struct marshmallow_function_body_s) ;
    
    function->entity_type = entity_function ;
    
    function->signature = signature ;
    
    function->statements = RKList_NewList() ;
    
    function->variables = RKStore_NewStore() ;
    
    return function ;
}

void marshmallow_add_statement_to_function( marshmallow_function_body function, marshmallow_statement statement ) {
    
    statement->function = function ;
    
    if ( function->entity_type == entity_statement ) statement->function = ((marshmallow_statement)function)->function ;
    
    RKList_AddToList(function->statements, statement) ;
}

void marshmallow_add_function_to_module( marshmallow_function_body function, marshmallow_module module ) {
    
    if ( RKStore_ItemExists(module->functions_and_methods, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Function name already used in this module.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(module->functions_and_methods, function, RKString_GetString(function->signature->func_name)) ;
}

void marshmallow_add_function_to_module_declarations( marshmallow_function_body function, marshmallow_module module ) {
    
    if ( RKStore_ItemExists(module->declarations, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Declaration name already used in this module.\n") ;
        
        exit(EXIT_FAILURE) ;
    }

    RKStore_AddItem(module->declarations, function, RKString_GetString(function->signature->func_name)) ;
}

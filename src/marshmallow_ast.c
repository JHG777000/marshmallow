/*
 Copyright (c) 2017-2018 Jacob Gordon. All rights reserved.
 
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
            
        case mgk(oct):
            
            type->root_type = oct ;
            
            break;
            
        case mgk(string):
            
            type->root_type = string ;
            
            break;
            
        case mgk(string8):
            
            type->root_type = string8 ;
            
            break;
            
        case mgk(string16):
            
            type->root_type = string16 ;
            
            break;
            
        case mgk(string32):
            
            type->root_type = string32 ;
            
            break;
            
        case mgk(character):
            
            type->root_type = character ;
            
            break;
            
        case mgk(floattype):
            
            type->root_type = f32 ;
            
            break;
            
        case mgk(doubletype):
            
            type->root_type = f64 ;
            
            break;
            
        case mgk(nullptr):
            
            type->root_type = nulltype ;
            
            pointers++ ;
            
            break;
            
        default:
            
            type->root_type = unknown ;
            
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
    
    variable->type->is_literal = 1 ;
}

marshmallow_type marshmallow_new_type( void ) {
    
    marshmallow_type type = RKMem_NewMemOfType(struct marshmallow_type_s) ;
    
    type->entity_type = entity_data_type ;
    
    type->base_type = NULL ;
    
    type->root_type = unknown ;
    
    type->type_name = rkstr("unknown") ;
    
    type->output_name = NULL ;
    
    type->is_literal = 0 ;
    
    type->is_init = 0 ;
    
    type->is_typedef = 0 ;
    
    type->is_cast = 0 ;
    
    type->is_readonly = 0 ;
    
    type->num_of_elements = -1 ;
    
    type->pointers = 0 ;
    
    return type ;
}

marshmallow_type marshmallow_copy_type( marshmallow_type t ) {
    
    marshmallow_type type = RKMem_NewMemOfType(struct marshmallow_type_s) ;
    
    type->entity_type = entity_data_type ;
    
    type->base_type = t->base_type ;
    
    type->root_type = t->root_type ;
    
    type->type_name = RKString_CopyString(t->type_name) ;
    
    type->output_name = RKString_CopyString(t->output_name) ;
    
    //type->is_init should not need to be copied
    
    type->is_literal = t->is_literal ;
    
    type->is_typedef = t->is_typedef ;
    
    type->is_cast = t->is_cast ;
    
    type->is_readonly = t->is_readonly ;
    
    type->num_of_elements = t->num_of_elements ;
    
    type->pointers = t->pointers ;
    
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
    
    variable->is_global = 0 ;
    
    variable->is_hidden = 0 ;
    
    variable->is_persistent = 0 ;
    
    variable->type = NULL ;
    
    variable->static_assignment = NULL ;
    
    return variable ;
}

void marshmallow_add_variable_to_scope( marshmallow_scope scope, marshmallow_variable variable ) {
    
    marshmallow_module module = (scope->entity_type == entity_module) ? (marshmallow_module)scope : ((marshmallow_function_body)scope)->module ;
    
    if ( RKStore_ItemExists(scope->variables, RKString_GetString(variable->name)) ) {
        
        printf("Variable name: '%s', already used in this scope. \n",RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
        
    if ( RKStore_ItemExists(module->functions_and_methods, RKString_GetString(variable->name)) ) {
            
        printf("Identifier error: '%s', identifier can not be used for a variable and a function or method.\n",RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->declarations, RKString_GetString(variable->name)) ) {
        
        printf("Identifier error: '%s', identifier can not be used for a variable and a declaration.\n",RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->types, RKString_GetString(variable->name)) ) {
        
        printf("Identifier error: '%s', identifier can not be used for a variable and a type.\n",RKString_GetString(variable->name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(scope->variables, variable, RKString_GetString(variable->name)) ;
}

marshmallow_entity marshmallow_lookup_identifier( marshmallow_function_body function, marshmallow_module module, marshmallow_entity identifier) {
    
    marshmallow_entity entity = NULL ;
    
    RKString identifier_name = NULL ;
    
    marshmallow_variable a = NULL ;
    
    if ( identifier->entity_type == entity_function ) {
        
        identifier_name = ((marshmallow_function_body)identifier)->signature->func_name ;
        
        if ( RKStore_ItemExists(module->enums, RKString_GetString(identifier_name)) ) {
        
            if ( RKStore_ItemExists(module->functions_and_methods, RKString_GetString(identifier_name)) ) {
                
                printf("Identifier error: '%s', identifier can not be used for a function or method and an enum.\n",RKString_GetString(identifier_name)) ;
                
                exit(EXIT_FAILURE) ;
            }
            
            printf("Identifier error: '%s', using an enum as a function or method is not allowed.\n",RKString_GetString(identifier_name)) ;
            
            exit(EXIT_FAILURE) ;
        }
        
        entity = RKStore_GetItem(module->functions_and_methods, RKString_GetString(identifier_name)) ;
        
        if ( entity == NULL ) {
            
            entity = RKStore_GetItem(module->declarations, RKString_GetString(identifier_name)) ;
            
            if ( entity != NULL ) if ( entity->entity_type != entity_function ) entity = NULL ;
        }
         
    } else if (identifier->entity_type == entity_variable) {
        
        identifier_name = ((marshmallow_variable)identifier)->name ;
        
        if ( function != NULL ) entity = RKStore_GetItem(function->variables, RKString_GetString(identifier_name)) ;
        
        if ( entity == NULL  ) {
            
            entity = RKStore_GetItem(module->variables, RKString_GetString(identifier_name)) ;
            
            if ( entity != NULL ) ((marshmallow_variable)entity)->is_global = 1 ;
        }
        
        if ( RKStore_ItemExists(module->enums, RKString_GetString(identifier_name)) ) {
            
            a = marshmallow_new_variable() ;
            
            a->name = RKString_CopyString(identifier_name) ;
            
            a->type = RKStore_GetItem(module->enums, RKString_GetString(identifier_name)) ;
            
            if ( function != NULL ) {
                
                if ( RKStore_ItemExists(function->variables, RKString_GetString(identifier_name)) ) {
                    
                    printf("Identifier error: '%s', identifier can not be used for a global or local  variable and an enum.\n",RKString_GetString(identifier_name)) ;
                    
                    exit(EXIT_FAILURE) ;
                }

            }
            
            if ( RKStore_ItemExists(module->variables, RKString_GetString(identifier_name)) ) {
                
                printf("Identifier error: '%s', identifier can not be used for a global or local variable and an enum.\n",RKString_GetString(identifier_name)) ;
                
                exit(EXIT_FAILURE) ;
            }
            
            entity = (marshmallow_entity)a ;
        }

    }
    
    if ( entity == NULL ) {
        
        printf("Identifier: '%s', does not exist.\n",RKString_GetString(identifier_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    return entity ;
}

marshmallow_module marshmallow_new_module( RKString name ) {
    
    marshmallow_module module = RKMem_NewMemOfType(struct marshmallow_module_s) ;
    
    module->entity_type = entity_module ;
    
    module->declarations = RKStore_NewStore() ;
    
    module->functions_and_methods = RKStore_NewStore() ;
    
    module->macros = RKStore_NewStore() ;
    
    module->modules = RKStore_NewStore() ;
    
    module->types = RKStore_NewStore() ;
    
    module->unprocessed_types = RKStore_NewStore() ;
    
    module->enums = RKStore_NewStore() ;
    
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
    
    signature->is_overridable = 0 ;
    
    signature->is_override = 0 ;
    
    signature->is_declared = 0 ;
    
    signature->is_external = 0 ;
    
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
    
    function->calls = RKStore_NewStore() ;
    
    function->module = NULL ;
    
    return function ;
}

static void marshmallow_attach_function_to_all_statements( marshmallow_function_body function, marshmallow_variable a, marshmallow_variable b ) {
    
    marshmallow_statement statement = NULL ;
    
    if ( a != NULL ) if (a->entity_type == entity_variable) if ( a->type->root_type == expression ) {
        
        statement = a->data ;
        
        statement->function = function ;
        
        marshmallow_attach_function_to_all_statements(function, (marshmallow_variable)statement->var_a, (marshmallow_variable)statement->var_b) ;
    }
    
    if ( b != NULL ) if (b->entity_type == entity_variable) if ( b->type->root_type == expression ) {
        
        statement = b->data ;
        
        statement->function = function ;
        
        marshmallow_attach_function_to_all_statements(function, (marshmallow_variable)statement->var_a, (marshmallow_variable)statement->var_b) ;
    }
}

 void marshmallow_attach_function_to_statement( marshmallow_function_body function, marshmallow_statement statement ) {
    
    statement->function = function ;
    
    marshmallow_attach_function_to_all_statements(function, (marshmallow_variable)statement->var_a, (marshmallow_variable)statement->var_b) ;
}

void marshmallow_add_statement_to_function( marshmallow_function_body function, marshmallow_statement statement ) {
    
    marshmallow_function_body f = function ;
    
loop:
    
    if ( f->entity_type == entity_statement ) {
        
        f = ((marshmallow_statement)f)->function ;
        
        goto loop ;
    }
    
    marshmallow_attach_function_to_statement(f, statement) ;
    
    RKList_AddToList(function->statements, statement) ;
}

void marshmallow_add_function_to_module( marshmallow_function_body function, marshmallow_module module ) {
    
    if ( RKStore_ItemExists(module->functions_and_methods, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Function name: %s, already used in this module.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->types, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Function name: %s, already used in this module as a type.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->variables, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Function name: %s, already used in this module as a global variable.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    RKStore_AddItem(module->functions_and_methods, function, RKString_GetString(function->signature->func_name)) ;
    
    function->module = module ;
}

void marshmallow_add_function_to_module_declarations( marshmallow_function_body function, marshmallow_module module ) {
    
    if ( RKStore_ItemExists(module->declarations, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Declaration name: %s, already used in this module.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->types, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Declaration name: %s, already used in this module as a type.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->variables, RKString_GetString(function->signature->func_name)) ) {
        
        printf("Declaration name: %s, already used in this module as a global variable.\n", RKString_GetString(function->signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }

    RKStore_AddItem(module->declarations, function, RKString_GetString(function->signature->func_name)) ;
}

void marshmallow_add_enums_to_module( marshmallow_type type, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( type->root_type != enum_type ) return ;
    
    list = ((marshmallow_enum)type->base_type)->enum_names ;
    
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

void marshmallow_add_typedef_to_module( marshmallow_type type, marshmallow_module module ) {
    
    if ( RKStore_ItemExists(module->types, RKString_GetString(type->type_name) ) ) {
        
        printf("Type name: %s, already used in this module. Can not redefine types.\n", RKString_GetString(type->type_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->variables, RKString_GetString(type->type_name) ) ) {
        
        printf("Type name: %s, already used in this module as a global variable.\n", RKString_GetString(type->type_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->functions_and_methods, RKString_GetString(type->type_name) ) ) {
        
        printf("Type name: %s, already used in this module as a functions or method.\n", RKString_GetString(type->type_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( RKStore_ItemExists(module->declarations, RKString_GetString(type->type_name) ) ) {
        
        printf("Type name: %s, already used in this module as a declaration.\n", RKString_GetString(type->type_name)) ;
        
        exit(EXIT_FAILURE) ;
    }

    
    RKStore_AddItem(module->types, type, RKString_GetString(type->type_name)) ;
}

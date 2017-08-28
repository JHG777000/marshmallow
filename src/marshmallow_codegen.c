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


static void output_symbol( marshmallow_context context, FILE* file, RKString name, marshmallow_module module, int is_global ) {
    
    RKString underscore = rkstr("_") ;
    
    RKString str0 = RKString_AppendString(rkstr("marshmallow_"), module->name) ;
    
    RKString str1  = RKString_AppendString(str0, underscore) ;
    
    RKString str2 = RKString_AppendString(str1, name) ;
    
    if ( RKStore_ItemExists(context->symbols, RKString_GetString(str2)) && is_global ) {
        
        if ( name != RKStore_GetItem(context->symbols, RKString_GetString(str2)) ) {
            
            printf("Error: symbol '%s', already exists.\n",RKString_GetString(str2)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
    }
    
    fprintf(file, "%s", RKString_GetString(str2)) ;
    
    if ( is_global ) RKStore_AddItem(context->symbols, name, RKString_GetString(str2)) ;
    
    RKString_DestroyString(underscore) ;
}

static void output_type( marshmallow_context context, FILE* file, marshmallow_type type, marshmallow_module module ) {
    
    marshmallow_type t = type ;
    
loop:
    
    if ( (t->root_type == ptr) || (t->root_type == array)  ) t = t->base_type ;
    
    if ( (t->root_type == ptr) || (t->root_type == array) ) goto loop ;
    
    if ( t->root_type != unknown ) {
        
        switch (t->root_type) {
                
            case u64:
                
                fprintf(file, "MULong ") ;
                
                break;
                
            default:
                break;
        }
        
        
    } else {
        
        output_symbol(context, file, t->type_name, module, 1) ;
        
        fprintf(file, " ") ;
    }
    
    if ( (type->root_type == ptr) || (type->root_type == array) ) {
        
        t = type ;
    loop2:
        if ( (t->root_type == ptr) || (t->root_type == array) ) {
            
            if (t->root_type == ptr) fprintf(file,"*") ;
            
            t = t->base_type ;
            
            goto loop2 ;
        }
    }
}

static void output_array( marshmallow_context context, FILE* file, marshmallow_type type, marshmallow_module module ) {
    
    marshmallow_type t = type ;
loop:
    if ( t->root_type == array ) {
        
        fprintf(file,"[") ;
        
        if ( t->num_of_elements > 0 ) fprintf(file, "%d", t->num_of_elements) ;
        
        fprintf(file,"]") ;
        
        t = t->base_type ;
        
        goto loop ;
    }
}

static void output_variable( marshmallow_context context, FILE* file, marshmallow_variable variable, marshmallow_module module, int is_global, int no_default ) {
    
    output_type(context, file, variable->type, module) ;
    
    output_symbol(context, file, RKString_AppendString(rkstr("variable_"),variable->name), module, is_global) ;
    
    output_array(context, file, variable->type, module) ;
    
    if ( variable->static_assignment != NULL && !no_default) {
        
        fprintf(file, " ") ;
        
        fprintf(file, "=") ;
        
        fprintf(file, " ") ;
        
        fprintf(file, "%s",RKString_GetString(((marshmallow_value)variable->static_assignment->data)->value)) ;
    }
}

static void output_statement( marshmallow_context context, FILE* file, marshmallow_statement statement, marshmallow_module module ) ;

static void output_value(marshmallow_context context, FILE* file, marshmallow_variable value, marshmallow_module module) {
    
    if ( value == NULL ) return ;
    
    if ( value->type->root_type != unknown && value->type->root_type != array && value->type->root_type != arguments
        && value->type->root_type != expression && value->data != NULL ) {
        
        fprintf(file, "%s", RKString_GetString(((marshmallow_value)value->data)->value)) ;
        
    }
    
    if ( value->type->root_type == expression ) {
        
        output_statement(context, file, value->data, module) ;
        
    }
    
    if ( value->type->root_type == unknown && value->name != NULL ) {
        
        output_symbol(context, file, RKString_AppendString(rkstr("variable_"),value->name), module, 0) ;
    }
    
}

static void output_arguments( marshmallow_context context, FILE* file, marshmallow_variable args, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( args->type->root_type == arguments ) {
        
        list = args->data ;
        
        if ( list != NULL ) {
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_value(context, file, RKList_GetData(node), module) ;
                
                if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
                
                node = RKList_GetNextNode(node) ;
            }
        }
    }
}

static void output_statement( marshmallow_context context, FILE* file, marshmallow_statement statement, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( statement->entity_type == entity_variable ) {
        
        output_value(context, file, (marshmallow_variable)statement, module) ;
    }
    
    if ( statement->is_expression ) fprintf(file, "(") ;
    
    switch ( statement->op ) {
            
        case ifop:
            
            fprintf(file,"if (") ;
            
            output_value(context, file, ((marshmallow_variable)statement->var_a)->data, module) ;
            
            fprintf(file,") {\n") ;
            
            list = statement->statements ;
            
            if ( list != NULL ) {
                
                node = RKList_GetFirstNode(list) ;
                
                while (node != NULL) {
                    
                    output_statement(context, file, RKList_GetData(node), module) ;
                    
                    fprintf(file, " ") ;
                    
                    fprintf(file, " ;\n") ;
                    
                    node = RKList_GetNextNode(node) ;
                }
            }
            
            fprintf(file,"}") ;
            
            break;
            
        case call:
            
            fprintf(file, "%s",RKString_GetString(((RKString)((marshmallow_function_body)statement->var_a)->signature->func_name))) ;
            
            fprintf(file, "(") ;
            
            fprintf(file, "\"") ;
            
            output_arguments(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            fprintf(file, "\"") ;
            
            fprintf(file, ")") ;
            
            fprintf(file, ";") ;
            
            break;
            
        case add:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "+") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case assignment:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "=") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        default:
            break;
    }
    
    if ( statement->is_expression ) fprintf(file, ")") ;
}

static void output_signature( marshmallow_context context, FILE* file, marshmallow_function_signature signature, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    fprintf(file, "void") ;
    
    fprintf(file, " ") ;
    
    if ( !signature->is_external ) {
        
        output_symbol(context, file, RKString_AppendString(rkstr("function_"), signature->func_name), module, 0) ;
        
    } else {
        
        fprintf(file, "%s", RKString_GetString(signature->func_name)) ;
        
    }
    
    fprintf(file, "(") ;
    
    list = RKStore_GetList(signature->parameters) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            output_variable(context, file, RKList_GetData(node), module, 0, 1) ;
            
            if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
}

static void output_declarations( marshmallow_context context, FILE* file, RKStore declarations, marshmallow_module module, int is_module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    marshmallow_entity entity = NULL ;
    
    list = RKStore_GetList(declarations) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            entity = RKList_GetData(node) ;
            
            if ( entity->entity_type == entity_variable ) {
                
                output_variable(context, file, RKList_GetData(node), module, 0, 1) ;
                
            } else if ( entity->entity_type == entity_function ) {
                
                output_signature(context, file, ((marshmallow_function_body)entity)->signature, module) ;
                
                fprintf(file, ")") ;
            }
            
            fprintf(file, " ;\n") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
    if ( is_module ) {
        
        list = RKStore_GetList(module->functions_and_methods) ;
        
        if ( list != NULL ) {
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_signature(context, file, ((marshmallow_function_body)RKList_GetData(node))->signature, module) ;
                
                fprintf(file, ")") ;
                
                fprintf(file, " ") ;
                
                fprintf(file, " ;\n") ;
                
                node = RKList_GetNextNode(node) ;
                
            }
        }
    }
    
}

static void output_function( marshmallow_context context, FILE* file, marshmallow_function_body function, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    output_signature(context, file, function->signature, module) ;
    
    fprintf(file, ")") ;
    
    fprintf(file, " ") ;
    
    fprintf(file, "{") ;
    
    fprintf(file, "\n") ;
    
    list = RKStore_GetList(function->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            output_variable(context, file, RKList_GetData(node), module, 0, 0) ;
            
            fprintf(file, " ;\n") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
    list = function->statements ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            output_statement(context, file, RKList_GetData(node), module) ;
            
            fprintf(file, " ") ;
            
            fprintf(file, " ;\n") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
    fprintf(file, "}") ;
    
    fprintf(file, "\n") ;
}

static void output_main( marshmallow_context context, FILE* file, marshmallow_module module ) {
    
    static int init = 0 ;
    
    if ( init ) return ;
    
    if ( !init ) init++ ;
    
    fprintf(file, "int main(int argc, const char **argv) {\n") ;
    
    output_symbol(context, file, RKString_AppendString(rkstr("function_"), rkstr("main")), module, 0) ;
    
    fprintf(file, "() ;\n") ;
    
    fprintf(file, "return 0 ; \n") ;
    
    fprintf(file, "} \n") ;
    
}

static void output_module( marshmallow_context context, FILE* file, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    output_declarations(context, file, module->declarations, module, 1) ;
    
    list = RKStore_GetList(module->variables) ;
    
    if ( list == NULL ) return ;
    
    output_main(context, file, module) ;
    
    node = RKList_GetFirstNode(list) ;
    
    while (node != NULL) {
        
        output_variable(context, file, RKList_GetData(node), module, 1, 0) ;
        
        fprintf(file, " ;\n") ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
    list = RKStore_GetList(module->functions_and_methods) ;
    
    if ( list == NULL ) return ;
    
    node = RKList_GetFirstNode(list) ;
    
    while (node != NULL) {
        
        output_function(context, file, RKList_GetData(node), module) ;
        
        node = RKList_GetNextNode(node) ;
        
    }
    
}

static void output_runtime( marshmallow_context context, FILE* file ) {
    
    fprintf(file, "typedef float MFloat ;\n") ;
    
    fprintf(file, "typedef double MDouble ;\n") ;
    
    fprintf(file, "typedef unsigned char MByte ;\n") ;
    
    fprintf(file, "typedef signed char MSByte ;\n") ;
    
    fprintf(file, "typedef signed short MShort ;\n") ;
    
    fprintf(file, "typedef unsigned short MUShort ;\n") ;
    
    fprintf(file, "typedef signed int MInt ;\n") ;
    
    fprintf(file, "typedef unsigned int MUInt ;\n") ;
    
    fprintf(file, "#ifdef _WIN32\n") ;
    
    fprintf(file, "typedef signed long long MLong ;\n") ;
    
    fprintf(file, "typedef unsigned long long MULong ;\n") ;
    
    fprintf(file, "#else\n") ;
    
    fprintf(file, "typedef signed long MLong ;\n") ;
    
    fprintf(file, "typedef unsigned long MULong ;\n") ;
    
    fprintf(file, "#endif\n") ;
    
    fprintf(file, "\n") ;
}

static void output_app( marshmallow_context context, FILE* file ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(context->modules) ;
    
    if ( list == NULL ) return ;
    
    node = RKList_GetFirstNode(list) ;
    
    output_runtime(context, file) ;
    
    while (node != NULL) {
        
        output_module(context, file, RKList_GetData(node)) ;
        
        node = RKList_GetNextNode(node) ;
    }
}

void marshmallow_codegen( marshmallow_context context, FILE* out_file ) {
    
    output_app(context, out_file) ;
}

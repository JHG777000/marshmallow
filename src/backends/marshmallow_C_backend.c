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

typedef struct c_backend_s { RKStore definitions ; RKStore banned_symbols ; } *c_backend ;

static void validate_definition( cg_routine routine, cg_variable variable, c_backend c ) {
    
    void* definition = NULL ;
    
    RKString definition_name = NULL ;
    
    if ( routine != NULL && variable == NULL ) {
        
        definition = routine ;
        
        definition_name = routine->name ;
        
        mlb_validate_routine(definition) ;
        
    } else if (routine == NULL && variable != NULL) {
        
        definition = variable ;
        
        definition_name = variable->name ;
        
        mlb_validate_variable(definition) ;
        
    } else if (routine == NULL && variable == NULL) {
        
        return ;
    }
    
    if ( RKStore_ItemExists(c->definitions, RKString_GetString(definition_name)) ) {
        
        cg_variable v = RKStore_GetItem(c->definitions, RKString_GetString(definition_name)) ;
        
        cg_routine r = (cg_routine)v ;
        
        if ( v->entity_type != ((cg_variable)definition)->entity_type) goto error ;
        
        if ( v->entity_type == cg_entity_variable ) {
         
            if ( !cg_variables_are_equal(v, definition) ) goto error ;
            
        }
        
        if ( v->entity_type == cg_entity_routine) {
            
            if ( r->is_global != ((cg_routine)definition)->is_global ) goto error ;
            
            if ( r->is_external != ((cg_routine)definition)->is_external ) goto error ;
            
            if ( RKList_GetNumOfNodes(RKStore_GetList(r->parameters)) != RKList_GetNumOfNodes(RKStore_GetList(((cg_routine)definition)->parameters))) goto error ;
            
            if ( RKList_GetNumOfNodes(r->return_types) != RKList_GetNumOfNodes(((cg_routine)definition)->return_types) ) goto error ;
            
            RKList_node node = RKList_GetFirstNode(RKStore_GetList(r->parameters)) ;
            
            RKList_node node2 = NULL ;
            
            while (node != NULL) {
                
             if ( !cg_variables_are_equal(RKList_GetData(node),RKStore_GetItem(((cg_routine)definition)->parameters,RKString_GetString(RKStore_GetStoreLabelFromListNode(node))))) goto error ;
                
            node = RKList_GetNextNode(node) ;
                
            }
            
            node = RKList_GetFirstNode(r->return_types) ;
            
            node2 = RKList_GetFirstNode(((cg_routine)definition)->return_types) ;
            
            while (node != NULL ) {
                
                if ( !cg_variables_are_equal(RKList_GetData(node),RKList_GetData(node2)) ) goto error ;
                
                node = RKList_GetNextNode(node) ;
            }
            
        }
        
        return ;
        
    error:
        
        printf("codegen error: definition '%s', already exists.\n",RKString_GetString(definition_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
}


static void* get_static_assignment( cg_variable variable ) {
    
    if ( !variable->is_literal ) {
        
        if ( variable->type == array && variable->values != NULL ) return variable->values ;
        
        if ( variable->type == class && variable->class_values != NULL ) return variable->class_values ;
        
        if ( variable->type != array && variable->type != class && variable->value != NULL ) return variable->value ;
    }
    
    return NULL ;
}

return_pointer_size(C) {
    
    return 8 ;
}

static void output_declarations( FILE* file, RKStore declarations, c_backend c ) ;

static void output_value( FILE* file, cg_variable value, void* static_assignment ) ;

static void output_collection( FILE* file, cg_variable variable ) ;

static void output_type( FILE* file, cg_variable type, void* static_assignment ) ;

static void output_symbol( FILE* file, cg_variable variable, c_backend c ) ;

static void output_array( FILE* file, cg_variable type, void* static_assignment ) ;

static void output_variable_definition( FILE* file, cg_variable variable, c_backend c ) ;

static void output_signature( FILE* file, cg_routine routine, c_backend c ) ;

static void output_declarations( FILE* file, RKStore declarations, c_backend c ) ;

static void output_runtime( FILE* file ) ;


static void output_value( FILE* file, cg_variable value, void* static_assignment ) {
    
    if ( value == NULL ) return ;
    
    if ( value->type == string ) fprintf(file, "u8\"") ;
    
    if ( value->type == string8 && value->is_literal ) fprintf(file, "u8\"") ;
    
    if ( value->type == string16 && value->is_literal ) fprintf(file, "u\"") ;
    
    if ( value->type == string32 && value->is_literal ) fprintf(file, "U\"") ;
    
    if ( value->type == character ) fprintf(file, "L\'") ;
    
    if ( !value->is_literal && value->name != NULL && static_assignment == NULL ) {
        
        fprintf(file, "%s", RKString_GetString(value->name)) ;
        
        return ;
    }
    
    if ( value->values != NULL ) {
        
        output_collection( file, value) ;
        
        return ;
    }
    
    if ( value->value != NULL ) {
        
        fprintf(file, "%s", RKString_GetString(value->value)) ;
    }
    
    if ( value->type == string ) fprintf(file, "\"") ;
    
    if ( value->type == string8 && value->is_literal ) fprintf(file, "\"") ;
    
    if ( value->type == string16 && value->is_literal ) fprintf(file, "\"") ;
    
    if ( value->type == string32 && value->is_literal ) fprintf(file, "\"") ;
    
    if ( value->type == character ) fprintf(file, "\'") ;
}

static void output_collection( FILE* file, cg_variable variable ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( variable->values != NULL ) {
        
        list = variable->values ;
        
        if ( list != NULL ) {
            
            fprintf(file, "{") ;
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_value(file, RKList_GetData(node), NULL) ;
                
                if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
                
                node = RKList_GetNextNode(node) ;
            }
            
            fprintf(file, "}") ;
            
        }
        
    }
    
}

static void output_type( FILE* file, cg_variable type, void* static_assignment ) {
    
    cg_variable t = type ;
    
loop:
    
    if ( (t->type == ptr) || (t->type == array)  ) t = t->ptr ;
    
    if ( (t->type == ptr) || (t->type == array) ) goto loop ;
        
        switch (t->type) {
                
            case u8:
                
                fprintf(file, "_mu8 ") ;
                
                break;
                
            case i8:
                
                fprintf(file, "_mi8 ") ;
                
                break;
                
            case u16:
                
                fprintf(file, "_mu16 ") ;
                
                break;
                
            case i16:
                
                fprintf(file, "_mi16 ") ;
                
                break;
                
            case u32:
                
                fprintf(file, "_mu32 ") ;
                
                break;
                
            case enum_type:
                
                fprintf(file, "_mu32 ") ;
                
                break;
                
            case string8:
                
                fprintf(file, "_mu8* ") ;
                
                break;
                
            case string16:
                
                fprintf(file, "_mu16* ") ;
                
                break;
                
                
            case string32:
                
                fprintf(file, "_mu32* ") ;
                
                break;
                
                
            case i32:
                
                fprintf(file, "_mi32 ") ;
                
                break;
                
            case u64:
                
                fprintf(file, "_mu64 ") ;
                
                break;
                
            case i64:
                
                fprintf(file, "_mi64 ") ;
                
                break;
                
            case f32:
                
                fprintf(file, "_mf32 ") ;
                
                break;
                
            case f64:
                
                fprintf(file, "_mf64 ") ;
                
                break;
                
            default:
                break;
        }
    
    if ( (type->type == ptr) || (type->type == array) ) {
        
        t = type ;
        
    loop2:
        
        if ( (t->type == ptr) || (t->type == array) ) {
            
            if (t->type == ptr) fprintf(file,"*") ;
            
            if (t->type == array && t->num_of_elements == 0 && static_assignment == NULL ) fprintf(file,"*") ;
            
            t = t->ptr ;
            
            goto loop2 ;
        }
    }
}

static void output_variable_name( FILE* file, cg_variable variable, c_backend c ) {
    
    RKString name = variable->name ;
    
    if ( variable->is_global ) {
        
        fprintf(file, "%s", RKString_GetString(name)) ;
        
        return ;
    }
    
    if ( RKStore_ItemExists(c->banned_symbols, RKString_GetString(name)) ) {
        
        printf("codegen error: symbol '%s', already exists.\n",RKString_GetString(name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    fprintf(file, "%s", RKString_GetString(name)) ;
}

static void output_array( FILE* file, cg_variable type, void* static_assignment ) {
    
    cg_variable t = type ;
    
loop:
    
    if ( t->type == array ) {
        
        if ( static_assignment == NULL && t->num_of_elements != 0 ) fprintf(file,"[") ;
        
        if ( static_assignment != NULL && t->num_of_elements != 0 ) fprintf(file,"[") ;
        
#ifdef _WIN32
        
        if ( t->num_of_elements > 0 ) fprintf(file, "%llu", t->num_of_elements) ;
        
#else
        
        if ( t->num_of_elements > 0 ) fprintf(file, "%lu", t->num_of_elements) ;
        
#endif

        if ( static_assignment == NULL && t->num_of_elements != 0 ) fprintf(file,"]") ;
        
        if ( static_assignment != NULL ) fprintf(file,"]") ;
        
        t = t->ptr ;
        
        goto loop ;
    }
}

static void output_variable_definition( FILE* file, cg_variable variable, c_backend c ) {
    
    output_type(file, variable, get_static_assignment(variable)) ;
    
    output_variable_name(file, variable, c) ;
    
    output_array(file, variable, get_static_assignment(variable)) ;
    
    if ( get_static_assignment(variable) != NULL ) {
        
        fprintf(file, " ") ;
        
        fprintf(file, "=") ;
        
        fprintf(file, " ") ;
        
        output_value(file, variable, get_static_assignment(variable)) ;
    }
}

static RKString get_struct_name_for_routines_returns( RKString routine_name ) {
    
    RKString string = rkstr("_returns") ;
    
    RKString returns_type_name = RKString_AppendString(RKString_CopyString(routine_name), string) ;
    
    RKString_DestroyString(string) ;
    
    return returns_type_name ;
}

static RKString get_routines_returns_name_from_index( RKInt index ) {
    
    char string[100] ;
    
    marshmallow_itoa(index, string) ;
    
    RKString string_index =  RKString_NewStringFromCString(string) ;
    
    RKString returns_index = RKString_AppendString(rkstr("_returns_"),string_index) ;
    
    RKString_DestroyString(string_index) ;
    
    return returns_index ;
}

static void output_signature( FILE* file, cg_routine routine, c_backend c ) {
    
    int i = 0 ;
    
    RKList_node node = NULL ;
    
    RKString returns_index = NULL ;
    
    RKString returns_type_name = get_struct_name_for_routines_returns(routine->name) ;
    
    if ( !routine->is_external ) {
        
         fprintf(file, "struct _") ;
        
         fprintf(file, "%s",RKString_GetString(returns_type_name)) ;
        
         fprintf(file, "{") ;
        
         node = RKList_GetFirstNode(routine->return_types) ;
        
        while ( node != NULL ) {
            
            output_type(file, RKList_GetData(node), NULL) ;
            
            fprintf(file, " ") ;
            
            returns_index = get_routines_returns_name_from_index(i) ;
            
            fprintf(file, " %s",RKString_GetString(returns_index)) ;
            
            RKString_DestroyString(returns_index) ;
            
            fprintf(file, ";") ;
            
            node = RKList_GetNextNode(node) ;
            
            i++ ;
        }
        
         fprintf(file, "} ;\n") ;
        
         fprintf(file, "void") ;
    }
    
    if ( routine->is_external ) {
        
        if ( RKList_GetNumOfNodes(routine->return_types) == 0 ) {
            
            fprintf(file, "void") ;
            
        } else if ( RKList_GetNumOfNodes(routine->return_types) == 1 ) {
            
            output_type(file, RKList_GetData(RKList_GetFirstNode(routine->return_types)), NULL) ;
            
        } else if ( RKList_GetNumOfNodes(routine->return_types) > 1 ) {
            
            printf("codegen error: external routine '%s', can only have one return.\n",RKString_GetString(routine->name)) ;
            
            exit(EXIT_FAILURE) ;
        }
        
    }
    
    fprintf(file, " ") ;
    
    fprintf(file, "%s",RKString_GetString(routine->name)) ;
    
    fprintf(file, "(") ;
    
    if ( !routine->is_external ) {
        
        fprintf(file, "struct _") ;
        
        fprintf(file, "%s",RKString_GetString(returns_type_name)) ;
        
        fprintf(file, " _returns") ;
        
        if ( RKStore_GetNumOfItems(routine->parameters) > 0 ) fprintf(file, ",") ;
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(routine->parameters)) ;
    
    while ( node != NULL ) {
        
        output_variable_definition(file, RKList_GetData(node), c) ;
        
        if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
        
        node = RKList_GetNextNode(node) ;
    }
    
    fprintf(file, ")") ;
    
    RKString_DestroyString(returns_type_name) ;
}

static void output_declarations( FILE* file, RKStore declarations, c_backend c ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    cg_variable entity = NULL ;
    
    list = RKStore_GetList(declarations) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            entity = RKList_GetData(node) ;
            
            if ( entity->entity_type == cg_entity_variable ) {
                
                fprintf(file, "extern ") ;
                
                output_variable_definition(file, RKList_GetData(node), c) ;
                
            } else if ( entity->entity_type == cg_entity_routine ) {
                
                output_signature(file, RKList_GetData(node), c) ;
                
            }
            
            fprintf(file, " ;\n") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
}

static void output_runtime( FILE* file ) {
    
    fprintf(file, "typedef float _mf32 ;\n") ;

    fprintf(file, "typedef double _mf64 ;\n") ;
    
    fprintf(file, "typedef unsigned char _mu8 ;\n") ;
    
    fprintf(file, "typedef signed char _mi8 ;\n") ;
    
    fprintf(file, "typedef signed short _mi16 ;\n") ;
    
    fprintf(file, "typedef unsigned short _mu16 ;\n") ;
    
    fprintf(file, "typedef signed int _mi32 ;\n") ;
    
    fprintf(file, "typedef unsigned int _mu32 ;\n") ;
    
    fprintf(file, "#ifdef _WIN32\n") ;
    
    fprintf(file, "typedef signed long long _mi64 ;\n") ;
    
    fprintf(file, "typedef unsigned long long _mu64 ;\n") ;
    
    fprintf(file, "#else\n") ;
    
    fprintf(file, "typedef signed long _mi64 ;\n") ;
    
    fprintf(file, "typedef unsigned long _mu64 ;\n") ;
    
    fprintf(file, "#endif\n") ;
    
    fprintf(file, "\n") ;
}

static void output_module( FILE* file, cg_context context,  c_backend c, cg_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    output_declarations(file, module->variable_declarations, c) ;
    
    output_declarations(file, module->routine_declarations, c) ;
    
    list = RKStore_GetList(module->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            //output_variable(context, file, RKList_GetData(node), module, 1, 0) ;
            
            fprintf(file, " ;\n") ;
            
            node = RKList_GetNextNode(node) ;
            
        }
        
    }
    
    //list = RKStore_GetList(module->functions_and_methods) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            //output_function(context, file, RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
            
        }
        
    }
}

static void output_app( FILE* file, cg_context context, c_backend c ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(context->modules) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        output_runtime(file) ;
        
        while (node != NULL) {
            
            output_module(file, context, c, RKList_GetData(node)) ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
}

get_context(C) {
    
    output_app(backend->output_file, context, backend->backend_ptr) ;
}

get_builder(C) {
    
    
}

static void DeleteRoutineInListOrStore(void* data) {
    
    cg_destroy_routine(data) ;
}

get_destroyer(C) {
    
    RKStore_IterateStoreWith(DeleteRoutineInListOrStore, ((c_backend)backend->backend_ptr)->definitions) ;
    
    RKStore_DestroyStore(((c_backend)backend->backend_ptr)->definitions) ;
    
    free(backend->backend_ptr) ;
}

new_backend(C) {
    
    backend->size_callback = get_callback(C,return_pointer_size) ;
    
    backend->context_callback = get_callback(C,get_context) ;
    
    backend->builder_callback = get_callback(C,get_builder) ;
    
    backend->destroyer_callback = get_callback(C, get_destroyer) ;
    
    c_backend c = RKMem_NewMemOfType(struct c_backend_s) ;
    
    c->definitions = RKStore_NewStore() ;
    
    c->banned_symbols = RKStore_NewStore() ;
    
    backend->backend_ptr = c ;
    
    cg_routine memcpy_routine = cg_new_routine(rkstr("memcpy"), 1) ;
    
    cg_variable dest = cg_new_variable(rkstr("dest"), ptr, -1, -1, 0, 0) ;
    
    dest->ptr = cg_new_variable(rkstr(""), blank, -1, -1, 0, 0) ;
    
    cg_variable src = cg_new_variable(rkstr("src"), ptr, -1, -1, 0, 0) ;
    
    src->ptr = cg_new_variable(rkstr(""), blank, -1, -1, 0, 0) ;
    
    cg_variable n = cg_new_variable(rkstr("n"), pointer, -1, -1, 0, 0) ;
    
    cg_add_parameter_to_routine(dest, memcpy_routine) ;
    
    cg_add_parameter_to_routine(src, memcpy_routine) ;
    
    cg_add_parameter_to_routine(n, memcpy_routine) ;
    
    mlb_validate_routine(memcpy_routine) ;
    
    validate_definition(memcpy_routine,NULL,c) ;
    
    RKStore_AddItem(c->banned_symbols, rkstr("memcpy"), "memcpy") ;
}

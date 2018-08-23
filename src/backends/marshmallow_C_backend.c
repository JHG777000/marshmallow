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

typedef struct c_backend_s { RKStore definitions ; } *c_backend ;

static void validate_definition( int add, cg_routine routine, cg_variable variable, c_backend c ) {
    
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
        
        if ( v->cgtype != ((cg_variable)definition)->cgtype) goto error ;
        
        if ( v->cgtype == cg_variable_type ) {
         
            if ( !cg_variables_are_equal(v, definition) ) goto error ;
            
        }
        
        if ( v->cgtype == cg_routine_type ) {
            
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
    
    if (add) RKStore_AddItem(c->definitions, definition, RKString_GetString(definition_name)) ;
}

return_pointer_size(C) {
    
    return 8 ;
}

static void output_type( marshmallow_context context, FILE* file, marshmallow_type type, marshmallow_variable static_assignment, marshmallow_module module ) {
    
    marshmallow_type t = type ;
    
loop:
    
    if ( (t->root_type == ptr) || (t->root_type == array)  ) t = t->base_type ;
    
    if ( (t->root_type == ptr) || (t->root_type == array) ) goto loop ;
    
    if ( t->root_type != unknown ) {
        
        switch (t->root_type) {
                
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
        
        
    }
    
    if ( (type->root_type == ptr) || (type->root_type == array) ) {
        
        t = type ;
    loop2:
        if ( (t->root_type == ptr) || (t->root_type == array) ) {
            
            if (t->root_type == ptr) fprintf(file,"*") ;
            
            if (t->root_type == array && t->num_of_elements == 0 && static_assignment == NULL ) fprintf(file,"*") ;
            
            t = t->base_type ;
            
            goto loop2 ;
        }
    }
}

static void output_runtime( marshmallow_context context, FILE* file ) {
    
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


get_context(C) {
    
    
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
    
    validate_definition(1,memcpy_routine,NULL,c) ;
}

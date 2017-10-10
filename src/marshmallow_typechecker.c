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

static int typecheck_are_types_equal( marshmallow_type t1, marshmallow_type t2 ) {
    
    marshmallow_type t = NULL ;
    
    marshmallow_type t0 = NULL ;
    
    if ( t1->root_type != t2->root_type ) return 0 ;
    
    if ( t1->type_name != NULL && t2->type_name == NULL ) return 0 ;
    
    if ( t1->type_name == NULL && t2->type_name != NULL ) return 0 ;
    
    if ( t1->type_name == NULL && t2->type_name == NULL ) {
        
        if ( !RKString_AreStringsEqual(t1->type_name, t2->type_name) ) return 0 ;
    }
    
    if ( t1->root_type != ptr && t1->root_type != array ) return 1 ;
    
    if ( t1->root_type == array ) {
        
        t = t1 ;
        
        t0 = t2 ;
        
    loop:
        
        if ( t->num_of_elements != t0->num_of_elements ) return 0 ;
        
        t = t1->base_type ;
        
        t0 = t2->base_type ;
        
        if ( t->root_type == array && t0->root_type == array ) goto loop ;
        
        if ( t->root_type != t0->root_type ) return 0 ;
    }
    
    if ( t1->root_type == ptr ) {
       
        t = t1 ;
        
        t0 = t2 ;
        
    loop2:
        
        t = t->base_type ;
        
        t0 = t0->base_type ;
        
        if ( t->root_type == ptr && t0->root_type == ptr ) goto loop2 ;
        
        if ( t->root_type == t0->root_type ) return 1 ;
    }
    
    return 0 ;
}

static void typecheck_type( marshmallow_variable variable, marshmallow_module module ) {
    
    marshmallow_type t = variable->type ;
    
    if ( variable->type->root_type == unknown && variable->type->type_name != NULL ) {
        
        variable->type = RKStore_GetItem(module->types, RKString_GetString(variable->type->type_name)) ;
        
         free(t) ;
        
        if ( variable->type == NULL ) {
            
            printf("Type given to variable: '%s', does not exist.\n",RKString_GetString(variable->name)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
    }
}

static void typecheck_variable( marshmallow_variable variable, marshmallow_module module ) {
    
    typecheck_type(variable,module) ;
    
    if ( variable->static_assignment != NULL ) {
    
        if ( variable->static_assignment->type->root_type == hex ) {
            
            variable->static_assignment->type->root_type = u64 ;
        }
        
      if ( !typecheck_are_types_equal(variable->type, variable->static_assignment->type) ) {
        
          printf("variable: '%s', is being statically assigned with a value that is not of its type.\n",RKString_GetString(variable->name)) ;
          
          exit(EXIT_FAILURE) ;
      }
        
    }
}

static void typecheck_function_signature( marshmallow_function_signature signature, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( signature->is_overridable && signature->is_override ) {
        
        printf("Function or method: '%s', is marked as overridable and override, a function or method can not be marked as both overridable and override.\n",RKString_GetString(signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( signature->is_method && signature->class == NULL ) {
        
        printf("Method: '%s', is not associated with a class, a method must be associated with a class.\n",RKString_GetString(signature->func_name)) ;
        
        exit(EXIT_FAILURE) ;
        
    }
    
    list = RKStore_GetList(signature->parameters) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_variable(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
    list = signature->returns ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_variable(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }

}

static void typecheck_declaration( marshmallow_entity declaration, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( declaration->entity_type == entity_function ) {
        
        if ( ((marshmallow_function_body)declaration)->signature->is_external ) {
            
            //external, means no fancy marshmallow types
            
            if ( ((marshmallow_function_body)declaration)->signature->is_overridable ) {
             
                printf("External function or method: '%s', is marked as overridable, an external function or method can not be marked as overridable.\n",RKString_GetString(((marshmallow_function_body)declaration)->signature->func_name)) ;
                
                exit(EXIT_FAILURE) ;
            }
        }
        
        list = RKStore_GetList(((marshmallow_function_body)declaration)->signature->parameters) ;
        
        if ( list != NULL ) {
            
            node = RKList_GetFirstNode(list) ;
            
            while ( node != NULL ) {
                
                if ( ((marshmallow_variable)RKList_GetData(node))->static_assignment != NULL ) {
                    
                    printf("Declared or external function or method parameter: '%s', is being statically assigned, a declared or external function or method parameter can not be statically assigned.\n",RKString_GetString(((marshmallow_variable)RKList_GetData(node))->name)) ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                node = RKList_GetNextNode(node) ;
            }
        }
        
        typecheck_function_signature(((marshmallow_function_body)declaration)->signature, module) ;
        
    } else if ( declaration->entity_type == entity_variable ) {
        
        if ( ((marshmallow_variable)declaration)->is_external ) {
            
            //external, means no fancy marshmallow types
            
        }
        
        if ( ((marshmallow_variable)declaration)->static_assignment != NULL ) {
            
            printf("Declared or external variable: '%s', is being statically assigned, a declared or external variable can not be statically assigned.\n",RKString_GetString(((marshmallow_variable)declaration)->name)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
        
        typecheck_variable((marshmallow_variable)declaration, module) ;
    }
}

static int is_number( marshmallow_type type ) {
    
    switch ( type->root_type ) {
            
        case i8:
            
            return 1 ;
            
            break;
            
        case u8:
            
            return 1 ;
            
            break;
            
        case i16:
            
            return 1 ;
            
            break;
            
        case u16:
            
            return 1 ;
            
            break;
            
        case i32:
            
            return 1 ;
            
            break;
            
        case u32:
            
            return 1 ;
            
            break;
            
            
        case i64:
            
            return 1 ;
            
            break;
            
        case u64:
            
            return 1 ;
            
            break;
            
        case hex:
            
            return 1 ;
            
            break;
            
        case f32:
            
            return 1 ;
            
            break;
            
        case f64:
            
            return 1 ;
            
            break;
            
        default:
            break;
    }
    
    return 0 ;
}

static marshmallow_type typecheck_get_type_from_root_type( marshmallow_root_type root ) {
    
    static marshmallow_type unknown_t = NULL ;
    
    static marshmallow_type i32_t = NULL ;
    
    switch (root) {
            
        case i32:
            
             if ( i32_t == NULL ) i32_t = RKMem_NewMemOfType(struct marshmallow_type_s) ;
            
            i32_t->root_type = i32 ;

            return i32_t ;
            
            break;
            
        default:
            break;
    }
    
    
    if ( unknown_t == NULL ) unknown_t = RKMem_NewMemOfType(struct marshmallow_type_s) ;
    
    unknown_t->root_type = unknown ;

    return unknown_t ;

}

static marshmallow_type typecheck_get_type_promotion( marshmallow_type a, marshmallow_type b ) {
    
    marshmallow_type array[2] ;
    
    array[0] = a ;
    
    array[1] = b ;
    
    int array2[2] ;
    
    array2[0] = 0 ;
    
    array2[1] = 0 ;
    
    int i = 0 ;
    
    int j = 0 ;
loop:
    
    j = 0 ;
    
    switch ( array[i]->root_type ) {
        
        case i8:
            
            j = 1 ;
            
            break;
            
        case u8:
            
            j = 1 ;
            
            break;
            
        case i16:
            
            j = 2 ;
            
            break;
            
        case u16:
            
            j = 2 ;
            
            break;
            
        case i32:
            
            j = 3 ;
            
            break;
            
        case u32:
            
            j = 3 ;
            
            break;
            
            
        case i64:
            
            j = 4 ;
            
            break;
            
        case u64:
            
            j = 4 ;
            
            break;
            
        case hex:
            
            j = 4 ;
            
            break;
            
        case f32:
            
            j = 5 ;
            
            break;
            
        case f64:
            
            j = 6 ;
            
            break;
            
        default:
            break;
    }
    
    array2[i] = j ;
    
    if ( !i ) {
        
        i++ ;
        
        goto loop ;
    }
    
    if ( array2[0] > array2[1] ) return a ;
    
    return b ;
}

static marshmallow_type typecheck_statment( marshmallow_statement statement, int* has_assignment, marshmallow_module module ) {
    
    marshmallow_type rettype_a = NULL ;
    
    marshmallow_type rettype_b = NULL ;
    
     switch ( statement->op ) {
           
        case add:
             
        case sub:
            
            if ( statement->var_a->entity_type == entity_variable ) {
                
                rettype_a = ((marshmallow_variable)statement->var_a)->type ;
                
                if (!is_number(rettype_a)) {
                    
                    printf("Variable: '%s', is wrong type for add.\n",RKString_GetString(((marshmallow_variable)statement->var_a)->name)) ;
                    
                    exit(EXIT_FAILURE) ;
                }
            }
            
            if ( statement->var_a->entity_type == entity_statement ) {
                
                rettype_a = typecheck_statment((marshmallow_statement)statement->var_a, has_assignment, module) ;
                
                if (!is_number(rettype_a)) {
                    
                    printf("Statement is of wrong type for add.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }

            }
            
            if ( statement->var_b->entity_type == entity_variable  ) {
                
                rettype_b = ((marshmallow_variable)statement->var_b)->type ;
                
                if (!is_number(rettype_b)) {
                    
                    printf("Variable: '%s', is wrong type for add.\n",RKString_GetString(((marshmallow_variable)statement->var_b)->name)) ;
                    
                    exit(EXIT_FAILURE) ;
                }
            }
            
            if ( statement->var_b->entity_type == entity_statement ) {
                
                rettype_b = typecheck_statment((marshmallow_statement)statement->var_b, has_assignment, module) ;
                
                if (!is_number(rettype_b)) {
                    
                    printf("Statement is of wrong type for add.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
            }
            
            return typecheck_get_type_from_root_type(typecheck_get_type_promotion(rettype_a, rettype_b)->root_type) ;
            
            break;
            
        default:
            break;
    }
    
    return typecheck_get_type_from_root_type(unknown) ;
}

static void typecheck_module( marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(module->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_variable(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
    list = RKStore_GetList(module->declarations) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_declaration(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }

}

void marshmallow_typecheck( marshmallow_context context ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(context->modules) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            typecheck_module(RKList_GetData(node)) ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }

}

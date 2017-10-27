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

static marshmallow_type typecheck_get_type_from_root_type( marshmallow_root_type root ) {
    
    static marshmallow_type unknown_t = NULL ;
    
    static marshmallow_type i8_t = NULL ;
    
    static marshmallow_type u8_t = NULL ;
    
    static marshmallow_type i16_t = NULL ;
    
    static marshmallow_type u16_t = NULL ;
    
    static marshmallow_type i32_t = NULL ;
    
    static marshmallow_type u32_t = NULL ;
    
    static marshmallow_type i64_t = NULL ;
    
    static marshmallow_type u64_t = NULL ;
    
    static marshmallow_type f32_t = NULL ;
    
    static marshmallow_type f64_t = NULL ;
    
#define get_type_from_root_type(type)\
case type:\
if ( type##_t == NULL ) type##_t = RKMem_NewMemOfType(struct marshmallow_type_s) ;\
type##_t->root_type = type ;\
return type##_t ;\
break;
    
    switch (root) {
            
            get_type_from_root_type(i8)
            
            get_type_from_root_type(u8)
            
            get_type_from_root_type(i16)
            
            get_type_from_root_type(u16)
            
            get_type_from_root_type(i32)
            
            get_type_from_root_type(u32)
            
            get_type_from_root_type(i64)
            
            get_type_from_root_type(u64)
            
            get_type_from_root_type(f32)
            
            get_type_from_root_type(f64)
            
        default:
            break;
    }
    
    if ( unknown_t == NULL ) unknown_t = RKMem_NewMemOfType(struct marshmallow_type_s) ;
    
    unknown_t->root_type = unknown ;
    
    return unknown_t ;
    
}

int m_is_type_float( marshmallow_type type ) {
    
    switch ( type->root_type ) {
            
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

int m_is_type_number( marshmallow_type type ) {
    
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
            
        case character:
            
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

int m_is_size_of_root_type_in_bytes( marshmallow_type type ) {
    
    switch ( type->root_type ) {
            
        case i8:
            
            return 1 ;
            
            break;
            
        case u8:
            
            return 1 ;
            
            break;
            
        case i16:
            
            return 2 ;
            
            break;
            
        case u16:
            
            return 2 ;
            
            break;
            
        case i32:
            
            return 4 ;
            
            break;
            
        case u32:
            
            return 4 ;
            
            break;
            
            
        case i64:
            
            return 8 ;
            
            break;
            
        case u64:
            
            return 8 ;
            
            break;
            
        case hex:
            
            return 8 ;
            
            break;
            
        case character:
            
            return 4 ;
            
            break;
            
        case f32:
            
            return 4 ;
            
            break;
            
        case f64:
            
            return 8 ;
            
            break;
            
        default:
            break;
    }
    
    return 0 ;
}

int m_is_size_of_type_in_bytes( marshmallow_type type ) {
    
    return 0 ;
}

static int typecheck_are_types_equivalent( marshmallow_type t1, marshmallow_type t2 ) {
    
    marshmallow_type t = NULL ;
    
    marshmallow_type t0 = NULL ;
    
    if ( m_is_type_number(t1) && m_is_type_number(t2) ) return 1 ;
    
    if ( (t1->root_type == array && t2->root_type == metacollection) || (t2->root_type == array && t1->root_type == metacollection) ) return 1 ;//for now fake it
    
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
        
      if ( !typecheck_are_types_equivalent(variable->type, variable->static_assignment->type) ) {
        
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

static marshmallow_type typecheck_get_type_from_variable( marshmallow_variable variable, int* has_assignment, marshmallow_module module ) ;

static int is_assignable( marshmallow_variable variable, int* has_assignment, marshmallow_module module ) {
    
    marshmallow_type type = typecheck_get_type_from_variable(variable, has_assignment, module) ;
    
    if ( (m_is_type_number(type) && variable->data != NULL) ) return 0 ;
    
    return 1 ;
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
    
    marshmallow_variable var_a = NULL ;
    
    marshmallow_variable var_b = NULL ;

    if ( statement->var_a != NULL && (statement->var_a->entity_type == entity_function
                                       || (statement->var_a->entity_type == entity_variable && ((marshmallow_variable)statement->var_a)->name != NULL)) ) {

        statement->var_a = (marshmallow_entity)marshmallow_lookup_identifier(statement->function, module, statement->var_a) ;
    }
    
    if (  statement->var_b != NULL && (statement->var_b->entity_type == entity_function
                                       || (statement->var_b->entity_type == entity_variable && ((marshmallow_variable)statement->var_b)->name != NULL)) ) {
        
        statement->var_b = (marshmallow_entity)marshmallow_lookup_identifier(statement->function, module, statement->var_b) ;
    }
    
     switch ( statement->op ) {
           
        case add:
        case sub:
        case mult:
        case mdiv:
        case rem:
                
                rettype_a = typecheck_get_type_from_variable((marshmallow_variable)statement->var_a, has_assignment, module) ;
                
                if (!m_is_type_number(rettype_a) || (statement->op == rem && m_is_type_float(rettype_a)) ) {
                    
                    if ( ((marshmallow_variable)statement->var_a)->name != NULL ) printf("Variable: '%s', is wrong type for add,sub,mult,div, or modulus.\n",RKString_GetString(((marshmallow_variable)statement->var_a)->name)) ;
                    
                    if ( ((marshmallow_variable)statement->var_a)->name == NULL ) printf("Variable is of the wrong type for add,sub,mult,div, or modulus.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                rettype_b = typecheck_get_type_from_variable((marshmallow_variable)statement->var_b, has_assignment, module) ;
                
                if (!m_is_type_number(rettype_b) || (statement->op == rem && m_is_type_float(rettype_b)) ) {
                    
                    if ( ((marshmallow_variable)statement->var_b)->name != NULL ) printf("Variable: '%s', is wrong type for add,sub,mult,div, or modulus.\n",RKString_GetString(((marshmallow_variable)statement->var_b)->name)) ;
                    
                    if ( ((marshmallow_variable)statement->var_b)->name == NULL ) printf("Variable is of the wrong type for add,sub,mult,div, or modulus.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
            
            return typecheck_get_type_from_root_type(typecheck_get_type_promotion(rettype_a, rettype_b)->root_type) ;
            
            break;
             
             case assignment:
             
             *has_assignment = 1 ;
                 
                 var_a = ((marshmallow_variable)statement->var_a) ;
                 
                 if ( !is_assignable(var_a,has_assignment,module) ) {
                     
                     if ( ((marshmallow_variable)statement->var_a)->name != NULL )
                         printf("Variable: '%s', is wrong type for assignment.\n",RKString_GetString(((marshmallow_variable)statement->var_a)->name)) ;
                     
                     if ( ((marshmallow_variable)statement->var_a)->name == NULL ) printf("Variable is of the wrong type for assignment.\n") ;
                     
                     exit(EXIT_FAILURE) ;
                 }
             

                 rettype_b = typecheck_get_type_from_variable((marshmallow_variable)statement->var_b, has_assignment, module) ; ;
                 
                 if ( !typecheck_are_types_equivalent(var_a->type, rettype_b) ) {
                     
                     if ( ((marshmallow_variable)statement->var_b)->name != NULL )
                         printf("Variable: '%s', is wrong type for assignment.\n",RKString_GetString(((marshmallow_variable)statement->var_b)->name)) ;
                     
                     if ( ((marshmallow_variable)statement->var_b)->name == NULL ) printf("Variable is of the wrong type for assignment.\n") ;
                     
                     exit(EXIT_FAILURE) ;
                 }
             
             break;
             
             case inc:
             case dec:
             
             if ( !is_assignable((marshmallow_variable)statement->var_a,has_assignment,module)
                 || !m_is_type_number(typecheck_get_type_from_variable((marshmallow_variable)statement->var_a,has_assignment,module)) ) {
                 
                 printf("Statement is of wrong type for increment or decrement.\n") ;
                 
                 exit(EXIT_FAILURE) ;
             }
             
             *has_assignment = 1 ;
             
             break;
            
        default:
            break;
    }
    
    return typecheck_get_type_from_root_type(unknown) ;
}

static marshmallow_type typecheck_get_type_from_variable( marshmallow_variable variable, int* has_assignment, marshmallow_module module ) {
    
    if ( variable->type->root_type == expression ) {
        
        return typecheck_statment((marshmallow_statement)variable->data, has_assignment, module) ;
    }
    
    return variable->type ;
}


static void typecheck_the_statment( marshmallow_statement statement, marshmallow_module module ) {
    
    int has_assignment = 0 ;
    
    typecheck_statment(statement, &has_assignment, module) ;
    
    if ( ( statement->op == ifop || statement->op == slifop || statement->op == whileop
           || statement->op == switchop || statement->op == caseop || statement->op == endcaseop ||
          statement->op == defaultop || statement->op == breakop || statement->op == continueop
          || statement->op == section || statement->op == gotoop || statement->op == call || statement->op == ret ) ) {
        
        has_assignment = 1 ;
    }
    
    if ( !has_assignment ) {
        
        printf("Expressions must have an assignment.\n") ;
        
        exit(EXIT_FAILURE) ;
        
    }
    
}

static void typecheck_function( marshmallow_function_body function, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;

    typecheck_function_signature(function->signature, module) ;
    
    list = RKStore_GetList(function->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_variable(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
    list = function->statements ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_the_statment(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }


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
    
    list = RKStore_GetList(module->functions_and_methods) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_function(RKList_GetData(node), module) ;
            
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

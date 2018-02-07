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
type##_t->type_name = NULL ;\
type##_t->is_typedef = 0 ;\
type##_t->is_readonly = 0 ;\
type##_t->base_type = NULL ;\
type##_t->num_of_elements = -1 ;\
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
    
    unknown_t->type_name = NULL ;
    
    unknown_t->is_typedef = 0 ;
    
    unknown_t->is_readonly = 0 ;
    
    unknown_t->base_type = NULL ;
    
    unknown_t->num_of_elements = -1 ;
    
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

int m_is_type_signed( marshmallow_type type ) {
    
    switch ( type->root_type ) {
        
    case i8:
        
        return 1 ;
        
        break;
        
    case i16:
        
        return 1 ;
        
        break;
        
    case i32:
        
        return 1 ;
        
        break;
        
    case i64:
        
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

int m_is_root_type( marshmallow_type type ) {
    
    switch (type->root_type) {
            
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
            
        case string:
            
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

int m_get_size_of_root_type_in_bytes( marshmallow_type type ) {
    
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
            
        case ptr:
            
            return 8 ;
            
            break;
            
        default:
            break;
    }
    
    return 0 ;
}

RKULong m_get_size_of_type_in_bytes( marshmallow_type type, marshmallow_root_type* root_type ) {
    
    RKULong size = 0 ;
    
    int num_of_elements = 1 ;
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    marshmallow_type t = NULL ;
    
    marshmallow_variable var = NULL ;
    
    if ( root_type != NULL ) *root_type = type->root_type ;
    
    size = m_get_size_of_root_type_in_bytes(type) ;
    
    if ( type->root_type == array ) {
        
        t = type ;
        
    loop:
        
        size += m_get_size_of_root_type_in_bytes(t->base_type) ;
        
        num_of_elements *= t->num_of_elements ;
        
        t = t->base_type ;
        
        if ( t->root_type == array ) {
            
            goto loop ;
            
        } else {
            
            if ( root_type != NULL ) *root_type = t->root_type ;
        }
        
        size = size * num_of_elements ;
    }
    
    if ( type->root_type == metacollection ) {
        
        list = (RKList)((marshmallow_variable)((marshmallow_variable)type->base_type)->data)->data ;
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            var = RKList_GetData(node) ;
            
            size += m_get_size_of_root_type_in_bytes(var->type) ;
            
            if ( var->type->root_type == array || var->type->root_type == metacollection ) size += m_get_size_of_type_in_bytes(var->type, NULL) ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
    return size ;
}

RKULong m_get_size_of_type_or_array_in_bytes( marshmallow_type type_or_array, marshmallow_root_type* root_type ) {
    
    RKULong size = m_get_size_of_type_in_bytes(type_or_array, root_type) ;
    
    if ( size == 0 ) return 8 ;
    
    return size ;
}

static int typecheck_are_types_equivalent( marshmallow_type t1, marshmallow_type t2 ) {
    
    RKULong size = 0 ;
    
    RKULong size2 = 0 ;
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    marshmallow_type t = NULL ;
    
    marshmallow_type t0 = NULL ;
    
    marshmallow_variable var = NULL ;
    
    marshmallow_root_type root_type ;
    
    marshmallow_root_type root_type2 ;
    
    if ( t1->type_name != NULL && (t2->type_name == NULL && !t2->is_literal) ) return 0 ;
    
    if ( t1->type_name == NULL && (t2->type_name != NULL && !t2->is_literal) ) return 0 ;
    
    if ( t1->type_name != NULL && (t2->type_name != NULL && !t2->is_literal) ) {
        
         if ( !RKString_AreStringsEqual(t1->type_name, t2->type_name) ) return 0 ;
    }
    
    if ( m_is_type_number(t1) && m_is_type_number(t2) ) {
        
        if ( m_is_type_signed(t1) && !m_is_type_signed(t2) ) return 0 ;
        
        if ( !m_is_type_signed(t1) && m_is_type_signed(t2) ) return 0 ;
        
        if ( m_get_size_of_type_in_bytes(t1,&root_type) >= m_get_size_of_type_in_bytes(t2,&root_type2) ) return 1 ;
        
        return 0 ;
    }
        
    if ( (t1->root_type == array && t2->root_type == metacollection) ) {
        
        size = m_get_size_of_type_in_bytes(t1, &root_type) ;
        
        list = (RKList)((marshmallow_variable)((marshmallow_variable)t2->base_type)->data)->data ;
    
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            var = RKList_GetData(node) ;
            
            size2 += m_get_size_of_type_in_bytes(var->type, &root_type2) ;
            
            if ( ((marshmallow_type)t1->base_type)->root_type != array ) {
                
                if ( var->type->root_type == metacollection ) {
                    
                    return 0 ;
                }
                    
                if ( !typecheck_are_types_equivalent(typecheck_get_type_from_root_type(root_type), typecheck_get_type_from_root_type(root_type2)) ) {
                    
                    return 0 ;
                }
            }
            
            if ( ((marshmallow_type)t1->base_type)->root_type == array ) {
                
                if ( var->type->root_type != metacollection ) {
                    
                    return 0 ;
                }
                
                if ( !typecheck_are_types_equivalent(t1->base_type, var->type) ) {
                    
                    return 0 ;
                }
            }
            
            node = RKList_GetNextNode(node) ;
        }
        
        if ( size == 0 ) return 1 ;
        
        if ( size != size2 ) return 0 ;
        
        return 1 ;
    }
    
    if ( t1->root_type == array && t2->root_type == array ) {
        
        t = t1 ;
        
        t0 = t2 ;
        
    loop:
        
        if ( t->num_of_elements != t0->num_of_elements ) return 0 ;
        
        t = t->base_type ;
        
        t0 = t0->base_type ;
        
        if ( t->root_type == array && t0->root_type == array ) goto loop ;
        
        if ( t->root_type != t0->root_type ) {
            
            return 0 ;
            
        } else {
            
            t1 = t ;
            
            t2 = t0 ;
        }
    }
    
    if ( t1->root_type == ptr && t2->root_type == ptr ) {
       
        t = t1 ;
        
        t0 = t2 ;
        
    loop2:
        
        t = t->base_type ;
        
        t0 = t0->base_type ;
        
        if ( t->root_type == ptr && t0->root_type == ptr ) goto loop2 ;
        
        if ( t->root_type == nulltype || t0->root_type == nulltype ) return 1 ;
        
        if ( t->root_type == t0->root_type ) return 1 ;
    }
    
    if ( t1->root_type == array && t2->root_type != metacollection ) return 0 ;
    
    if ( t1->root_type != array && t2->root_type == metacollection ) return 0 ;
    
    if ( t1->root_type == enum_type && t2->root_type == enum_type ) {
        
        if ( !RKString_AreStringsEqual(t1->type_name, t2->type_name) ) return 0 ;
    }
    
    if ( t1->root_type != t2->root_type ) return 0 ;
    
    return 1 ;
}

static void typecheck_type( marshmallow_variable variable, marshmallow_module module ) {
    
    marshmallow_type t = variable->type ;
    
    if ( variable->type->type_name != NULL && ((m_is_type_number(variable->type) && !variable->type->is_typedef) || variable->type->root_type == metacollection ) ) {
        
    free_type_name:
        
        RKString_DestroyString(variable->type->type_name) ;
        
        variable->type->type_name = NULL ;
    }
    
    if ( variable->type->root_type == unknown && variable->type->type_name != NULL ) {
        
        if ( RKString_AreStringsEqual(rkstr("unknown"), variable->type->type_name) ) {
            
            goto free_type_name ;
        }
        
        variable->type = RKStore_GetItem(module->types, RKString_GetString(variable->type->type_name)) ;
        
         free(t) ;
        
        if ( variable->type == NULL ) {
            
            printf("Type given to variable: '%s', does not exist.\n",RKString_GetString(variable->name)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
    }
}

static void typecheck_variable( marshmallow_variable variable, marshmallow_module module ) {
    
    int has_rechecked = 0 ;
    
    typecheck_type(variable,module) ;
    
    if ( variable->static_assignment != NULL ) {
        
        typecheck_type(variable->static_assignment,module) ;
        
    recheck:
        
      if ( !typecheck_are_types_equivalent(variable->type, variable->static_assignment->type) ) {
        
          if ( variable->static_assignment->type->root_type == unknown && !has_rechecked ) {
              
              
              variable->static_assignment = (marshmallow_variable)marshmallow_lookup_identifier(NULL,
                                                                                                module, (marshmallow_entity)variable->static_assignment) ;
              
              if ( variable->static_assignment != NULL && variable->static_assignment->type->root_type != unknown ) {
                  
                  has_rechecked++ ;
                  
                  goto recheck ;
              }
              
          }
          
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
             
                printf("External function or method: '%s', is marked as overridable, an external function can not be marked as overridable.\n",RKString_GetString(((marshmallow_function_body)declaration)->signature->func_name)) ;
                
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
    
    if ( (m_is_type_number(type) && variable->data != NULL) ) {
        
        return 0 ;
    }
    
    return 1 ;
}

static marshmallow_type typecheck_get_type_promotion( marshmallow_type a, marshmallow_type b ) {
    
    marshmallow_type array[2] ;
    
    int array2[2] ;
    
    int i = 0 ;
    
    int j = 0 ;
    
    if ( a == NULL && b != NULL ) return b ;
    
    if ( b == NULL && a != NULL ) return a ;
    
    if ( a == NULL && b == NULL ) return typecheck_get_type_from_root_type(unknown) ;
    
    array[0] = a ;
    
    array[1] = b ;
    
    array2[0] = 0 ;
    
    array2[1] = 0 ;

loop:
    
    j = 0 ;
    
    switch ( array[i]->root_type ) {
        
        case i8:
            
            j = 2 ;
            
            break;
            
        case u8:
            
            j = 1 ;
            
            break;
            
        case i16:
            
            j = 4 ;
            
            break;
            
        case u16:
            
            j = 3 ;
            
            break;
            
        case i32:
            
            j = 6 ;
            
            break;
            
        case u32:
            
            j = 5 ;
            
            break;
            
        case i64:
            
            j = 8 ;
            
            break;
            
        case u64:
            
            j = 7 ;
            
            break;
            
        case hex:
            
            j = 7 ;
            
            break;
            
        case f32:
            
            j = 9 ;
            
            break;
            
        case f64:
            
            j = 10 ;
            
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

static marshmallow_type typecheck_statment( marshmallow_statement statement, int* has_assignment, marshmallow_module module, RKStore store ) ;

static marshmallow_variable typecheck_integer_evalulator( marshmallow_statement statement, marshmallow_module module ) ;

static marshmallow_variable typecheck_float_evalulator( marshmallow_statement statement, marshmallow_module module ) ;

typedef struct eval_val_s { marshmallow_root_type root_type ; int error ; union { RKByte byteval ; RKShort shortval ;
    
RKInt intval ; RKLong longval ; RKFloat floatval ; RKDouble doubleval ; } ; }* eval_val ;

static void typecheck_get_variables_for_evalulator( marshmallow_entity entity, marshmallow_entity* a, marshmallow_entity* b, marshmallow_module module ) {
    
    
    if ( entity->entity_type == entity_statement ) {
        
        *a = ((marshmallow_statement)entity)->var_a ;
        
        *b = ((marshmallow_statement)entity)->var_b ;
    }
    
    if ( entity->entity_type == entity_variable ) {
        
        *a = entity ;
        
        *b = NULL ;
    }
    
}

static eval_val typecheck_get_value_for_evalulator( marshmallow_entity entity, marshmallow_module module ) {
    
    int has_assignment = 0 ;
    
    marshmallow_type type = NULL ;
    
    marshmallow_variable variable = NULL ;
    
    eval_val retptr = RKMem_NewMemOfType( struct eval_val_s ) ;
    
    retptr->error = 1 ;
    
    if ( entity == NULL ) return NULL ;
    
statment_evalulator:
    
    if ( entity->entity_type == entity_statement ) {
        
        type = typecheck_statment((marshmallow_statement)entity, &has_assignment, module, NULL) ;
        
        if ( m_is_type_number(type) && !m_is_type_float(type) ) {
            
            variable = typecheck_integer_evalulator((marshmallow_statement)entity, module) ;
            
            retptr->intval = atoi(RKString_GetString(((marshmallow_value)variable->data)->value)) ;
            
            retptr->root_type = i32 ;
            
            retptr->error = 0 ;
            
        } else if ( m_is_type_float(type) ) {
            
            variable = typecheck_float_evalulator((marshmallow_statement)entity, module) ;
            
            retptr->doubleval = atof(RKString_GetString(((marshmallow_value)variable->data)->value)) ;
            
            retptr->root_type = f64 ;
            
            retptr->error = 0 ;
        }
    }
    
    if ( entity->entity_type == entity_variable ) {
        
        if ( ((marshmallow_variable)entity)->type->root_type == expression ) {
            
            entity = ((marshmallow_variable)entity)->data ;
            
            goto statment_evalulator ;
        }
        
        if ( ((marshmallow_variable)entity)->type->root_type == enum_type ) {
            
            variable = (marshmallow_variable)entity ;
            
            if ( RKStore_ItemExists(((marshmallow_enum)(variable->type->base_type))->enums, RKString_GetString(variable->name)) ) {
                
                retptr->intval = *((unsigned int*)(RKStore_GetItem(((marshmallow_enum)(variable->type->base_type))->enums, RKString_GetString(variable->name)))) ;
                
                retptr->root_type = u32 ;
                
                retptr->error = 0 ;
            }
        
        }
       
        if ( m_is_type_number(((marshmallow_variable)entity)->type) && ((marshmallow_variable)entity)->data != NULL ) {
            
               switch ( ((marshmallow_variable)entity)->type->root_type ) {
                       
                   case i8:
                       
                       retptr->byteval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = i8 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case u8:
                       
                       retptr->byteval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = u8 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case i16:
                       
                       retptr->shortval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = i16 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case u16:
                       
                       retptr->shortval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = u16 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case i32:
                       
                       retptr->intval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = i32 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case u32:
                       
                       retptr->intval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = u32 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case i64:
                       
                       retptr->longval = atol(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = i64 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case u64:
                       
                       retptr->longval = atol(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = u64 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case hex:
                       
                     #ifdef WIN32_
                       
                       strtoll(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value), NULL, 0) ;
                       
                     #else
                       
                       strtol(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value), NULL, 0) ;
                       
                     #endif
                       
                       retptr->root_type = u64 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case f32:
                       
                       retptr->floatval = atof(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                       
                       retptr->root_type = f32 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   case f64:
                       
                       retptr->doubleval = atof(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->data)->value)) ;
                      
                       retptr->root_type = f64 ;
                       
                       retptr->error = 0 ;
                       
                       break;
                       
                   default:
                       break;
               }
       }
        
        if ( m_is_type_number(((marshmallow_variable)entity)->type) && ((marshmallow_variable)entity)->static_assignment != NULL &&
            ((marshmallow_variable)entity)->type->is_readonly) {
            
            switch ( ((marshmallow_variable)entity)->type->root_type ) {
                    
                case i8:
                    
                    retptr->byteval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = i8 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case u8:
                    
                    retptr->byteval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = u8 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case i16:
                    
                    retptr->shortval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = i16 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case u16:
                    
                    retptr->shortval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = u16 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case i32:
                    
                    retptr->intval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = i32 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case u32:
                    
                    retptr->intval = atoi(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = u32 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case i64:
                    
                    retptr->longval = atol(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = i64 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case u64:
                    
                    retptr->longval = atol(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = u64 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case hex:
                    
                #ifdef WIN32_
                    
                    strtoll(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value), NULL, 0) ;
                    
                #else
                    
                    strtol(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value), NULL, 0) ;
                    
                #endif
                    
                    retptr->root_type = u64 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case f32:
                    
                    retptr->floatval = atof(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = f32 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                case f64:
                    
                    retptr->doubleval = atof(RKString_GetString(((marshmallow_value)((marshmallow_variable)entity)->static_assignment->data)->value)) ;
                    
                    retptr->root_type = f64 ;
                    
                    retptr->error = 0 ;
                    
                    break;
                    
                default:
                    break;
            }
        }

    
    }
    
    if ( retptr->error ) return NULL ;
    
    return retptr ;
}

static marshmallow_variable typecheck_integer_evalulator( marshmallow_statement statement, marshmallow_module module ) {
    
    marshmallow_variable var = marshmallow_new_variable() ;
    
    var->type = marshmallow_new_type() ;
    
    marshmallow_value value = RKMem_NewMemOfType(struct marshmallow_value_s) ;
    
    value->type = marshmallow_new_type() ;
    
    char string[100] ;
    
    int a = 0 ;
    
    int b = 0 ;
    
    int c = 0 ;
    
    eval_val eval_a = NULL ;
    
    eval_val eval_b = NULL ;
    
    marshmallow_entity entity_a = NULL ;
    
    marshmallow_entity entity_b = NULL ;
    
    var->type->root_type = i32 ;
    
    value->type->root_type = i32 ;
    
    var->data = value ;
    
    typecheck_get_variables_for_evalulator((marshmallow_entity)statement, &entity_a, &entity_b, module) ;
    
    eval_a = typecheck_get_value_for_evalulator(entity_a, module) ;
    
    eval_b = typecheck_get_value_for_evalulator(entity_b, module) ;
    
    if ( eval_a == NULL ) return NULL ;
    
    switch (eval_a->root_type) {
         
        case i8:
            
            a = eval_a->byteval ;
            
            break;
            
        case u8:
            
            a = eval_a->byteval ;
            
            break;

            
        case i16:
            
            a = eval_a->shortval ;
            
            break;
            
        case u16:
            
            a = eval_a->shortval ;
            
            break;
    
            
        case i32:
            
            a = eval_a->intval ;
            
            break;
            
        case u32:
            
            a = eval_a->intval ;
            
            break;
            
        case i64:
            
            a = (RKInt)eval_a->longval ;
            
            break;
            
        case u64:
            
            a = (RKInt)eval_a->longval ;
            
            break;
            
        case f32:
            
            a = eval_a->floatval ;
            
            break;
            
        case f64:
            
            a = eval_a->doubleval ;
            
            break;

            
        default:
            break;
    }
    
    if ( eval_b == NULL ) {
        
        c = a ;
        
        goto end ;
    }
    
    switch (eval_b->root_type) {
            
        case i8:
            
            b = eval_b->byteval ;
            
            break;
            
        case u8:
            
            b = eval_b->byteval ;
            
            break;
            
            
        case i16:
            
            b = eval_b->shortval ;
            
            break;
            
        case u16:
            
            b = eval_b->shortval ;
            
            break;
            
            
        case i32:
            
            b = eval_b->intval ;
            
            break;
            
        case u32:
            
            b = eval_b->intval ;
            
            break;
            
        case i64:
            
            b = (RKInt)eval_b->longval ;
            
            break;
            
        case u64:
            
            b = (RKInt)eval_b->longval ;
            
            break;
            
        case f32:
            
            b = eval_b->floatval ;
            
            break;
            
        case f64:
            
            b = eval_b->doubleval ;
            
            break;
            
            
        default:
            break;
    }

    
    switch ( statement->op ) {
            
        case add:
            
            c = a + b ;
            
            break;
            
        case sub:
            
            c = a - b ;
            
            break;
            
        case mult:
            
            c = a * b ;
            
            break;
            
        case mdiv:
            
            c = a / b ;
            
            break;
            
        case rem:
            
            c = a % b ;
            
            break;
            
        case bor:
            
            c = a | b ;
            
            break;
            
        case xor:
            
            c = a ^ b ;
            
            break;
            
        case band:
            
            c = a & b ;
            
            break;
            
        default:
            
            return NULL ;
            
            break;
    }
    
end:
    
    marshmallow_itoa(c, string) ;
    
    value->value = RKString_NewStringFromCString(string) ;
    
    return var ;
}

static marshmallow_variable typecheck_float_evalulator( marshmallow_statement statement, marshmallow_module module ) {
    
    marshmallow_variable var = marshmallow_new_variable() ;
    
    var->type = marshmallow_new_type() ;
    
    marshmallow_value value = RKMem_NewMemOfType(struct marshmallow_value_s) ;
    
    value->type = marshmallow_new_type() ;
    
    char string[100] ;
    
    double a = 0 ;
    
    double b = 0 ;
    
    double c = 0 ;
    
    eval_val eval_a = NULL ;
    
    eval_val eval_b = NULL ;
    
    marshmallow_entity entity_a = NULL ;
    
    marshmallow_entity entity_b = NULL ;
    
    var->type->root_type = f64 ;
    
    value->type->root_type = f64 ;
    
    var->data = value ;
    
    typecheck_get_variables_for_evalulator((marshmallow_entity)statement, &entity_a, &entity_b, module) ;
    
    eval_a = typecheck_get_value_for_evalulator(entity_a, module) ;
    
    eval_b = typecheck_get_value_for_evalulator(entity_b, module) ;
    
    if ( eval_a == NULL ) return NULL ;
    
    switch (eval_a->root_type) {
            
        case i8:
            
            a = eval_a->byteval ;
            
            break;
            
        case u8:
            
            a = eval_a->byteval ;
            
            break;
            
            
        case i16:
            
            a = eval_a->shortval ;
            
            break;
            
        case u16:
            
            a = eval_a->shortval ;
            
            break;
            
            
        case i32:
            
            a = eval_a->intval ;
            
            break;
            
        case u32:
            
            a = eval_a->intval ;
            
            break;
            
        case i64:
            
            a = (RKInt)eval_a->longval ;
            
            break;
            
        case u64:
            
            a = (RKInt)eval_a->longval ;
            
            break;
            
        case f32:
            
            a = eval_a->floatval ;
            
            break;
            
        case f64:
            
            a = eval_a->doubleval ;
            
            break;
            
            
        default:
            break;
    }
    
    if ( eval_b == NULL ) {
        
        c = a ;
        
        goto end ;
    }
    
    switch (eval_b->root_type) {
            
        case i8:
            
            b = eval_b->byteval ;
            
            break;
            
        case u8:
            
            b = eval_b->byteval ;
            
            break;
            
            
        case i16:
            
            b = eval_b->shortval ;
            
            break;
            
        case u16:
            
            b = eval_b->shortval ;
            
            break;
            
            
        case i32:
            
            b = eval_b->intval ;
            
            break;
            
        case u32:
            
            b = eval_b->intval ;
            
            break;
            
        case i64:
            
            b = eval_b->longval ;
            
            break;
            
        case u64:
            
            b = eval_b->longval ;
            
            break;
            
        case f32:
            
            b = eval_b->floatval ;
            
            break;
            
        case f64:
            
            b = eval_b->doubleval ;
            
            break;
            
            
        default:
            break;
    }
    
    
    switch ( statement->op ) {
            
        case add:
            
            c = a + b ;
            
            break;
            
        case sub:
            
            c = a - b ;
            
            break;
            
        case mult:
            
            c = a * b ;
            
            break;
            
        case mdiv:
            
            c = a / b ;
            
            break;
            
        default:
            
            return NULL ;
            
            break;
    }
    
end:
    
    marshmallow_dtoa(c, string) ;
    
    value->value = RKString_NewStringFromCString(string) ;
    
    return var ;
}

static marshmallow_type typecheck_make_ptr_type_from_type( marshmallow_type type ) {
    
    marshmallow_type ptrtype = marshmallow_new_type() ;
    
    ptrtype->base_type = type ;
    
    ptrtype->root_type = ptr ;
    
    RKString_DestroyString(ptrtype->type_name) ;
    
    ptrtype->type_name = NULL ;
    
    return ptrtype ;
}

static marshmallow_type typecheck_statment( marshmallow_statement statement, int* has_assignment, marshmallow_module module, RKStore store ) {
    
    marshmallow_type rettype_a = NULL ;
    
    marshmallow_type rettype_b = NULL ;
    
    marshmallow_variable var_a = NULL ;
    
    marshmallow_variable var_b = NULL ;
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    RKStore switch_store = NULL ;

    if ( statement->entity_type == entity_variable ) {
        
        return typecheck_get_type_from_variable((marshmallow_variable)statement, has_assignment, module) ;
    }
    
    
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
                
                if (!(m_is_type_number(rettype_a) || rettype_a->root_type == enum_type) || (statement->op == rem && m_is_type_float(rettype_a)) ) {
                    
                    if ( ((marshmallow_variable)statement->var_a)->name != NULL ) printf("Variable: '%s', is wrong type for add,sub,mult,div, or modulus.\n",RKString_GetString(((marshmallow_variable)statement->var_a)->name)) ;
                    
                    if ( ((marshmallow_variable)statement->var_a)->name == NULL ) printf("Variable is of the wrong type for add,sub,mult,div, or modulus.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                rettype_b = typecheck_get_type_from_variable((marshmallow_variable)statement->var_b, has_assignment, module) ;
                
                if (!(m_is_type_number(rettype_b) || rettype_b->root_type == enum_type) || (statement->op == rem && m_is_type_float(rettype_b)) ) {
                    
                    if ( ((marshmallow_variable)statement->var_b)->name != NULL ) printf("Variable: '%s', is wrong type for add,sub,mult,div, or modulus.\n",RKString_GetString(((marshmallow_variable)statement->var_b)->name)) ;
                    
                    if ( ((marshmallow_variable)statement->var_b)->name == NULL ) printf("Variable is of the wrong type for add,sub,mult,div, or modulus.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
            
            return typecheck_get_type_from_root_type(typecheck_get_type_promotion(rettype_a, rettype_b)->root_type) ;
            
            break;
             
             case assignment:
             
             *has_assignment = 1 ;
                 
                 var_a = ((marshmallow_variable)statement->var_a) ;
             
                 var_b = ((marshmallow_variable)statement->var_b) ;
                 
                 if ( !is_assignable(var_a,has_assignment,module) ) {
                     
                     if ( ((marshmallow_variable)statement->var_a)->name != NULL )
                         printf("Variable: '%s', is wrong type for assignment.\n",RKString_GetString(((marshmallow_variable)statement->var_a)->name)) ;
                     
                     if ( ((marshmallow_variable)statement->var_a)->name == NULL ) printf("Variable is of the wrong type for assignment.\n") ;
                     
                     exit(EXIT_FAILURE) ;
                 }
             

                 rettype_b = typecheck_get_type_from_variable((marshmallow_variable)statement->var_b, has_assignment, module) ;
             
                 if ( !typecheck_are_types_equivalent(var_a->type, rettype_b) ) {
                     
                     if ( ((marshmallow_variable)statement->var_b)->name != NULL )
                         printf("Variable: '%s', is wrong type for assignment.\n",RKString_GetString(((marshmallow_variable)statement->var_b)->name)) ;
                     
                     if ( ((marshmallow_variable)statement->var_b)->name == NULL ) printf("Variable is of the wrong type for assignment.\n") ;
                     
                     exit(EXIT_FAILURE) ;
                 }
             
             if ( var_a->type->root_type == array && var_b->type->root_type == array && var_a->type->num_of_elements > 0 ) statement->op = array_assignment ;
             
             return typecheck_get_type_from_root_type(typecheck_get_type_promotion(var_a->type, var_b->type)->root_type) ;
             
             break;
             
             case inc:
             case dec:
             
             if ( !is_assignable((marshmallow_variable)statement->var_a,has_assignment,module)
                 || !m_is_type_number(typecheck_get_type_from_variable((marshmallow_variable)statement->var_a,has_assignment,module)) ) {
                 
                 printf("Statement is of wrong type for increment or decrement.\n") ;
                 
                 exit(EXIT_FAILURE) ;
             }
             
             *has_assignment = 1 ;
             
             return typecheck_get_type_from_root_type(typecheck_get_type_promotion(((marshmallow_variable)statement->var_a)->type, NULL)->root_type) ;
             
             break;
             
             case switchop:
             
             rettype_a = typecheck_statment((marshmallow_statement)statement->var_a, has_assignment, module, NULL) ;
             
             if ( !m_is_type_number(rettype_a) || m_is_type_float(rettype_a) ) {
                 
                 printf("Statement is a non-integer expression, switch needs a integer expression.\n") ;
                 
                 exit(EXIT_FAILURE) ;
             }
             
             switch_store = RKStore_NewStore() ;
             
             list = statement->statements ;
             
             if ( list != NULL ) {
                 
                 node = RKList_GetFirstNode(list) ;
                 
                 while (node != NULL) {
                     
                     typecheck_statment(RKList_GetData(node), has_assignment, module, switch_store) ;
                     
                     node = RKList_GetNextNode(node) ;
                 }
             }
             
             RKStore_DestroyStore(switch_store) ;
             
             break;
             
             case caseop:
             case endcaseop:

             var_a = typecheck_integer_evalulator((marshmallow_statement)statement->var_a, module) ;
             
             if ( var_a == NULL ) {
                 
                 printf("Expression is a non-constant expression, case needs a constant expression.\n") ;
                 
                 exit(EXIT_FAILURE) ;
                 
             }
             
             if ( RKStore_ItemExists(store, RKString_GetString(((marshmallow_value)var_a->data)->value)) ) {
                 
                 printf("Expression value: %s, is already used by another case.\n",RKString_GetString(((marshmallow_value)var_a->data)->value)) ;
                 
                 exit(EXIT_FAILURE) ;
             }
             
             RKStore_AddItem(store, rkstr("item"), RKString_GetString(((marshmallow_value)var_a->data)->value)) ;
             
             statement->var_a =(marshmallow_entity)var_a ;
             
             list = statement->statements ;
             
             if ( list != NULL ) {
                 
                 node = RKList_GetFirstNode(list) ;
                 
                 while (node != NULL) {
                     
                     typecheck_statment(RKList_GetData(node), has_assignment, module, store) ;
                     
                     node = RKList_GetNextNode(node) ;
                 }
             }
             
             break;
             
         case addrof:
             
             rettype_a = typecheck_get_type_from_variable((marshmallow_variable)statement->var_a, has_assignment, module) ;
             
             if ( rettype_a->is_literal ) {
                 
                 printf("Can not take the address of a literal.") ;
                 
                 exit(EXIT_FAILURE) ;
             }
             
             return typecheck_make_ptr_type_from_type(rettype_a) ;
             
             break;
             
         case deref:
             
             rettype_a = typecheck_get_type_from_variable((marshmallow_variable)statement->var_a, has_assignment, module) ;
             
             if ( rettype_a->root_type != ptr ) {
                 
                 printf("Can not deref a non-pointer.") ;
                 
                 exit(EXIT_FAILURE) ;
             }
            
             var_a = marshmallow_new_variable() ;
             
             var_a->type = rettype_a->base_type ;
             
             typecheck_type(var_a, module) ;
             
             free(var_a) ;
             
             return rettype_a->base_type ;
             
             break;
            
        default:
            break;
    }
    
    return typecheck_get_type_from_root_type(unknown) ;
}

static marshmallow_type typecheck_get_type_from_variable( marshmallow_variable variable, int* has_assignment, marshmallow_module module ) {
    
    marshmallow_type t = NULL ;
    
    if ( variable->type->root_type == expression ) {
        
        t = typecheck_statment((marshmallow_statement)variable->data, has_assignment, module, NULL) ;
        
    } else {
        
        t = variable->type ;
    }
    
    typecheck_type(variable, module) ;
    
    return t ;
}

static void typecheck_the_statment( marshmallow_statement statement, marshmallow_module module ) {
    
    int has_assignment = 0 ;
    
    typecheck_statment(statement, &has_assignment, module, NULL) ;
    
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

static void typecheck_process_type( marshmallow_type type, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    marshmallow_type t = NULL ;
    
    marshmallow_type t0 = NULL ;
    
    if ( !type->is_typedef ) return ;
    
    if ( type->is_typedef ) {
        
        t = type ;
        
    loop:
        
        if ( t->root_type == unknown && t->is_typedef && t->base_type != NULL ) {
            
            t = t->base_type ;
            
            goto loop ;
            
        } else  if ( t->is_typedef && t->base_type == NULL ) {
            
            if ( t->is_typedef && t->root_type != unknown ) goto process ;
            
            t0 = RKStore_GetItem(module->types, RKString_GetString(t->type_name)) ;
            
            if ( t0 != NULL ) t = t0 ;
            
            if ( t->base_type != NULL && t->root_type == enum_type ) {
                
                goto process ;
            }
            
            if ( ( t->base_type != NULL && ((marshmallow_type)t->base_type)->root_type != unknown) || m_is_root_type(t) ) {
                
                goto process ;
            }
            
            list = RKStore_GetItem(module->unprocessed_types, RKString_GetString(t->type_name)) ;
            
            if ( list == NULL ) {
                
                list = RKList_NewList() ;
                
                RKStore_AddItem(module->unprocessed_types, list, RKString_GetString(t->type_name)) ;
            }
            
            RKList_AddToList(list, type) ;
            
            return ;
        }
    }
    
process:
    
        if ( t->base_type != NULL && t->root_type != enum_type ) t = t->base_type ;
    
        type->root_type = t->root_type ;
    
        type->output_name = RKString_CopyString(t->type_name) ;
    
        type->is_readonly = t->is_readonly ;
        
        type->num_of_elements = t->num_of_elements ;
        
        t0 = ( type->root_type == unknown ) ? type->base_type : NULL ;
    
        type->base_type = t->base_type ;
        
        free(t0) ;
    
        list = RKStore_GetItem(module->unprocessed_types, RKString_GetString(type->type_name)) ;
    
        if ( list != NULL ) {
    
         node = RKList_GetFirstNode(list) ;
    
         while ( node != NULL ) {
        
          t0 = RKList_GetData(node) ;
          
          typecheck_process_type(t0, module) ;
        
          node = RKList_GetNextNode(node) ;
             
        }
            
          RKList_DeleteList(list) ;
            
          RKStore_AddItem(module->unprocessed_types, NULL, RKString_GetString(type->type_name)) ;
      }
}

static void typecheck_module( marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(module->types) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            typecheck_process_type(RKList_GetData(node), module) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
    list = RKStore_GetList(module->unprocessed_types) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            if ( RKList_GetData(node) != NULL ) {
                
                printf("Undefined type: %s.\n", RKString_GetString(RKStore_GetStoreLabelFromListNode(node))) ;
                
                exit(EXIT_FAILURE) ;
            }
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
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

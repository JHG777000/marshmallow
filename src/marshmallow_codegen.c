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

 const char* marshmallow_ltoa( RKULong val, char* string ) {
    
#ifdef _WIN32
    
    snprintf(string, sizeof(string), "%llu", val) ;
    
#else
    
    snprintf(string, sizeof(string), "%lu", val) ;
    
#endif
    
    return string ;
    
}

 const char* marshmallow_itoa( int val, char* string ) {
    
    snprintf(string, sizeof(string), "%d", val) ;
    
    return string ;
}

 const char* marshmallow_uitoa( unsigned int val, char* string ) {
    
    snprintf(string, sizeof(string), "%u", val) ;
    
    return string ;
    
}

 const char* marshmallow_ftoa( float val, char* string ) {
    
    snprintf(string, sizeof(string), "%f", val) ;
    
    return string ;
    
}

 const char* marshmallow_dtoa( double val, char* string ) {
    
    snprintf(string, sizeof(string), "%f", val) ;
    
    return string ;
    
}

static void output_symbol( marshmallow_context context, FILE* file, RKString name, marshmallow_module module, int is_global, int is_definition ) {
    
    if ( name == NULL ) return ;
    
    if ( is_global ) {
    
     RKString underscore = rkstr("_") ;
    
     RKString str0 = RKString_AppendString(rkstr("marshmallow_"), module->name) ;
    
     RKString str1  = RKString_AppendString(str0, underscore) ;
    
     RKString str2 = RKString_AppendString(str1, name) ;
        
     if ( RKStore_ItemExists(context->symbols, RKString_GetString(str2)) && is_definition ) {
        
         if ( name != RKStore_GetItem(context->symbols, RKString_GetString(str2)) ) {
            
             printf("Error: symbol '%s', already exists.\n",RKString_GetString(str2)) ;
            
             exit(EXIT_FAILURE) ;
            
         }
     }
        
     fprintf(file, "%s", RKString_GetString(str2)) ;
     
     if ( is_definition ) RKStore_AddItem(context->symbols, name, RKString_GetString(str2)) ;
    
     RKString_DestroyString(underscore) ;
        
    } else {

     fprintf(file, "%s", RKString_GetString(name)) ;
        
    }
}

static void output_type( marshmallow_context context, FILE* file, marshmallow_type type, marshmallow_variable static_assignment, marshmallow_module module ) {
    
    marshmallow_type t = type ;
    
loop:
    
    if ( (t->root_type == ptr) || (t->root_type == array)  ) t = t->base_type ;
    
    if ( (t->root_type == ptr) || (t->root_type == array) ) goto loop ;
    
    if ( t->root_type == unknown && t->is_typedef ) {
        
        fprintf(file, "%s ", RKString_GetString(t->output_name)) ;
    }
    
    if ( t->root_type != unknown ) {
        
        switch (t->root_type) {
             
            case u8:
                
                fprintf(file, "mu8 ") ;
                
                break;
                
            case i8:
                
                fprintf(file, "mi8 ") ;
                
                break;
                
            case u16:
                
                fprintf(file, "mu16 ") ;
                
                break;
                
            case i16:
                
                fprintf(file, "mi16 ") ;
                
                break;
                
            case u32:
                
                fprintf(file, "mu32 ") ;
                
                break;
                
            case enum_type:
                
                fprintf(file, "mu32 ") ;
                
                break;
                
            case i32:
                
                fprintf(file, "mi32 ") ;
                
                break;

            case u64:
                
                fprintf(file, "mu64 ") ;
                
                break;
                
            case i64:
                
                fprintf(file, "mi64 ") ;
                
                break;
                
            case f32:
                
                fprintf(file, "mf32 ") ;
                
                break;
                
            case f64:
                
                fprintf(file, "mf64 ") ;
                
                break;
                
            default:
                break;
        }
        
        
    } else if (!t->is_typedef ) {
        
        output_symbol(context, file, t->type_name, module, 1, 0) ;
        
        fprintf(file, " ") ;
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

static void output_array( marshmallow_context context, FILE* file, marshmallow_type type, marshmallow_variable static_assignment, marshmallow_module module ) {
    
    int is_not_zero = 0 ;
    
    int is_first = 1 ;
    
    int is_zero = 0 ;
    
    marshmallow_type t = type ;
    
loop:
    if ( t->root_type == array ) {
        
        if ( t->num_of_elements == 0 ) is_zero++ ;
        
        if ( t->num_of_elements != 0 ) is_not_zero++ ;
        
        if ( t->num_of_elements == 0 && !is_first && static_assignment != NULL ) {
            
            printf("Error: Only the first array is allowed to be zero, when statically assigned.\n") ;
            
            exit(EXIT_FAILURE) ;
        }
        
        if ( ((t->num_of_elements != 0 && is_zero) || (t->num_of_elements == 0 && is_not_zero)) && static_assignment == NULL ) {
            
            printf("Error: When not statically assigned zero and non-zero arrays can not be mixed.\n") ;
            
            exit(EXIT_FAILURE) ;
        }
        
        if ( static_assignment == NULL && t->num_of_elements != 0 ) fprintf(file,"[") ;
        
        if ( static_assignment != NULL ) fprintf(file,"[") ;
        
#ifdef _WIN32
        
        if ( t->num_of_elements > 0 ) fprintf(file, "%llu", t->num_of_elements) ;

#else
        
        if ( t->num_of_elements > 0 ) fprintf(file, "%lu", t->num_of_elements) ;
        
#endif
        
        if ( static_assignment == NULL && t->num_of_elements != 0 ) fprintf(file,"]") ;
        
        if ( static_assignment != NULL ) fprintf(file,"]") ;
        
        t = t->base_type ;
        
        is_first = 0 ;
        
        goto loop ;
    }
}

static void output_value(marshmallow_context context, FILE* file, marshmallow_variable value, marshmallow_module module) ;

static void output_variable( marshmallow_context context, FILE* file, marshmallow_variable variable, marshmallow_module module, int is_global, int no_default ) {
    
    if ( RKStore_ItemExists(context->symbols, RKString_GetString(variable->name)) ) {
        
        if ( variable->name != RKStore_GetItem(context->symbols, RKString_GetString(variable->name)) ) {
            
            printf("Error: symbol '%s', already exists.\n",RKString_GetString(variable->name)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
    }
    
    output_type(context, file, variable->type, variable->static_assignment, module) ;
    
    output_symbol(context, file, variable->name, module, is_global, 1) ;
    
    output_array(context, file, variable->type, variable->static_assignment, module) ;
    
    if ( variable->static_assignment != NULL && !no_default) {
        
        fprintf(file, " ") ;
        
        fprintf(file, "=") ;
        
        fprintf(file, " ") ;
    
        output_value(context, file, variable->static_assignment, module) ;
    }
}

static void output_a_return( marshmallow_context context, FILE* file, marshmallow_variable variable, int n, marshmallow_function_signature signature, marshmallow_module module, int is_definition ) ;

static void output_statement( marshmallow_context context, FILE* file, marshmallow_statement statement, marshmallow_module module ) ;

static void output_collection( marshmallow_context context, FILE* file, marshmallow_variable the_collection, marshmallow_module module ) ;

static void output_enum( marshmallow_context context, FILE* file, marshmallow_variable value, marshmallow_module module ) {
    
    char string[100] ;
    
    if ( !RKStore_ItemExists(((marshmallow_enum)(value->type->base_type))->enums, RKString_GetString(value->name)) ) {
        
        output_symbol(context, file, value->name, module, value->is_global, 0) ;
        
        return ;
    }
    
    fprintf(file, "%s",marshmallow_uitoa(*((unsigned int*)(RKStore_GetItem(((marshmallow_enum)(value->type->base_type))->enums, RKString_GetString(value->name)))), string)) ;
}

static void output_value( marshmallow_context context, FILE* file, marshmallow_variable value, marshmallow_module module ) {
    
    if ( value == NULL ) return ;
    
    if ( value->type->root_type == string ) fprintf(file, "u8\"") ;
    
    if ( value->type->root_type == character ) fprintf(file, "L\'") ;
    
    if ( value->type->root_type == enum_type ) {
        
        output_enum(context, file, value, module) ;
    }
    
    if ( value->type->root_type == array ) {
        
        if ( value->name != NULL ) output_symbol(context, file, value->name, module, 0, 0) ;
    }
    
    if ( value->type->root_type == ptr ) {
        
        if ( ((marshmallow_type)(value->type->base_type))->root_type == nulltype ) {
            
            fprintf(file, "%s", "((void*)0)") ;
            
            return ;
        }
        
        if ( value->name != NULL ) output_symbol(context, file, value->name, module, 0, 0) ;
    }

    
    if ( value->type->root_type != unknown && value->type->root_type != array && value->type->root_type != arguments && value->type->root_type != metacollection
        && value->type->root_type != expression && value->data != NULL ) {
        
        fprintf(file, "%s", RKString_GetString(((marshmallow_value)value->data)->value)) ;
        
    }
    
    if ( value->type->root_type == expression ) {
        
        output_statement(context, file, value->data, module) ;
    }
    
    if ( value->type->root_type == metacollection ) {
        
        output_collection(context, file, value->data, module) ;
    }
    
    if ( (value->type->root_type == unknown || ( m_is_type_number(value->type) && value->type->root_type != hex )) && value->name != NULL ) {
        
        output_symbol(context, file, value->name, module, value->is_global, 0) ;
    }
    
    if ( value->type->root_type == unknown && value->name == NULL ) {
        
         fprintf(file, "%s", RKString_GetString(((marshmallow_value)value->data)->value)) ;
    }
    
    if ( value->type->root_type == string ) fprintf(file, "\"") ;
    
    if ( value->type->root_type == character ) fprintf(file, "\'") ;
    
}

static void output_collection( marshmallow_context context, FILE* file, marshmallow_variable the_collection, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( the_collection->type->root_type == collection ) {
        
        list = the_collection->data ;
        
        if ( list != NULL ) {
            
            fprintf(file, "{") ;
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_value(context, file, RKList_GetData(node), module) ;
                
                if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
                
                node = RKList_GetNextNode(node) ;
            }
            
            fprintf(file, "}") ;
            
        }
        
    }
    
}

static void output_multiple_returns( marshmallow_context context, FILE* file, marshmallow_variable the_collection, marshmallow_function_signature signature, marshmallow_module module ) {
    
    int n = 0 ;
    
    RKList list = NULL ;
    
    RKList list2 = NULL ;
    
    RKList_node node = NULL ;
    
    RKList_node node2 = NULL ;
    
    if ( the_collection->type->root_type == collection ) {
        
        list = the_collection->data ;
        
        list2 = signature->returns ;
        
        if ( list != NULL && list2 != NULL ) {
            
            node = RKList_GetFirstNode(list) ;
            
            node2 = RKList_GetFirstNode(list2) ;
            
            while (node != NULL && node2 != NULL) {
                
                output_a_return(context, file, NULL, n, signature, module, 0) ;
                
                fprintf(file, "=") ;
                
                output_value(context, file, RKList_GetData(node), module) ;
                
                if ( RKList_GetNextNode(node) != NULL ) fprintf(file, " ; \n") ;
                
                node = RKList_GetNextNode(node) ;
                
                node2 = RKList_GetNextNode(node2) ;
                
                n++ ;
            }
            
        }
        
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


static void output_array_assignment( marshmallow_context context, FILE* file, marshmallow_statement statement, marshmallow_module module ) {
    
    fprintf(file,"memcpy(") ;
    
    output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
    
    fprintf(file,",") ;
    
    output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
    
    fprintf(file,", sizeof(") ;
    
    output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
    
    fprintf(file,"))") ;
}

static void output_statement( marshmallow_context context, FILE* file, marshmallow_statement statement, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( statement->entity_type == entity_variable ) {
        
        output_value(context, file, (marshmallow_variable)statement, module) ;
        
        return ;
    }
    
    if ( statement->is_expression ) fprintf(file, "(") ;
    
    switch ( statement->op ) {
         
        case noop:
         
             output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            break;
            
        case section:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,":") ;
            
            break;
            
        case gotoop:
            
            fprintf(file,"goto ") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,";") ;
            
            break;
            
        case slifop:
            
            fprintf(file,"if (") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,")") ;
            
            fprintf(file," ") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case ifop:
            
            if ( statement->var_b != NULL ) {
                
                fprintf(file,"else ") ;
            }
            
            fprintf(file,"if (") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,") {\n") ;
            
            list = statement->statements ;
            
            if ( list != NULL ) {
                
                node = RKList_GetFirstNode(list) ;
                
                while (node != NULL) {
                    
                    output_statement(context, file, RKList_GetData(node), module) ;
                    
                    fprintf(file, " ") ;
                    
                    if (((marshmallow_statement)RKList_GetData(node))->op != ifop) fprintf(file, " ;\n") ;
                    
                    node = RKList_GetNextNode(node) ;
                }
            }
            
            fprintf(file,"}") ;
            
            break;
            
        case whileop:
            
            fprintf(file,"while (") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,") {\n") ;
            
            list = statement->statements ;
            
            if ( list != NULL ) {
                
                node = RKList_GetFirstNode(list) ;
                
                while (node != NULL) {
                    
                    output_statement(context, file, RKList_GetData(node), module) ;
                    
                    fprintf(file, " ") ;
                    
                    if (((marshmallow_statement)RKList_GetData(node))->op != ifop) fprintf(file, " ;\n") ;
                    
                    node = RKList_GetNextNode(node) ;
                }
            }
            
            fprintf(file,"}") ;
            
            break;
            
        case switchop:
            
            fprintf(file,"switch (") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,") {\n") ;
            
            list = statement->statements ;
            
            if ( list != NULL ) {
                
                node = RKList_GetFirstNode(list) ;
                
                while (node != NULL) {
                    
                    output_statement(context, file, RKList_GetData(node), module) ;
                    
                    node = RKList_GetNextNode(node) ;
                }
            }
            
            fprintf(file,"}") ;
            
            break;
            
        case caseop:
        case endcaseop:
            
            fprintf(file,"case ") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file,":\n") ;
            
            list = statement->statements ;
            
            if ( list != NULL ) {
                
                node = RKList_GetFirstNode(list) ;
                
                while (node != NULL) {
                    
                    output_statement(context, file, RKList_GetData(node), module) ;
                    
                    fprintf(file, " ") ;
                    
                    if (((marshmallow_statement)RKList_GetData(node))->op != ifop) fprintf(file, " ;\n") ;
                    
                    node = RKList_GetNextNode(node) ;
                }
            }
            
            if ( statement->op == endcaseop ) fprintf(file,"break;") ;
            
            break;
            
        case defaultop:
            
            fprintf(file,"default:") ;
            
            list = statement->statements ;
            
            if ( list != NULL ) {
                
                node = RKList_GetFirstNode(list) ;
                
                while (node != NULL) {
                    
                    output_statement(context, file, RKList_GetData(node), module) ;
                    
                    fprintf(file, " ") ;
                    
                    if (((marshmallow_statement)RKList_GetData(node))->op != ifop) fprintf(file, " ;\n") ;
                    
                    node = RKList_GetNextNode(node) ;
                }
            }
            
            fprintf(file,"break;") ;
            
            break;

        case call:
            
            if ( 0 /*!((marshmallow_function_body)statement->var_a)->signature->is_external*/ ) {
                
                //output_symbol(context, file, ((marshmallow_function_body)statement->var_a)->signature->func_name, module, 1, 0) ;
                
            } else {
                
                fprintf(file, "%s", RKString_GetString(((marshmallow_function_body)statement->var_a)->signature->func_name)) ;
                
            }
            
            fprintf(file, "(") ;
            
            output_arguments(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            fprintf(file, ")") ;
            
            fprintf(file, ";") ;
            
            break;
            
        case ret:
            
            if ( ((marshmallow_variable)statement->var_a)->type->root_type == metacollection ) {
                
                output_multiple_returns(context, file, ((marshmallow_variable)statement->var_a)->data, statement->function->signature, module) ;
                
            } else {
                
                output_a_return(context, file, RKList_GetData(RKList_GetFirstNode(statement->function->signature->returns)), 0, statement->function->signature, module, 0) ;
                
                fprintf(file, "=") ;
                
                output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            }
            
            break;
            
        case breakop:
            
            fprintf(file, "break") ;
            
            break;
            
        case continueop:
            
            fprintf(file, "continue") ;
            
            break;
            
        case add:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "+") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case sub:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "-") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case mult:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "*") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case mdiv:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "/") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case assignment:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "=") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case array_assignment:
            
            output_array_assignment(context, file, statement, module) ;
            
            break;
          
        case is_equal:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "==") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;

        case is_not_equal:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "!=") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case is_greaterthan:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, ">") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case is_greaterthan_or_equal:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, ">=") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case is_lessthan:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "<") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case is_lessthan_or_equal:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "<=") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            
            break;
            
        case inc:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "++") ;
            
            break;
            
        case dec:
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            fprintf(file, "--") ;
            
            break;
            
            
        case addrof:
            
            fprintf(file, "&") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            break;
            
        case deref:
            
            fprintf(file, "*") ;
            
            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
            
            break;

            
        default:
            break;
    }
    
    if ( statement->is_expression ) fprintf(file, ")") ;
}

static void output_a_return( marshmallow_context context, FILE* file, marshmallow_variable variable, int n, marshmallow_function_signature signature, marshmallow_module module, int is_definition ) {
    
    char myintstring[100] ;
    
    RKString underscore = rkstr("_") ;
   
    if (is_definition) {
        
    output_type(context, file, variable->type, variable->static_assignment, module) ;
    
    fprintf(file, "* " ) ;
        
    } else {
        
    fprintf(file, "(*" ) ;
        
    }
    
    marshmallow_itoa(n, myintstring) ;
    
    RKString str0 = RKString_NewStringFromCString(myintstring) ;
    
    RKString str1 = RKString_AppendString(rkstr("returns_marshmallow_"), module->name) ;
    
    RKString str2 = RKString_AppendString(str1, underscore) ;
    
    RKString str3 = RKString_AppendString(str2, signature->func_name) ;
    
    RKString str4 = RKString_AppendString(str3, underscore) ;
    
    RKString name = RKString_AppendString(str4, str0) ;
    
    if (is_definition) RKStore_AddItem(context->symbols, name, RKString_GetString(name)) ;
    
    fprintf(file, "%s", RKString_GetString(name)) ;
    
    if (!is_definition) fprintf(file, ")" ) ;
    
    RKString_DestroyString(str0) ;
    
    RKString_DestroyString(name) ;
    
    RKString_DestroyString(underscore) ;
}

static void output_signature( marshmallow_context context, FILE* file, marshmallow_function_signature signature, marshmallow_module module ) {
    
    int n = 0 ;
    
    int has_parameters = 0 ;
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    fprintf(file, "void") ;
    
    fprintf(file, " ") ;
    
    if ( !signature->is_external ) {
        
        output_symbol(context, file, signature->func_name, module, 1, 1) ;
        
    } else {
        
        fprintf(file, "%s", RKString_GetString(signature->func_name)) ;
        
    }
    
    fprintf(file, "(") ;
    
    list = RKStore_GetList(signature->parameters) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            has_parameters = 1 ;
            
            output_variable(context, file, RKList_GetData(node), module, 0, 1) ;
            
            if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }

    list = signature->returns ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        if ( node != NULL  && has_parameters ) fprintf(file, ",") ;
        
        while (node != NULL) {
            
            output_a_return(context, file, RKList_GetData(node), n, signature, module, 1) ;
            
            if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
            
            n++ ;
            
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
                
                if ( !RKString_AreStringsEqual(((marshmallow_function_body)entity)->signature->func_name, rkstr("memcpy")) ) {
                    
                output_signature(context, file, ((marshmallow_function_body)entity)->signature, module) ;
                
                fprintf(file, ")") ;
                    
                }
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
            
            if (((marshmallow_statement)RKList_GetData(node))->op != ifop) fprintf(file, " ;\n") ;
            
            node = RKList_GetNextNode(node) ;
        }
        
    }
    
    fprintf(file, "}") ;
    
    fprintf(file, "\n") ;
}

static void output_main( marshmallow_context context, FILE* file, marshmallow_module module ) {
    
    if ( !RKStore_ItemExists(module->functions_and_methods, "main") ) return ;
    
    if ( context->program_has_main ) {
        
        printf("Multiple main functions. Only one main function can exist in a marshmallow program.\n") ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( !context->program_has_main ) context->program_has_main++ ;
    
    fprintf(file, "int main(int argc, const char **argv) {\n") ;
    
    RKString str0 = rkstr("returns_marshmallow_") ;
    
    RKString str1 = RKString_AppendString(str0, module->name) ;
    
    RKString str2 = RKString_AppendString(str1, rkstr("_main_0")) ;
    
    fprintf(file, "mi32 ") ;
    
    fprintf(file, "%s", RKString_GetString(str2)) ;
    
    fprintf(file, " = 0 ;\n") ;
    
    output_symbol(context, file, rkstr("main"), module, 1, 0) ;
    
    fprintf(file, "(&") ;
    
    fprintf(file, "%s", RKString_GetString(str2)) ;
    
    fprintf(file, ") ;\n") ;
    
    fprintf(file, "return ") ;
    
    fprintf(file, "%s", RKString_GetString(str2)) ;
    
    fprintf(file, "; \n") ;
    
    fprintf(file, "} \n") ;
    
}

static void output_module( marshmallow_context context, FILE* file, marshmallow_module module ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    output_declarations(context, file, module->declarations, module, 1) ;
    
    output_main(context, file, module) ;
    
    list = RKStore_GetList(module->variables) ;
    
    if ( list != NULL ) {
    
      node = RKList_GetFirstNode(list) ;
    
      while (node != NULL) {
        
          output_variable(context, file, RKList_GetData(node), module, 1, 0) ;
        
          fprintf(file, " ;\n") ;
        
          node = RKList_GetNextNode(node) ;
        
      }
    
    }
    
    list = RKStore_GetList(module->functions_and_methods) ;
    
    if ( list != NULL ) {
    
      node = RKList_GetFirstNode(list) ;
    
      while (node != NULL) {
        
          output_function(context, file, RKList_GetData(node), module) ;
        
          node = RKList_GetNextNode(node) ;
        
      }
        
    }
}

static void output_runtime( marshmallow_context context, FILE* file ) {
    
    fprintf(file, "typedef float mf32 ;\n") ;
    
    fprintf(file, "typedef double mf64 ;\n") ;
    
    fprintf(file, "typedef unsigned char mu8 ;\n") ;
    
    fprintf(file, "typedef signed char mi8 ;\n") ;
    
    fprintf(file, "typedef signed short mi16 ;\n") ;
    
    fprintf(file, "typedef unsigned short mu16 ;\n") ;
    
    fprintf(file, "typedef signed int mi32 ;\n") ;
    
    fprintf(file, "typedef unsigned int mu32 ;\n") ;
    
    fprintf(file, "#ifdef _WIN32\n") ;
    
    fprintf(file, "typedef signed long long mi64 ;\n") ;
    
    fprintf(file, "typedef unsigned long long mu64 ;\n") ;
    
    fprintf(file, "#else\n") ;
    
    fprintf(file, "typedef signed long mi64 ;\n") ;
    
    fprintf(file, "typedef unsigned long mu64 ;\n") ;
    
    fprintf(file, "#endif\n") ;
    
    fprintf(file, "void* memcpy(void* dest, const void* src, mu64 n) ;") ;
    
    fprintf(file, "\n") ;
}

static void output_app( marshmallow_context context, FILE* file ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    list = RKStore_GetList(context->modules) ;
    
    if ( list != NULL ) {
    
     node = RKList_GetFirstNode(list) ;
    
     output_runtime(context, file) ;
    
     while (node != NULL) {
        
         output_module(context, file, RKList_GetData(node)) ;
        
         node = RKList_GetNextNode(node) ;
     }
        
    }
}

void marshmallow_codegen( marshmallow_context context, FILE* out_file ) {
    
    RKStore_AddItem(context->symbols, rkstr("item"), "memcpy") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mi8") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mu8") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mi16") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mu16") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mi32") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mu32") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mi64") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mu64") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mf32") ;
    
    RKStore_AddItem(context->symbols, rkstr("item"), "mf64") ;
    
    #define token(word,string) RKStore_AddItem(context->symbols, rkstr("item"), string) ;
    
    #include "marshmallow_tokens.h"
    
    #undef token
    
    output_app(context, out_file) ;
}

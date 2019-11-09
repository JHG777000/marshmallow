/*
 Copyright (c) 2017-2019 Jacob Gordon. All rights reserved.

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

//////////////////OLD CODEGEN(still in use)//////////////////////////////////////////////////
///NEW CODEGEN(line# 1511, see marshmallow_codegen.h)///////////////////////////////////////

 const char* marshmallow_ltoa( RKLong val, char* string ) {

#ifdef _WIN32

    snprintf(string, sizeof(string), "%lld", val) ;

#else

    snprintf(string, sizeof(string), "%ld", val) ;

#endif

    return string ;

}

const char* marshmallow_ultoa( RKULong val, char* string ) {

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

            case string8:

                fprintf(file, "mu8* ") ;

                break;

            case string16:

                fprintf(file, "mu16* ") ;

                break;


            case string32:

                fprintf(file, "mu32* ") ;

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

    fprintf(file, "%s",marshmallow_itoa(*((int*)(RKStore_GetItem(((marshmallow_enum)(value->type->base_type))->enums, RKString_GetString(value->name)))), string)) ;
}

static void output_value( marshmallow_context context, FILE* file, marshmallow_variable value, marshmallow_module module ) {

    if ( value == NULL ) return ;

    if ( value->type->root_type == string ) fprintf(file, "u8\"") ;

    if ( value->type->root_type == string8 && value->type->is_literal ) fprintf(file, "u8\"") ;

    if ( value->type->root_type == string16 && value->type->is_literal ) fprintf(file, "u\"") ;

    if ( value->type->root_type == string32 && value->type->is_literal ) fprintf(file, "U\"") ;

    if ( value->type->root_type == character ) fprintf(file, "L\'") ;

    if ( value->type->root_type == enum_type ) {

        output_enum(context, file, value, module) ;

        return ;
    }

    if ( value->type->root_type == ptr ) {

        if ( ((marshmallow_type)(value->type->base_type))->root_type == nulltype ) {

            fprintf(file, "%s", "((void*)0)") ;

            return ;
        }
    }

    if ( value->type->root_type == array ) {

        if ( ((marshmallow_type)(value->type->base_type))->root_type == inittype ) {

            fprintf(file, "%s", "{0}") ;

            return ;
        }
    }

    if ( value->type->root_type == expression ) {

        output_statement(context, file, value->data, module) ;

        return ;
    }

    if ( value->type->root_type == metacollection ) {

        output_collection(context, file, value->data, module) ;

        return ;
    }

    if ( !value->type->is_literal && value->name != NULL ) {

        output_symbol(context, file, value->name, module, value->is_global, 0) ;

        return ;
    }

    if ( value->data != NULL ) {

         fprintf(file, "%s", RKString_GetString(((marshmallow_value)value->data)->value)) ;
    }

    if ( value->type->root_type == string ) fprintf(file, "\"") ;

    if ( value->type->root_type == string8 && value->type->is_literal ) fprintf(file, "\"") ;

    if ( value->type->root_type == string16 && value->type->is_literal ) fprintf(file, "\"") ;

    if ( value->type->root_type == string32 && value->type->is_literal ) fprintf(file, "\"") ;

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

static void output_multiple_returns( marshmallow_context context, FILE* file, marshmallow_variable the_collection,
                                     marshmallow_function_signature signature, marshmallow_module module ) {

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

                if ( statement->function->signature->is_external )  {

                    fprintf(file, "return ") ;

                    output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

                } else {

                 output_a_return(context, file, RKList_GetData(RKList_GetFirstNode(statement->function->signature->returns)), 0, statement->function->signature, module, 0) ;

                 fprintf(file, "=") ;

                 output_value(context, file, (marshmallow_variable)statement->var_a, module) ;
             }

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

        case not:

            fprintf(file, "!") ;

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            break;

        case bnot:

            fprintf(file, "~") ;

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            break;

        case band:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, "&") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case bor:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, "|") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case xor:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, "^") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case lshift:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, "<<") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case rshift:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, ">>") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;
            break;

        case or:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, "||") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case and:

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            fprintf(file, "&&") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case negate:

            fprintf(file, "-") ;

            output_value(context, file, (marshmallow_variable)statement->var_a, module) ;

            break;

        case castop:

            fprintf(file, "(") ;

            output_type(context, file, ((marshmallow_variable)statement->var_a)->type, NULL, module) ;

            fprintf(file, ")") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

            break;

        case reinterpretop:

            fprintf(file, "*(") ;

            output_type(context, file, ((marshmallow_variable)statement->var_a)->type, NULL, module) ;

            fprintf(file, "*)&") ;

            output_value(context, file, (marshmallow_variable)statement->var_b, module) ;

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

    if ( !signature->is_external || (signature->is_external && (RKList_GetNumOfNodes(signature->returns) == 0))) fprintf(file, "void") ;

    if ( signature->is_external && (RKList_GetNumOfNodes(signature->returns) == 1))
        output_type(context, file, ((marshmallow_variable)RKList_GetData(RKList_GetFirstNode(signature->returns)))->type, NULL, module) ;

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

    if ( signature->is_external ) return ;

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

static void output_runtime( marshmallow_context context, FILE* file ) ;

static void output_module( marshmallow_context context, FILE* file, marshmallow_module module ) {

    RKList list = NULL ;

    RKList_node node = NULL ;

    output_runtime(context, file) ;

    output_declarations(context, file, module->declarations, module, 1) ;

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

static FILE* output_get_module_file( RKString output_dir, marshmallow_module module ) {

    RKString name = rkstr("/module_") ;

    RKString ext = rkstr(".c") ;

    RKString mod_out_file_path = RKString_AppendString(RKString_AppendString(RKString_AppendString(output_dir,name), module->name), ext) ;

    RKString_DestroyString(name) ;

    RKString_DestroyString(ext) ;

    FILE* mod_out_file = fopen(RKString_GetString(mod_out_file_path), "w") ;

    RKString_DestroyString(mod_out_file_path) ;

    return mod_out_file ;
}

static void output_app( marshmallow_context context, const char* out_directory ) {

    RKList list = NULL ;

    RKList_node node = NULL ;

    FILE* file = NULL ;

    list = RKStore_GetList(context->modules) ;

    if ( list != NULL ) {

     node = RKList_GetFirstNode(list) ;

     while (node != NULL) {

         file = output_get_module_file(RKString_NewStringFromCString(out_directory), RKList_GetData(node)) ;

         output_module(context, file, RKList_GetData(node)) ;

         fclose(file) ;

         node = RKList_GetNextNode(node) ;
     }

    }
}

static void cg_output_app( marshmallow_context context, FILE* file ) ;

void marshmallow_codegen( marshmallow_context context, const char* out_directory ) {

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

    #if 1

     output_app(context, out_directory) ;

    #else

     cg_output_app(context, out_file) ;

    #endif
}

//////////////////NEW CODEGEN//////////////////////////////////////////////////

static void name_mangle( cg_module module, cg_variable variable ) {

    RKString name = variable->name ;

    RKString underscore = rkstr("_") ;

    RKString str0 = RKString_AppendString(rkstr("marshmallow_"), module->name) ;

    RKString str1  = RKString_AppendString(str0, underscore) ;

    RKString str2 = RKString_AppendString(str1, name) ;

    variable->name = str2 ;

    RKString_DestroyString(underscore) ;

    RKString_DestroyString(name) ;
}

static cg_variable cg_output_variable( marshmallow_variable variable, cg_routine routine, cg_module module ) {

    marshmallow_type t = NULL ;

    cg_variable v = NULL ;

    marshmallow_type type = variable->type ;

    cg_variable var = cg_new_variable(RKString_CopyString(variable->name),
                                      variable->type->root_type, -1, -1, variable->type->num_of_elements, 0) ;

    if ( variable->is_global && (variable->access_control == public || variable->access_control == publish || variable->is_external) ) var->is_global = 1 ;

    if ( !variable->is_global && variable->is_persistent ) var->is_global = 1 ;

    if ( (type->root_type == ptr) || (type->root_type == array) ) {

        v = var ;

        t = type ;

    loop:

        if ( t != NULL ) {

            v->ptr = cg_new_variable(NULL, t->root_type, -1, -1, t->num_of_elements, 0) ;

            v = v->ptr ;

            t = t->base_type ;

            goto loop ;
        }
    }

    if ( variable->static_assignment != NULL ) {


    }

    if ( routine != NULL ) {

        cg_add_variable_to_routine(var, routine) ;

    }

    if ( routine == NULL ) {

        name_mangle(module, var) ;

        cg_add_variable_to_module(var, module) ;

    }

    return var ;
}

static cg_variable cg_output_literal( RKString value, cg_root_type type, cg_routine routine, cg_module module ) {

    cg_variable literal = cg_new_variable(NULL, type, -1, -1, 0, 0) ;

    literal->value = value ;

    literal->is_literal = 1 ;

    if ( routine != NULL ) cg_add_variable_to_routine(literal, routine) ;

    if ( routine == NULL ) cg_add_variable_to_module(literal, module) ;

    return literal ;
}

static cg_variable cg_output_enum( marshmallow_variable value, cg_routine routine, cg_module module ) {

    char string[100] ;

    return cg_output_literal(RKString_NewStringFromCString(marshmallow_itoa(*((int*)(RKStore_GetItem(((marshmallow_enum)(value->type->base_type))->enums, RKString_GetString(value->name)))), string)), i32, routine, module) ;
}

static cg_variable cg_output_null( cg_routine routine ) {

    cg_variable null = cg_new_variable(NULL, ptr, -1, -1, 0, 0) ;

    null->ptr = cg_new_variable(NULL, nulltype, -1, -1, 0, 0) ;

    null->is_literal = 1 ;

    cg_add_variable_to_routine(null, routine) ;

    return null ;
}

static void cg_output_value( marshmallow_context context, FILE* file, marshmallow_variable value, marshmallow_module module, cg_routine r, cg_module m ) {

    if ( value == NULL ) return ;

    if ( value->type->root_type == string ) {

        cg_output_literal(((marshmallow_value)value->data)->value, string, r, m) ;

    }

    if ( value->type->root_type == string8 && value->type->is_literal ) {

        cg_output_literal(((marshmallow_value)value->data)->value, string8, r, m) ;

    }

    if ( value->type->root_type == string16 && value->type->is_literal ) {

        cg_output_literal(((marshmallow_value)value->data)->value, string16, r, m) ;

    }

    if ( value->type->root_type == string32 && value->type->is_literal ) {

        cg_output_literal(((marshmallow_value)value->data)->value, string32, r, m) ;

    }

    if ( value->type->root_type == character ) {

        cg_output_literal(((marshmallow_value)value->data)->value, character, r, m) ;

    }

    if ( value->type->root_type == ptr ) {

        if ( ((marshmallow_type)(value->type->base_type))->root_type == nulltype ) {

            fprintf(file, "%s", "((void*)0)") ;

            return ;
        }
    }

    if ( value->type->root_type == array ) {

        if ( ((marshmallow_type)(value->type->base_type))->root_type == inittype ) {

            fprintf(file, "%s", "{0}") ;

            return ;
        }
    }

    if ( value->type->root_type == expression ) {

        output_statement(context, file, value->data, module) ;

        return ;
    }

    if ( value->type->root_type == metacollection ) {

        output_collection(context, file, value->data, module) ;

        return ;
    }

    if ( !value->type->is_literal && value->name != NULL ) {

        output_symbol(context, file, value->name, module, value->is_global, 0) ;

        return ;
    }

    if ( value->data != NULL ) {

        fprintf(file, "%s", RKString_GetString(((marshmallow_value)value->data)->value)) ;
    }

}

static void cg_output_module( marshmallow_context context, FILE* file, marshmallow_module module ) {

    RKList list = NULL ;

    RKList_node node = NULL ;

    //output_declarations(context, file, module->declarations, module, 1) ;

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

static void cg_output_app( marshmallow_context context, FILE* file ) {

    RKList list = NULL ;

    RKList_node node = NULL ;

    list = RKStore_GetList(context->modules) ;

    if ( list != NULL ) {

        node = RKList_GetFirstNode(list) ;

        while (node != NULL) {

            cg_output_module(context, file, RKList_GetData(node)) ;

            node = RKList_GetNextNode(node) ;
        }

    }
}

static void validate_definition( cg_context context, cg_routine routine, cg_variable variable ) {

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

    if ( RKStore_ItemExists(context->definitions, RKString_GetString(definition_name)) ) {

        cg_variable v = RKStore_GetItem(context->definitions, RKString_GetString(definition_name)) ;

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

                node2 = RKList_GetNextNode(node2) ;
            }

        }

        RKStore_AddItem(context->definitions, v, RKString_GetString(v->name)) ;

        return ;

    error:

        printf("codegen error: definition '%s', already exists.\n",RKString_GetString(definition_name)) ;

        exit(EXIT_FAILURE) ;
    }

    RKStore_AddItem(context->definitions, definition, RKString_GetString(definition_name)) ;

}

static void DeleteStatementInListOrStore(void* data) {

    cg_destroy_statement(data) ;
}

static void DeleteMlbStatementInListOrStore(void* data) {

    mlb_destroy_statement(data) ;
}

static void DeleteVariableInListOrStore(void* data) {

    if ( ((cg_variable)data)->entity_type != cg_entity_variable ) return ;

    cg_destroy_variable(data) ;
}

static void DeleteRoutineInListOrStore(void* data) {

    cg_destroy_routine(data) ;
}

static void DeleteModuleInListOrStore(void* data) {

    cg_destroy_module(data) ;
}

codegen_backend codegen_new_backend( codegen_backend_type backend_type, const char* out_directory ) {

    codegen_backend backend = RKMem_NewMemOfType(struct codegen_backend_s) ;

    backend->output_dir = RKString_NewStringFromCString(out_directory) ;

    init_backend(C) ;

    return backend ;
}

void codegen_destroy_backend( codegen_backend backend ) {

    backend->destroyer_callback(backend) ;

    RKString_DestroyString(backend->output_dir) ;

    free(backend) ;
}

void cg_give_context_to_backend( cg_context context, codegen_backend backend ) {

    mlb_validate_context(context) ;

    backend->context_callback(context,backend) ;
}

cg_context cg_new_context( void ) {

    cg_context context = RKMem_NewMemOfType(struct cg_context_s) ;

    context->modules = RKStore_NewStore() ;

    context->definitions = RKStore_NewStore() ;

    return context ;
}

void cg_destroy_context( cg_context context ) {

    RKStore_IterateStoreWith(DeleteModuleInListOrStore, context->modules) ;

    RKStore_DestroyStore(context->modules) ;

    RKStore_DestroyStore(context->definitions) ;

    free(context) ;
}

void cg_add_module_to_context( cg_module module, cg_context context ) {

    module->context = context ;

    RKStore_AddItem(context->modules, module, RKString_GetString(module->name)) ;
}

cg_module cg_new_module( RKString name ) {

    cg_module module = RKMem_NewMemOfType(struct cg_module_s) ;

    module->name = name ;

    module->context = NULL ;

    module->classes = RKStore_NewStore() ;

    module->routines = RKStore_NewStore() ;

    module->variables = RKStore_NewStore() ;

    module->entity_type = cg_entity_module ;

    module->routine_declarations = RKStore_NewStore() ;

    module->variable_declarations = RKStore_NewStore() ;

    return module ;
}

void cg_destroy_module( cg_module module ) {

    RKList_node node = NULL ;

    RKStore_IterateStoreWith(DeleteRoutineInListOrStore, module->routines) ;

    node = RKList_GetFirstNode(RKStore_GetList(module->routines)) ;

    while ( node != NULL ) {

        RKStore_RemoveItem(module->routine_declarations, RKString_GetString(RKStore_GetStoreLabelFromListNode(node))) ;

        node = RKList_GetNextNode(node) ;
    }

    RKStore_IterateStoreWith(DeleteVariableInListOrStore, module->variables) ;

    node = RKList_GetFirstNode(RKStore_GetList(module->variables)) ;

    while ( node != NULL ) {

        RKStore_RemoveItem(module->variable_declarations, RKString_GetString(RKStore_GetStoreLabelFromListNode(node))) ;

        node = RKList_GetNextNode(node) ;
    }

    RKStore_IterateStoreWith(DeleteRoutineInListOrStore, module->routine_declarations) ;

    RKStore_IterateStoreWith(DeleteVariableInListOrStore, module->variable_declarations) ;

    RKStore_IterateStoreWith(DeleteVariableInListOrStore, module->classes) ;

    RKStore_DestroyStore(module->routines) ;

    RKStore_DestroyStore(module->variables) ;

    RKStore_DestroyStore(module->routine_declarations) ;

    RKStore_DestroyStore(module->variable_declarations) ;

    RKStore_DestroyStore(module->classes) ;

    RKString_DestroyString(module->name) ;

    free(module) ;
}

void cg_add_class_to_module( cg_variable class, cg_module module ) {

    RKStore_AddItem(module->classes, class, RKString_GetString(class->value)) ;
}

void cg_add_variable_declaration_to_module( cg_variable variable, cg_module module ) {

    validate_definition(module->context, NULL, variable) ;

    RKStore_AddItem(module->variable_declarations, variable, RKString_GetString(variable->name)) ;
}

void cg_add_routine_declaration_to_module( cg_routine routine, cg_module module ) {

    validate_definition(module->context, routine, NULL) ;

    RKStore_AddItem(module->routine_declarations, routine, RKString_GetString(routine->name)) ;
}

void cg_add_variable_to_module( cg_variable variable, cg_module module ) {

    validate_definition(module->context, NULL, variable) ;

    RKStore_AddItem(module->variables, variable, RKString_GetString(variable->name)) ;
}

void cg_add_routine_to_module( cg_routine routine, cg_module module ) {

    validate_definition(module->context, routine, NULL) ;

    routine->module = module ;

    RKStore_AddItem(module->routines, routine, RKString_GetString(routine->name)) ;
}

cg_routine cg_new_routine( RKString name, int is_global ) {

    cg_routine routine = RKMem_NewMemOfType(struct cg_routine_s) ;

    routine->name = name ;

    routine->module = NULL ;

    routine->is_external = 0 ;

    routine->is_global = is_global ;

    routine->entity_type = cg_entity_routine ;

    routine->return_types = RKList_NewList() ;

    routine->parameters = RKStore_NewStore() ;

    routine->variables = RKStore_NewStore() ;

    routine->calls = RKStore_NewStore() ;

    routine->mib_code = RKList_NewList() ;

    routine->mob_code = RKList_NewList() ;

    routine->mlb_code = RKList_NewList() ;

    routine->optimized_mlb_code = NULL ;

    routine->mob_stack = RKStack_NewStack() ;

    routine->mob_call_stack = RKStack_NewStack() ;

    return routine ;
}

void cg_destroy_routine( cg_routine routine ) {

    RKString_DestroyString(routine->name) ;

    if ( routine->return_types != NULL ) {

        RKList_IterateListWith(DeleteVariableInListOrStore, routine->return_types) ;

        RKList_DeleteList(routine->return_types) ;
    }

    if ( routine->parameters != NULL ) {

        RKStore_IterateStoreWith(DeleteVariableInListOrStore, routine->parameters) ;

        RKStore_DestroyStore(routine->parameters) ;
    }

    if ( routine->variables != NULL ) {

        RKStore_IterateStoreWith(DeleteVariableInListOrStore, routine->variables) ;

        RKStore_DestroyStore(routine->variables) ;
    }

    if ( routine->mib_code != NULL ) {

        RKList_IterateListWith(DeleteStatementInListOrStore, routine->mib_code) ;

        RKList_DeleteList(routine->mib_code) ;
    }

    if ( routine->mob_code != NULL ) {

        RKList_IterateListWith(DeleteStatementInListOrStore, routine->mob_code) ;

        RKList_DeleteList(routine->mob_code) ;
    }

    if ( routine->mlb_code != NULL ) {

        RKList_IterateListWith(DeleteMlbStatementInListOrStore, routine->mlb_code) ;

        RKList_DeleteList(routine->mlb_code) ;
    }

    if ( routine->optimized_mlb_code != NULL ) {

        RKList_IterateListWith(DeleteMlbStatementInListOrStore, routine->optimized_mlb_code) ;

        RKList_DeleteList(routine->optimized_mlb_code) ;
    }

    RKStack_DestroyStack(routine->mob_stack) ;

    RKStack_DestroyStack(routine->mob_call_stack) ;

    RKStore_DestroyStore(routine->calls) ;

    free(routine) ;
}

void cg_add_parameter_to_routine( cg_variable parameter, cg_routine routine ) {

    if ( routine->parameters == NULL ) routine->parameters = RKStore_NewStore() ;

    RKStore_AddItem(routine->parameters, parameter, RKString_GetString(parameter->name)) ;
}

void cg_add_return_to_returns_in_routine( cg_variable return_type, cg_routine routine ) {

    if ( routine->return_types == NULL ) routine->return_types = RKList_NewList() ;

    RKList_AddToList(routine->return_types, return_type) ;
}

void cg_add_variable_to_routine( cg_variable variable, cg_routine routine ) {

    if ( routine->variables == NULL ) routine->variables = RKStore_NewStore() ;

    if ( variable->name == NULL && variable->is_literal ) {

        RKStore_AddItemToList(routine->variables, variable) ;

        return ;
    }

    if ( variable->name == NULL && !variable->is_literal ) {

        printf("codegen error: variable has no name.\n") ;

        exit(EXIT_FAILURE) ;
    }

    RKStore_AddItem(routine->variables, variable, RKString_GetString(variable->name)) ;
}

 cg_variable cg_get_variable( cg_routine routine, RKString var ) {

    cg_variable variable = RKStore_GetItem(routine->variables, RKString_GetString(var)) ;

    if ( variable == NULL ) variable = RKStore_GetItem(routine->parameters, RKString_GetString(var)) ;

    if ( variable == NULL ) variable = RKStore_GetItem(routine->module->variables, RKString_GetString(var)) ;

    return variable ;
}

void cg_destroy_statement( cg_statement statement ) {

    free(statement) ;
}

cg_variable cg_new_variable( RKString name, cg_root_type type, int mlb_return_value, int mlb_get_return_value, RKULong num_of_elements, int is_global ) {

    cg_variable variable = RKMem_NewMemOfType(struct cg_variable_s) ;

    variable->mlb_get_return_value = mlb_get_return_value ;

    variable->mlb_return_value = mlb_return_value ;

    variable->num_of_elements = num_of_elements ;

    variable->entity_type = cg_entity_variable ;

    variable->is_global = is_global ;

    variable->is_temporary = 0 ;

    variable->is_literal = 0 ;

    variable->is_const = 0 ;

    variable->class_values = NULL ;

    variable->values = NULL ;

    variable->value = NULL ;

    variable->type = type ;

    variable->name = name ;

    variable->delete_ptr = 1 ;

    variable->ptr = NULL ;

    variable->class_element = NULL ;

    variable->index = -1 ;

    return variable ;
}

void cg_destroy_variable( cg_variable variable ) {

    RKString_DestroyString(variable->name) ;

    if ( variable->value != NULL ) RKString_DestroyString(variable->value) ;

    if ( variable->values != NULL ) RKList_DeleteList(variable->values) ;

    if ( variable->class_values != NULL ) RKStore_IterateStoreWith(DeleteVariableInListOrStore, variable->class_values) ;

    if ( variable->class_values != NULL ) RKStore_DestroyStore(variable->class_values) ;

    if ( variable->class_element != NULL ) RKString_DestroyString(variable->class_element) ;

    if ( variable->ptr != NULL && variable->ptr->type != class && variable->delete_ptr ) cg_destroy_variable(variable->ptr) ;

    free(variable) ;
}

int cg_variables_are_equal( cg_variable a, cg_variable b ) {

loop:

    if ( a->is_global != b->is_global ) return 0 ;

    if ( a->mlb_get_return_value != b->mlb_get_return_value ) return 0 ;

    if ( a->mlb_return_value != b->mlb_return_value ) return 0 ;

    if ( a->num_of_elements != b->num_of_elements ) return 0 ;

    if ( a->type != b->type ) return 0 ;

    if ( a->ptr != NULL ) {

        a = a->ptr ;

        b = b->ptr ;

        goto loop ;
    }

    if ( a->values == NULL && b->values != NULL) return 0 ;

    if ( a->values != NULL && b->values == NULL) return 0 ;

    if ( a->values != NULL ) {

        if ( RKList_GetNumOfNodes(a->values) != RKList_GetNumOfNodes(b->values) ) return 0 ;

        RKList_node node = RKList_GetFirstNode(a->values) ;

        RKList_node node2 = RKList_GetFirstNode(b->values) ;

        while ( node != NULL ) {

            if ( !cg_variables_are_equal(RKList_GetData(node),RKList_GetData(node2)) ) return 0 ;

            node = RKList_GetNextNode(node) ;

            node2 = RKList_GetNextNode(node2) ;
        }
    }

    if ( a->class_values == NULL && b->class_values != NULL) return 0 ;

    if ( a->class_values != NULL && b->class_values == NULL) return 0 ;

    if ( a->class_values != NULL ) {

        if ( RKList_GetNumOfNodes(RKStore_GetList(a->class_values)) != RKList_GetNumOfNodes(RKStore_GetList(b->class_values)) ) return 0 ;

        RKList_node node = RKList_GetFirstNode(RKStore_GetList(a->class_values)) ;

        while ( node != NULL ) {

            if ( !cg_variables_are_equal(RKList_GetData(node),RKStore_GetItem(b->class_values,RKString_GetString(RKStore_GetStoreLabelFromListNode(node))))) return 0 ;

            node = RKList_GetNextNode(node) ;

        }
    }

    return 1 ;
}

cg_variable cg_new_class( RKString class_name, cg_module module ) {

    cg_variable new_class = cg_new_variable(class_name, class, -1, -1, 0, 0) ;

    new_class->value = RKString_CopyString(class_name) ;

    new_class->class_values = RKStore_NewStore() ;

    cg_add_class_to_module(new_class, module) ;

    return new_class ;
}

void cg_add_class_element( cg_variable element, cg_variable class ) {

    RKStore_AddItem(class->class_values, element, RKString_GetString(element->name)) ;
}

cg_variable cg_get_class_element( RKString element, cg_variable class_var ) {

    cg_variable class_element = cg_new_variable(NULL, i8, -1, -1, 0, 0) ;

    class_element->class_element = element ;

    class_element->is_literal = 1 ;

    class_element->delete_ptr = 0 ;

    class_element->ptr = class_var ;

    return class_element ;
}

cg_variable cg_get_array_index( int index, cg_variable array_var ) {

    cg_variable array_index = cg_new_variable(NULL, i8, -1, -1, 0, 0) ;

    array_index->index = index ;

    array_index->is_literal = 1 ;

    array_index->delete_ptr = 0 ;

    array_index->ptr = array_var ;

    return array_index ;
}

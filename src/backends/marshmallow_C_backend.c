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

typedef struct c_backend_s { RKStore banned_symbols ; cg_routine memcpy_routine ; } *c_backend ;

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

static RKString get_struct_name_for_routines_returns( RKString routine_name )  ;

static RKString get_routines_returns_name_from_index( RKInt index ) ;

static void output_routine( FILE* file, cg_routine routine, c_backend c ) ;

static void output_classes( FILE* file, cg_module module, c_backend c ) ;

static void output_class( FILE* file, cg_variable class, c_backend c ) ;

static void output_statement( FILE* file, mlb_statement statement, cg_routine* last_routine_to_be_called_ptr ) ;

static void output_declarations( FILE* file, RKStore declarations, c_backend c ) ;

static void output_value( FILE* file, cg_variable value, void* static_assignment, cg_routine routine ) ;

static void output_collection( FILE* file, cg_variable value ) ;

static void output_type( FILE* file, cg_variable type, void* static_assignment ) ;

static void output_array( FILE* file, cg_variable type, void* static_assignment ) ;

static void output_variable_name( FILE* file, cg_variable variable, c_backend c ) ;

static void output_variable_definition( FILE* file, cg_variable variable, int can_be_static, c_backend c, int no_static_assignment ) ;

static void output_signature( FILE* file, cg_routine routine, int output_returns_struct, c_backend c ) ;

static void output_declarations( FILE* file, RKStore declarations, c_backend c ) ;

static void output_runtime( FILE* file ) ;

static void output_routine( FILE* file, cg_routine routine, c_backend c ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    cg_routine last_routine_to_be_called = NULL ;
    
    output_signature(file, routine, 0, c) ;
    
    fprintf(file, " {\n") ;
    
    list = RKStore_GetList(routine->calls) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            if ( !((cg_routine)RKList_GetData(node))->is_external ) {
            
            fprintf(file, "struct _") ;
            
            RKString returns_type_name = get_struct_name_for_routines_returns(((cg_routine)RKList_GetData(node))->name) ;
            
            fprintf(file, "%s ", RKString_GetString(returns_type_name)) ;
            
            RKString_DestroyString(returns_type_name) ;
            
            fprintf(file, "_%s",RKString_GetString(((cg_routine)RKList_GetData(node))->name)) ;
            
            fprintf(file, "_get_returns") ;
            
            fprintf(file, " ;\n") ;
                
            } else if ( RKList_GetNumOfNodes(((cg_routine)RKList_GetData(node))->return_types) > 0 ) {
                
                output_type(file, RKList_GetData(RKList_GetFirstNode(((cg_routine)RKList_GetData(node))->return_types)), NULL) ;
                
                fprintf(file, "_%s",RKString_GetString(((cg_routine)RKList_GetData(node))->name)) ;
                
                fprintf(file, "_get_returns") ;
                
                fprintf(file, " ;\n") ;
            }
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
    list = RKStore_GetList(routine->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
            
            if ( !((cg_variable)RKList_GetData(node))->is_literal ) {
            
             ((cg_variable)RKList_GetData(node))->is_global = !((cg_variable)RKList_GetData(node))->is_global ;
            
             output_variable_definition(file, RKList_GetData(node), 1, c, 0) ;
             
             if ( ((cg_variable)RKList_GetData(node))->mlb_return_value < 0 && ((cg_variable)RKList_GetData(node))->mlb_get_return_value < 0 )
                 
                 fprintf(file, " ;\n") ;
            
             }
                
            node = RKList_GetNextNode(node) ;
        }
    }
    
    list = routine->mlb_code ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while ( node != NULL ) {
           
            output_statement(file, RKList_GetData(node),&last_routine_to_be_called) ;
            
            node = RKList_GetNextNode(node) ;
        }
    }
    
    fprintf(file, "}\n") ;
}

static void output_classes( FILE* file, cg_module module, c_backend c ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( module->classes != NULL ) {
        
        list = RKStore_GetList(module->classes) ;
        
        if ( list != NULL ) {
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_type(file, RKList_GetData(node), NULL) ;
                
                fprintf(file, "; \n") ;
                
                node = RKList_GetNextNode(node) ;
            }
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_class(file, RKList_GetData(node), c) ;
                
                fprintf(file, " ;\n") ;
                
                node = RKList_GetNextNode(node) ;
            }
        }
        
    }
}

static void output_class( FILE* file, cg_variable class, c_backend c ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( class->class_values != NULL ) {
        
        list = RKStore_GetList(class->class_values) ;
        
        if ( list != NULL ) {
            
            output_type(file, class, NULL) ;
            
            fprintf(file, "{ ") ;
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_variable_definition(file, RKList_GetData(node), 0, c, 1) ;
                
                fprintf(file, " ; ") ;
                
                node = RKList_GetNextNode(node) ;
            }
            
            fprintf(file, "}") ;
            
        }
        
    }
}

static void output_statement( FILE* file, mlb_statement statement, cg_routine* last_routine_to_be_called_ptr ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    cg_routine last_routine_to_be_called = NULL ;
    
    switch (statement->op) {
            
        case cg_endif:
        case cg_endswitch:
            
            fprintf(file, "}") ;
            
            break;
            
        case cg_else:
            
            fprintf(file, "} else {") ;
            
            break;
            
        case cg_endcase:
            
            fprintf(file, "break") ;
            
            break;
            
        case cg_default:
            
            fprintf(file, "default:") ;
            
            break;
            
        case cg_return:

            fprintf(file, "return") ;
            
            break;
            
        case cg_if:
            
            fprintf(file, "if (") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ") {") ;
            
            break;
            
        case cg_else_if:
            
            fprintf(file, "} else if (") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ") {") ;
            
            break;
            
        case cg_switch:
            
            fprintf(file, "switch (") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ") {") ;
            
            break;
            
        case cg_case:
            
            fprintf(file, "case ") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ":") ;
            
            break;
            
        case cg_section:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ":") ;
            
            break;
            
        case cg_goto:
            
            fprintf(file, "goto ") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case mlb_external_return:
            
            fprintf(file, "return ") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_call:

            list = statement->A->values ;
            
            if ( list != NULL ) {
                
              node = RKList_GetFirstNode(statement->A->values) ;
                
              last_routine_to_be_called = RKList_GetData(node) ;
              
              if ( last_routine_to_be_called->is_external ) {
                  
                  if ( RKList_GetNumOfNodes(last_routine_to_be_called->return_types) > 0 ) {
                      
                      fprintf(file, "_%s",RKString_GetString(last_routine_to_be_called->name)) ;
                      
                      fprintf(file, "_get_returns = ") ;
                      
                  }
              }
                
              fprintf(file, "%s(",RKString_GetString(last_routine_to_be_called->name)) ;
            
              node = RKList_GetNextNode(node) ;
              
              if ( !last_routine_to_be_called->is_external ) {
                  
                  fprintf(file, "&_%s",RKString_GetString(last_routine_to_be_called->name)) ;
                  
                  fprintf(file, "_get_returns") ;
                  
                  if ( RKStore_GetNumOfItems(last_routine_to_be_called->parameters) > 0 ) fprintf(file, ",") ;
              }
                
              while ( node != NULL ) {
                
                 output_value(file, RKList_GetData(node), NULL, *last_routine_to_be_called_ptr) ;
                
                 if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
                  
                 node = RKList_GetNextNode(node) ;
              }
                
                fprintf(file, ")") ;
            }
            
            *last_routine_to_be_called_ptr = last_routine_to_be_called ;
            
            break;
            
        case mlb_set:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_sizeof:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = sizeof(") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ")") ;
            
            break;
            
        case cg_not:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ~") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_logic_not:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = !") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_deref:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = *") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_addrof:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = &") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_array_copy:
            
            fprintf(file, "memcpy(") ;
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ",") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, ",sizeof(") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, "))") ;
            
            break;
            
        case cg_cast:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            fprintf(file, " ( ") ;
            
            output_type(file, statement->B, NULL) ;
            
            fprintf(file, " ) ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_add:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " + ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_sub:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " - ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_mult:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " * ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_div:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " / ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_rem:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " %% ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_rshift:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " >> ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_lshift:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " << ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_and:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " & ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_or:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " | ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_xor:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " ^ ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_logic_and:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " && ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_logic_or:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " || ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_equals:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " == ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_not_equals:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " != ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_greaterthan:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " > ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_lessthan:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " < ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_greaterthan_or_equals:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " >= ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        case cg_lessthan_or_equals:
            
            output_value(file, statement->A, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " = ") ;
            
            output_value(file, statement->B, NULL, *last_routine_to_be_called_ptr) ;
            
            fprintf(file, " <= ") ;
            
            output_value(file, statement->C, NULL, *last_routine_to_be_called_ptr) ;
            
            break;
            
        default:
            break;
    }
    
    fprintf(file, " ;\n") ;
}

static void output_value( FILE* file, cg_variable value, void* static_assignment, cg_routine routine ) {
    
    char val[100] ;
    
    if ( value == NULL ) return ;
    
    if ( value->type == string ) fprintf(file, "u8\"") ;
    
    if ( value->type == string8 && value->is_literal ) fprintf(file, "u8\"") ;
    
    if ( value->type == string16 && value->is_literal ) fprintf(file, "u\"") ;
    
    if ( value->type == string32 && value->is_literal ) fprintf(file, "U\"") ;
    
    if ( value->type == character ) fprintf(file, "L\'") ;
    
    if ( value->type == ptr ) {
        
        if ( value->ptr->type == nulltype && value->is_literal ) {
            
            fprintf(file, "%s", "((void*)0)") ;
            
            return ;
        }
        
        if ( value->ptr->type == nulltype && !value->is_literal ) {
            
            printf("codegen error: null must be a literal.\n") ;
            
            exit(EXIT_FAILURE) ;
        }
    }
    
    if ( value->class_element != NULL ) {
        
        output_value(file, value->ptr, NULL, routine) ;
        
        fprintf(file, ".") ;
        
        fprintf(file, "%s", RKString_GetString(value->class_element)) ;
    }
    
    if ( value->index >= 0 ) {
        
        output_value(file, value->ptr, NULL, routine) ;
        
        marshmallow_uitoa(value->index, val) ;
        
        fprintf(file, "[") ;
        
        fprintf(file, "%s", val) ;
        
        fprintf(file, "]") ;
    }
 
    if ( !value->is_literal && value->name != NULL && static_assignment == NULL && value->mlb_return_value >= 0 ) {
        
        RKString returns_index_string = get_routines_returns_name_from_index(value->mlb_return_value) ;
        
        fprintf(file, "_returns->%s", RKString_GetString(returns_index_string)) ;
        
        RKString_DestroyString(returns_index_string) ;
        
        return ;
    }
    
    if ( !value->is_literal && value->name != NULL && static_assignment == NULL && value->mlb_get_return_value >= 0 ) {
        
        if ( routine == NULL ) {
            
            printf("codegen error: used a get_return before a routine is called.\n") ;
            
            exit(EXIT_FAILURE) ;
        }
        
        RKString get_returns_index_string = get_routines_returns_name_from_index(value->mlb_get_return_value) ;
        
        fprintf(file, "_%s",RKString_GetString(routine->name)) ;
        
        fprintf(file, "_get_returns") ;
        
        if (!routine->is_external) fprintf(file, ".%s", RKString_GetString(get_returns_index_string)) ;
        
        RKString_DestroyString(get_returns_index_string) ;
        
        return ;
    }
    
    if ( !value->is_literal && value->name != NULL && static_assignment == NULL ) {
        
        fprintf(file, "%s", RKString_GetString(value->name)) ;
        
        return ;
    }
    
    if ( value->values != NULL ) {
        
        output_collection( file, value ) ;
        
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

static void output_collection( FILE* file, cg_variable value ) {
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    if ( value->values != NULL ) {
        
        list = value->values ;
        
        if ( list != NULL ) {
            
            fprintf(file, "{") ;
            
            node = RKList_GetFirstNode(list) ;
            
            while (node != NULL) {
                
                output_value(file, RKList_GetData(node), NULL, NULL) ;
                
                if ( RKList_GetNextNode(node) != NULL ) fprintf(file, ",") ;
                
                node = RKList_GetNextNode(node) ;
            }
            
            fprintf(file, "}") ;
            
        }
        
    }
}

static void output_type( FILE* file, cg_variable type, void* static_assignment ) {
    
    cg_variable t = type ;
    
    if ( t->is_const ) fprintf(file, "const ") ;
    
loop:
    
    if ( (t->type == ptr) || (t->type == array)  ) t = t->ptr ;
    
    if ( t->is_const ) fprintf(file, "const ") ;
    
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
                
            case blank:
                
                fprintf(file, "void ") ;
                
                break;
                
            case ptrsize:
                
                fprintf(file, "_mu64 ") ;
                
                break;
                
            case class:
                
                fprintf(file, "struct ") ;
                
                if ( t->ptr == NULL ) fprintf(file, "%s ", RKString_GetString(t->value)) ;
                
                if ( t->ptr != NULL ) fprintf(file, "%s ", RKString_GetString(t->ptr->value)) ;
                
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

static void output_variable_definition( FILE* file, cg_variable variable, int can_be_static, c_backend c, int no_static_assignment ) {
    
    if ( variable->mlb_return_value >= 0 || variable->mlb_get_return_value >= 0 ) return ;
    
    if ( !variable->is_global && can_be_static ) fprintf(file, "static ") ;
    
    output_type(file, variable, get_static_assignment(variable)) ;
    
    output_variable_name(file, variable, c) ;
    
    output_array(file, variable, get_static_assignment(variable)) ;
    
    if ( get_static_assignment(variable) != NULL && !no_static_assignment ) {
        
        fprintf(file, " ") ;
        
        fprintf(file, "=") ;
        
        fprintf(file, " ") ;
        
        output_value(file, variable, get_static_assignment(variable), NULL) ;
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
    
    RKString string_index = RKString_NewStringFromCString(string) ;
    
    RKString returns_index = RKString_AppendString(rkstr("_returns_"),string_index) ;
    
    RKString_DestroyString(string_index) ;
    
    return returns_index ;
}

static void output_signature( FILE* file, cg_routine routine, int output_returns_struct, c_backend c ) {
    
    int i = 0 ;
    
    RKList_node node = NULL ;
    
    RKString returns_index = NULL ;
    
    RKString returns_type_name = get_struct_name_for_routines_returns(routine->name) ;
    
    if ( !routine->is_external && output_returns_struct) {
        
         fprintf(file, "struct _") ;
        
         fprintf(file, "%s",RKString_GetString(returns_type_name)) ;
        
         fprintf(file, " { ") ;
        
         node = RKList_GetFirstNode(routine->return_types) ;
        
        while ( node != NULL ) {
            
            output_type(file, RKList_GetData(node), NULL) ;
            
            returns_index = get_routines_returns_name_from_index(i) ;
            
            fprintf(file, "%s", RKString_GetString(returns_index)) ;
            
            RKString_DestroyString(returns_index) ;
            
            output_array(file, RKList_GetData(node), NULL) ;
            
            fprintf(file, " ; ") ;
            
            node = RKList_GetNextNode(node) ;
            
            i++ ;
        }
        
         fprintf(file, "} ;\n") ;
        
         if ( !routine->is_global ) fprintf(file, "static ") ;
        
         fprintf(file, "void ") ;
    }
    
    if ( !routine->is_external && !output_returns_struct) {
        
        if ( !routine->is_global ) fprintf(file, "static ") ;
        
        fprintf(file, "void ") ;
    }
    
    if ( routine->is_external ) {
        
        if ( RKList_GetNumOfNodes(routine->return_types) == 0 ) {
            
            if ( !routine->is_global ) fprintf(file, "static ") ;
            
            fprintf(file, "void ") ;
            
        } else if ( RKList_GetNumOfNodes(routine->return_types) == 1 ) {
            
            if ( !routine->is_global ) fprintf(file, "static ") ;
            
            output_type(file, RKList_GetData(RKList_GetFirstNode(routine->return_types)), NULL) ;
            
        } else if ( RKList_GetNumOfNodes(routine->return_types) > 1 ) {
            
            printf("codegen error: external routine '%s', can only have one return.\n",RKString_GetString(routine->name)) ;
            
            exit(EXIT_FAILURE) ;
        }
        
    }
    
    fprintf(file, "%s",RKString_GetString(routine->name)) ;
    
    fprintf(file, "(") ;
    
    if ( !routine->is_external ) {
        
        fprintf(file, "struct _") ;
        
        fprintf(file, "%s",RKString_GetString(returns_type_name)) ;
        
        fprintf(file, "* _returns") ;
        
        if ( RKStore_GetNumOfItems(routine->parameters) > 0 ) fprintf(file, ",") ;
    }
    
    node = RKList_GetFirstNode(RKStore_GetList(routine->parameters)) ;
    
    while ( node != NULL ) {
        
        output_variable_definition(file, RKList_GetData(node), 0, c, 1) ;
        
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
                
                output_variable_definition(file, RKList_GetData(node), 0, c, 1) ;
                
            } else if ( entity->entity_type == cg_entity_routine ) {
                
                output_signature(file, RKList_GetData(node), 1, c) ;

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
    
    output_runtime(file) ;
    
    output_classes(file, module, c) ;
    
    output_declarations(file, module->variable_declarations, c) ;
    
    output_declarations(file, module->routine_declarations, c) ;
    
    list = RKStore_GetList(module->variables) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            if ( !((cg_variable)RKList_GetData(node))->is_literal ) {
            
             output_variable_definition(file, RKList_GetData(node), 1, c, 0) ;
            
             fprintf(file, " ;\n") ;
            
            }
                
            node = RKList_GetNextNode(node) ;
            
        }
        
    }
    
    list = RKStore_GetList(module->routines) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            output_routine(file, RKList_GetData(node), c) ;
            
            node = RKList_GetNextNode(node) ;
            
        }
        
    }
}

static FILE* output_get_module_file( RKString output_dir, cg_module module ) {
    
    RKString name = rkstr("/module_") ;
    
    RKString ext = rkstr(".c") ;
    
    RKString mod_out_file_path = RKString_AppendString(RKString_AppendString(RKString_AddStrings(output_dir,name), module->name), ext) ;
    
    RKString_DestroyString(name) ;
    
    RKString_DestroyString(ext) ;
    
    FILE* mod_out_file = fopen(RKString_GetString(mod_out_file_path), "w") ;
    
    RKString_DestroyString(mod_out_file_path) ;
    
    return mod_out_file ;
}

static void output_app( RKString output_dir, cg_context context, c_backend c ) {
    
    int i = 0 ;
    
    RKList list = NULL ;
    
    RKList_node node = NULL ;
    
    FILE* file = NULL ;
    
    list = RKStore_GetList(context->modules) ;
    
    if ( list != NULL ) {
        
        node = RKList_GetFirstNode(list) ;
        
        while (node != NULL) {
            
            file = output_get_module_file(output_dir, RKList_GetData(node)) ;
            
            if ( i == 0 ) cg_add_routine_declaration_to_module(c->memcpy_routine, RKList_GetData(node)) ;
            
            output_module(file, context, c, RKList_GetData(node)) ;
            
            fclose(file) ;
            
            node = RKList_GetNextNode(node) ;
            
            i++ ;
        }
        
    }
}

get_context(C) {
    
    output_app(backend->output_dir, context, backend->backend_ptr) ;
}

get_builder(C) {
    
    
}

static void DeleteStringInListOrStore(void* data) {
    
    RKString_DestroyString(data) ;
}

get_destroyer(C) {
    
    RKStore_IterateStoreWith(DeleteStringInListOrStore, ((c_backend)backend->backend_ptr)->banned_symbols) ;
    
    RKStore_DestroyStore(((c_backend)backend->backend_ptr)->banned_symbols) ;
    
    free(backend->backend_ptr) ;
}

new_backend(C) {
    
    backend->size_callback = get_callback(C,return_pointer_size) ;
    
    backend->context_callback = get_callback(C,get_context) ;
    
    backend->builder_callback = get_callback(C,get_builder) ;
    
    backend->destroyer_callback = get_callback(C, get_destroyer) ;
    
    c_backend c = RKMem_NewMemOfType(struct c_backend_s) ;
    
    c->banned_symbols = RKStore_NewStore() ;
    
    backend->backend_ptr = c ;
    
    cg_routine memcpy_routine = cg_new_routine(rkstr("memcpy"), 1) ;
    
    memcpy_routine->is_external = 1 ;
    
    cg_variable ret = cg_new_variable(NULL, ptr, -1, -1, 0, 0) ;
    
    ret->ptr = cg_new_variable(NULL, blank, -1, -1, 0, 0) ;
    
    cg_add_return_to_returns_in_routine(ret, memcpy_routine) ;
    
    cg_variable dest = cg_new_variable(rkstr("dest"), ptr, -1, -1, 0, 0) ;
    
    dest->ptr = cg_new_variable(NULL, blank, -1, -1, 0, 0) ;
    
    cg_variable src = cg_new_variable(rkstr("src"), ptr, -1, -1, 0, 0) ;
    
    src->ptr = cg_new_variable(NULL, blank, -1, -1, 0, 0) ;
    
    src->ptr->is_const = 1 ;
    
    cg_variable n = cg_new_variable(rkstr("n"), ptrsize, -1, -1, 0, 0) ;
    
    cg_add_parameter_to_routine(dest, memcpy_routine) ;
    
    cg_add_parameter_to_routine(src, memcpy_routine) ;
    
    cg_add_parameter_to_routine(n, memcpy_routine) ;
    
    mlb_validate_routine(memcpy_routine) ;
    
    c->memcpy_routine = memcpy_routine ;
    
    RKStore_AddItem(c->banned_symbols, rkstr("memcpy"), "memcpy") ;
}

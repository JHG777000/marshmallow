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


static int marshmallow_is_symbol( char c, int balance ) {
    
    if ( balance == 0 ) if ( c == '.' ) return 1 ;
    
    if ( c == '(' ) return 1 ;
    
    if ( c == ')' ) return 1 ;
    
    if ( c == '"' ) return 1 ;
    
    if ( c == '\'' ) return 1 ;
    
    if ( c == '*' ) return 1 ;
    
    if ( c == '&' ) return 1 ;
    
    if ( c == ',' ) return 1 ;
    
    if ( c == '+' ) return 1 ;
    
    if ( c == '-' ) return 1 ;
    
    if ( c == '/' ) return 1 ;
    
    if ( c == '%' ) return 1 ;
    
    if ( c == '$' ) return 1 ;
    
    if ( c == '#' ) return 1 ;
    
    if ( c == '!' ) return 1 ;
    
    if ( c == '|' ) return 1 ;
    
    if ( c == '@' ) return 1 ;
    
    if ( c == '=' ) return 1 ;
    
    if ( c == '[' ) return 1 ;
    
    if ( c == ']' ) return 1 ;
    
    if ( c == '{' ) return 1 ;
    
    if ( c == '}' ) return 1 ;
    
    return 0 ;
}

static int marshmallow_is_token_root_type( marshmallow_token token ) {
    
    switch (token->keyword) {
            
        case mgk(i8type):
            
            return 1 ;
            
            break;
            
        case mgk(u8type):
            
            return 1 ;
            
            break;
            
        case mgk(i16type):
            
            return 1 ;
            
            break;
            
        case mgk(u16type):
            
            return 1 ;
            
            break;
            
        case mgk(i32type):
            
            return 1 ;
            
            break;
            
        case mgk(u32type):
            
            return 1 ;
            
            break;
            
        case mgk(i64type):
            
            return 1 ;
            
            break;
            
        case mgk(u64type):
            
            return 1 ;
            
            break;
            
        case mgk(hex):
            
            return 1 ;
            
            break;
            
        case mgk(string):
            
            return 1 ;
            
            break;
            
        case mgk(floattype):
            
            return 1 ;
            
            break;
            
        case mgk(doubletype):
            
            return 1 ;
            
            break;
            
        default:
            break;
    }
    
    return 0 ;
}

static marshmallow_token marshmallow_get_token( RKList_node node ) {
    
    static marshmallow_token token = NULL ;
    
    if ( node == NULL ) {
        
        if ( token == NULL ) {
            
            token = RKMem_NewMemOfType(struct marshmallow_token_s) ;
            
            token->keyword = mgk(end_of_line) ;
            
            token->value = rkstr("end_of_line") ;
        }
        
        return token ;
    }
    
    return RKList_GetData(node) ;
}

#define m_processor(name) static void* name##processor( marshmallow_context context, RKList symbol_list, RKList_node* startnode, int index )

#define m_process(name) name##processor(context,symbol_list,startnode,index)

#define m_accept(symbol) marshmallow_accept_or_expect(*startnode,rkstr(#symbol),mgk(symbol),0)

#define m_expect(symbol) marshmallow_accept_or_expect(*startnode,rkstr(#symbol),mgk(symbol),1)

#define m_expectN(n,symbol) marshmallow_accept_or_expect(RKList_GetNextNodeAfterN(*startnode,n),rkstr(#symbol),mgk(symbol),1)

#define m_advance *startnode = RKList_GetNextNode(*startnode)

#define m_advanceN(n) *startnode = RKList_GetNextNodeAfterN(*startnode,n)

#define m_reset *startnode = RKList_GetFirstNode(symbol_list)

#define m_gettoken (marshmallow_get_token(*startnode))

#define m_peek(n) (marshmallow_get_token(RKList_GetNextNodeAfterN(*startnode,n)))

int marshmallow_accept_or_expect( RKList_node startnode, RKString symbol_name, marshmallow_keyword symbol, int expect ) {
    
    marshmallow_token token = NULL ;
    
    if ( startnode == NULL ) {
        
        token = marshmallow_get_token(NULL) ;
    }
    
    if ( token == NULL ) token = RKList_GetData(startnode) ;
    
    if (expect) if ( symbol != token->keyword ) {
        
        printf("Error: expected %s, %s is not %s.\n",RKString_GetString(symbol_name),RKString_GetString(token->value),RKString_GetString(symbol_name)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( symbol == token->keyword ) return 1 ;
    
    return 0 ;
}

static int is_assignment( RKList_node* startnode, int n ) {
    
    if ( m_peek(n+0)->keyword == mgk(colon) ) {
        
        if ( m_peek(n+1)->keyword == mgk(eql) ) {
            
            return 1 ;
        }
    }
    
    return 0 ;
}

m_processor(type) ;

m_processor(variable) ;

m_processor(expression) ;

m_processor(assignment) ;

m_processor(arguments) {
    
    int n = 0 ;
    
    marshmallow_variable argument = NULL ;
    
    marshmallow_variable args = marshmallow_new_variable() ;
    
    args->type = marshmallow_new_type() ;
    
    args->type->root_type = arguments ;
    
    args->data = RKList_NewList() ;
   
    if ( m_peek(1)->keyword == mgk(pleft) ) {
        
        if ( m_peek(2)->keyword == mgk(pright) ) {
            
            m_advanceN(3) ;
            
            m_expect(end_of_line) ;
            
        } else {
            
            m_advanceN(2) ;
            
        add_argument:
            
            argument = m_process(expression) ;
            
            RKList_AddToList(args->data, argument) ;
            
            if ( m_peek(n+0)->keyword == mgk(comma) ) {
                
                n += 1 ;
                
                m_advanceN(n) ;
                
                n = 0 ;
                
                goto add_argument ;
            }
            
            m_expect(end_of_line) ;
        }
        
    } else {
        
        m_advanceN(2) ;
        
        m_expect(end_of_line) ;
    }
    
    return args ;
}

m_processor(function) {
    
    int n = 0 ;
    
    int is_first_parameter = 1 ;
    
    marshmallow_function_signature signature = marshmallow_new_function_signature(NULL, 0) ;
    
    marshmallow_function_body function = marshmallow_new_function_body(signature) ;
    
    marshmallow_variable variable = NULL ;
    
    if ( m_gettoken->keyword == mgk(external) ) {
        
        signature->is_external = 1 ;
        
        m_advanceN(1) ;
    }
    
    if ( m_peek(1)->keyword == mgk(identifier) ) {
        
        signature->func_name = RKString_CopyString(m_peek(1)->value) ;
        
    } else {
        
        m_expect(identifier) ;
    }
    
    if ( m_peek(2)->keyword == mgk(pleft) ) {
        
        if ( m_peek(3)->keyword == mgk(pright) ) {
            
            m_advanceN(4) ;
            
            if ( m_gettoken->keyword == mgk(returns) )  goto add_the_returns ;
            
            m_expect(end_of_line) ;
            
        } else {
            
            m_advanceN(3) ;
            
        add_parameter:
            
            variable = m_process(variable) ;
            
            if ( variable->entity_type != entity_variable ) {
                
                printf("Unknown entity in function or method definition. Not a parameter in function or method: '%s'.\n", RKString_GetString(signature->func_name)) ;
                
                exit(EXIT_FAILURE) ;
            }
            
            marshmallow_add_parameter_to_function(signature, variable, is_first_parameter) ;
            
            is_first_parameter = 0 ;
            
            if ( m_peek(n+0)->keyword == mgk(comma) ) {
                
                n += 1 ;
                
                m_advanceN(n) ;
                
                n = 0 ;
                
                goto add_parameter ;
            }
            
            m_expect(pright) ;
            
            m_advanceN(1) ;
           
            if ( m_gettoken->keyword == mgk(returns) )  goto add_the_returns ;
            
            m_expect(end_of_line) ;
        }
        
    } else {
        
        m_advanceN(2) ;
        
        if ( m_gettoken->keyword == mgk(returns) )  goto add_the_returns ;
            
        m_expect(end_of_line) ;
    }
    
add_the_returns:
    
    if ( m_gettoken->keyword == mgk(returns) ) {
        
        n = 0 ;
        
        m_advanceN(1) ;
        
    add_return:
        
        if ( m_gettoken->keyword != mgk(identifier) && !marshmallow_is_token_root_type(m_gettoken) ) {
            
            printf("Error: expected type name in returns. Got: '%s'.\n",RKString_GetString(m_gettoken->value)) ;
            
            exit(EXIT_FAILURE) ;
        }
        
        variable = m_process(type) ;
        
        if ( variable->entity_type != entity_variable ) {
            
            printf("Unknown entity in function or method definition. Not a retunrs in function or method: '%s'.\n", RKString_GetString(signature->func_name)) ;
            
            exit(EXIT_FAILURE) ;
        }
        
        marshmallow_add_return_to_function_return_list(signature, variable) ;
        
        if ( m_peek(n+0)->keyword == mgk(comma) ) {
            
            n += 1 ;
            
            m_advanceN(n) ;
            
            n = 0 ;
            
            goto add_return ;
        }
    }
    
    m_expect(end_of_line) ;
    
    return function ;
}

m_processor(goto) ;

m_processor(if) ;

m_processor(while) ;

m_processor(statement) {
    
    switch (m_peek(0)->keyword) {
            
        case mgk(pleft):
            
            return m_process(assignment) ;
            
            break;
          
        case mgk(goto):
            
            return m_process(goto) ;
            
            break;
            
        case mgk(if):
            
            return m_process(if) ;
            
            break;
            
        case mgk(while):
            
            return m_process(while) ;
            
            break;
            
        default:
            break;
    }
    
    printf("Expected statement. '%s' is not a statement.\n",RKString_GetString(m_peek(0)->value)) ;
    
    exit(EXIT_FAILURE) ;
    
    return NULL ;
}

m_processor(section) {
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    if ( m_peek(0)->keyword == mgk(section) ) {
       
        if ( m_peek(1)->keyword == mgk(identifier) ) {
            
            marshmallow_parse_value(m_peek(1), a) ;
            
            m_advanceN(2) ;
            
            m_expect(end_of_line) ;
            
            return marshmallow_new_statement(section, 0, (marshmallow_entity)a, NULL) ;
        }
        
        m_expect(identifier) ;
    }
    
    m_expect(section) ;
    
    return NULL ;
}

m_processor(goto) {
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    if ( m_peek(0)->keyword == mgk(goto) ) {
        
        if ( m_peek(1)->keyword == mgk(identifier) ) {
            
            marshmallow_parse_value(m_peek(1), a) ;
            
            m_advanceN(2) ;
            
            m_expect(end_of_line) ;
            
            return marshmallow_new_statement(gotoop, 0, (marshmallow_entity)a, NULL) ;
        }
        
         m_expect(identifier) ;
    }
    
    m_expect(goto) ;
    
    return NULL ;
}

m_processor(if) {
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    if ( m_peek(0)->keyword == mgk(if) ) {
        
        if ( m_peek(1)->keyword == mgk(pleft) ) {
            
            m_advanceN(2) ;
            
            a->type->root_type = expression ;
            
            a->data = m_process(expression) ;
            
        } else {
            
            printf("Expected expression. '%s' is not an expression.\n",RKString_GetString(m_peek(0)->value)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
        
    }
    
    if ( m_gettoken->keyword == mgk(end_of_line) ) {
        
        return marshmallow_new_statement(ifop, 0, (marshmallow_entity)a, NULL) ;
    }
    
    marshmallow_variable b = marshmallow_new_variable() ;
    
    b->type = marshmallow_new_type() ;
    
    b->type->root_type = expression ;
    
    b->data = m_process(statement) ;
    
    return marshmallow_new_statement(slifop, 0, (marshmallow_entity)a, (marshmallow_entity)b) ;
}

m_processor(while) {
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    if ( m_peek(0)->keyword == mgk(while) ) {
        
        if ( m_peek(1)->keyword == mgk(pleft) ) {
            
            m_advanceN(2) ;
            
            a->type->root_type = expression ;
            
            a->data = m_process(expression) ;
            
        } else {
            
            printf("Expected expression. '%s' is not an expression.\n",RKString_GetString(m_peek(0)->value)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
        
    }
    
    m_expect(end_of_line) ;
    
    return marshmallow_new_statement(whileop, 0, (marshmallow_entity)a, NULL) ;
}

m_processor(switch) {
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    if ( m_peek(0)->keyword == mgk(switch) ) {
        
        if ( m_peek(1)->keyword == mgk(pleft) ) {
            
            m_advanceN(2) ;
            
            a->type->root_type = expression ;
            
            a->data = m_process(expression) ;
            
        } else {
            
            printf("Expected expression. '%s' is not an expression.\n",RKString_GetString(m_peek(0)->value)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
        
    }
    
    m_expect(end_of_line) ;
    
    return marshmallow_new_statement(switchop, 0, (marshmallow_entity)a, NULL) ;
}

m_processor(case) {
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    if ( m_peek(0)->keyword == mgk(case) ) {
        
        if ( m_peek(1)->keyword == mgk(pleft) ) {
            
            m_advanceN(2) ;
            
            a->type->root_type = expression ;
            
            a->data = m_process(expression) ;
            
        } else {
            
            printf("Expected expression. '%s' is not an expression.\n",RKString_GetString(m_peek(0)->value)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
        
    }
    
    m_expect(end_of_line) ;
    
    return marshmallow_new_statement(caseop, 0, (marshmallow_entity)a, NULL) ;
}

m_processor(default) {
    
    if ( m_peek(0)->keyword == mgk(default) ) {
        
        m_advance ;
        
        m_expect(end_of_line) ;
        
        return marshmallow_new_statement(defaultop, 0, NULL, NULL) ;
    }
    
    m_advance ;
    
    m_expect(end_of_line) ;
    
    return NULL ;
}

m_processor(expression) {
    
    int n = 0 ;
    
    int flag_a = 0 ;
    
    int flag_b = 0 ;
    
    marshmallow_op_type op = noop ;
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    marshmallow_variable b = marshmallow_new_variable() ;
    
    b->type = marshmallow_new_type() ;
    
    //&x
    
    //*x
    
    //x++
    
    //x--
    
    if ( m_peek(n+0)->keyword == mgk(and) ) op = addrof ;
    
    if ( m_peek(n+0)->keyword == mgk(star) )  op = deref ;
    
    if ( m_peek(n+0)->keyword == mgk(minus) )  op = negate ;
    
    if ( m_peek(n+0)->keyword == mgk(epoint) )  op = not ;
    
    if ( op == addrof || op == deref || op == negate || op == not ) n++ ;
    
    if ( marshmallow_is_token_root_type(m_peek(n+0)) ) {
        
        a->name = RKString_CopyString(m_peek(n+0)->value) ;
        
        marshmallow_parse_type(a->type, m_peek(n+0), 0, NULL, 0) ;
        
        marshmallow_parse_value(m_peek(n+0), a) ;
        
        flag_a++ ;
    }
    
    if ( m_peek(n+0)->keyword == mgk(identifier) ) {
        
        a->type->root_type = unknown ;
        
        a->name = RKString_CopyString( m_peek(n+0)->value) ;
        
        flag_a++ ;
    }
    
    if ( m_peek(n+0)->keyword == mgk(pleft) ) {
        
        m_advanceN(1) ;
        
        a->type->root_type = expression ;
        
        a->data = m_process(expression) ;
        
        n = n-1 ;
        
        flag_a++ ;
    }
    
    if ( !flag_a ) {
        
        printf("Unknown expression variable A in expression. %s is not a value, variable, or expression.\n",RKString_GetString(m_peek(n+0)->value)) ;
        
        exit(EXIT_FAILURE) ;
    }
    //op != addrof && op != deref && op != negate && op != not
    if ( op == noop ) {
        
        switch ( m_peek(n+1)->keyword ) {
                
            case mgk(plus):
                
                op = add ;
                
                if ( m_peek(n+2)->keyword == mgk(plus) ) {
                    
                    op = inc ;
                    
                    n++ ;
                }
                
                break;
                
            case mgk(minus):
                
                op = sub ;
                
                if ( m_peek(n+2)->keyword == mgk(minus) ) {
                    
                    op = dec ;
                    
                    n++ ;
                }
                
                break;
                
            case mgk(pright):
                
                m_advanceN(n+2) ;
                
                return a ;
                
                break;
                
            case mgk(comma):
                
                m_advanceN(n+1) ;
                
                return a ;
                
                break;
                
            case mgk(colon):
                
                if ( m_peek(n+2)->keyword == mgk(eql) ) op = assignment ;
                
                if ( op != assignment ) {
                    
                    printf("Unknown operator. %s is not a operator.\n",RKString_GetString(m_peek(n+2)->value)) ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                n++ ;
                
                break;
                
                
            case mgk(epoint):
                
                if ( m_peek(n+2)->keyword == mgk(eql) ) op = is_not_equal ;
                
                if ( op != is_not_equal ) {
                    
                    printf("Unknown operator. %s is not a operator.\n",RKString_GetString(m_peek(n+2)->value)) ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                n++ ;
                
                break;
                
            case mgk(greaterthan):
                
                op = is_greaterthan ;
                
                if ( m_peek(n+2)->keyword == mgk(eql) ){
                    
                    op = is_greaterthan_or_equal ;
                    
                    n++ ;
                }
                
                break;
                
            case mgk(lessthan):
                
                op = is_lessthan ;
                
                if ( m_peek(n+2)->keyword == mgk(eql) ){
                    
                    op = is_lessthan_or_equal ;
                    
                    n++ ;
                }
                
                break;
                
            default:
                
                printf("Unknown operator. %s is not a operator.\n",RKString_GetString(m_peek(n+1)->value)) ;
                
                exit(EXIT_FAILURE) ;
                
                break;
        }
        
        if ( op == inc || op == dec  ) n++ ;
        
        if ( op != inc && op != dec  ) {
            
            m_advanceN(n+2) ;
            
            if ( op == assignment ) n-- ;
            
            if ( marshmallow_is_token_root_type(m_peek(n+0)) ) {
                
                b->name = RKString_CopyString(m_peek(n+0)->value) ;
                
                marshmallow_parse_type(b->type, m_peek(n+0), 0, NULL, 0) ;
                
                marshmallow_parse_value(m_peek(n+0), b) ;
                
                flag_b++ ;
            }
            
            if ( m_peek(n+0)->keyword == mgk(identifier) ) {
                
                b->type->root_type = unknown ;
                
                b->name = RKString_CopyString( m_peek(n+0)->value) ;
                
                flag_b++ ;
            }
            
            if ( m_peek(n+0)->keyword == mgk(pleft) ) {
                
                m_advanceN(1) ;
                
                b->type->root_type = expression ;
                
                b->data = m_process(expression) ;
                
                n = n-1 ;
                
                flag_b++ ;
            }
            
            if ( !flag_b ) {
                
                printf("Unknown expression variable B in expression. %s is not a value, variable, or expression.\n",RKString_GetString(m_peek(n+0)->value)) ;
                
                exit(EXIT_FAILURE) ;
                
            }
        }
    }
    
    m_advanceN(n+1) ;
    
    m_expect(pright) ;
    
    m_advanceN(1) ;
    
    return marshmallow_new_statement(op, 1, (marshmallow_entity)a, (marshmallow_entity)b) ;
}


m_processor(collection) {
    
    int n = 0 ;
    
    marshmallow_variable element = NULL ;
    
    marshmallow_variable the_collection = marshmallow_new_variable() ;
    
    the_collection->type = marshmallow_new_type() ;
    
    the_collection->type->root_type = collection ;
    
    the_collection->data = RKList_NewList() ;
    
    if ( m_peek(0)->keyword == mgk(bleft) ) {
        
        if ( m_peek(1)->keyword == mgk(bright) ) {
            
            m_advanceN(1) ;
            
            m_expect(bright) ;
            
            m_advanceN(1) ;
            
        } else {
            
            m_advanceN(1) ;
            
        add_element:
            
            if ( marshmallow_is_token_root_type(m_peek(n+0)) ) {
               
                element = marshmallow_new_variable() ;
                
                element->type = marshmallow_new_type() ;
                
                element->name = RKString_CopyString(m_peek(n+0)->value) ;
                
                marshmallow_parse_type(element->type, m_peek(n+0), 0, NULL, 0) ;
                
                marshmallow_parse_value(m_peek(n+0), element) ;
                
                m_advanceN(1) ;
                
            } else if ( m_peek(n+0)->keyword == mgk(identifier) ) {
                
                element = marshmallow_new_variable() ;
                
                element->type = marshmallow_new_type() ;
                
                element->type->root_type = unknown ;
                
                element->name = RKString_CopyString( m_peek(n+0)->value) ;
                
                m_advanceN(1) ;
                
            } else {
                
                element = m_process(assignment) ;
            }
            
            RKList_AddToList(the_collection->data, element) ;
            
            if ( m_peek(n+0)->keyword == mgk(comma) ) {
                
                n += 1 ;
                
                m_advanceN(n) ;
                
                n = 0 ;
                
                goto add_element ;
            }
            
            m_expect(bright) ;
            
            m_advanceN(1) ;
        }
        
    } else {
        
        m_advanceN(1) ;
        
        m_expect(bright) ;
        
        m_advanceN(1) ;
    }
    
    return the_collection ;
}

m_processor(assignment) {
    
    int n = 0 ;
    
    int flag_a = 0 ;
    
    int flag_b = 0 ;
    
    marshmallow_op_type op = noop ;
    
    marshmallow_variable a = marshmallow_new_variable() ;
    
    a->type = marshmallow_new_type() ;
    
    marshmallow_variable b = marshmallow_new_variable() ;
    
    b->type = marshmallow_new_type() ;
    
    if ( m_peek(n+0)->keyword == mgk(identifier) ) {
        
        a->type->root_type = unknown ;
        
        a->name = RKString_CopyString( m_peek(n+0)->value) ;
        
        flag_a++ ;
    }
    
    if ( m_peek(n+0)->keyword == mgk(pleft) ) {
        
        m_advanceN(1) ;
        
        a->type->root_type = expression ;
        
        a->data = m_process(expression) ;
        
        n = n-1 ;
        
        flag_a++ ;
    }
    
    if ( m_peek(n+0)->keyword == mgk(bleft) ) {
        
        a->type->root_type = metacollection ;
        
        a->data = m_process(collection) ;
        
        n = n-1 ;
        
        flag_a++ ;
    }
    
    if ( !flag_a ) {
        
        printf("Unknown assignment variable A in assignment. %s is not a variable, or expression.\n",RKString_GetString(m_peek(n+0)->value)) ;
        
        exit(EXIT_FAILURE) ;
        
    }
    
    if ( is_assignment(startnode, n+1) ) {
        
        m_advanceN(n+3) ;
        
        op = assignment ;
        
        if ( marshmallow_is_token_root_type(m_peek(n+0)) ) {
            
            b->name = RKString_CopyString(m_peek(n+0)->value) ;
            
            marshmallow_parse_type(b->type, m_peek(n+0), 0, NULL, 0) ;
            
            marshmallow_parse_value(m_peek(n+0), b) ;
            
            flag_b++ ;
        }
        
        if ( m_peek(n+0)->keyword == mgk(identifier) ) {
            
            b->type->root_type = unknown ;
            
            b->name = RKString_CopyString( m_peek(n+0)->value) ;
            
            flag_b++ ;
        }
        
        if ( m_peek(n+0)->keyword == mgk(pleft) ) {
            
            m_advanceN(1) ;
            
            b->type->root_type = expression ;
            
            b->data = m_process(expression) ;
            
            n = n-1 ;
            
            flag_b++ ;
        }
        
        if ( m_peek(n+0)->keyword == mgk(bleft) ) {
            
            b->type->root_type = metacollection ;
            
            b->data = m_process(collection) ;
            
            n = n-1 ;
            
            flag_b++ ;
        }
        
        if ( !flag_b ) {
            
            printf("Unknown assignment variable B in assignment. %s is not a value, variable, or expression.\n",RKString_GetString(m_peek(n+0)->value)) ;
            
            exit(EXIT_FAILURE) ;
            
        }
        
    } else {
        
        if ( m_peek(n+1)->keyword == mgk(plus)) if ( m_peek(n+2)->keyword == mgk(plus)) op = inc ;
        
        if ( m_peek(n+1)->keyword == mgk(minus)) if ( m_peek(n+2)->keyword == mgk(minus)) op = dec ;
    }
    
    if ( op == noop && a->type->root_type != expression ) {
        
        printf("Unknown operator. %s is not a operator.\n",RKString_GetString(m_peek(n+1)->value)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( op == noop && a->type->root_type != expression ) m_advanceN(1) ;
    
    if ( op == assignment && a->type->root_type != expression ) m_advanceN(1) ;
    
    if ( op == assignment && a->type->root_type == expression ) m_advanceN(1) ;
    
    if ( op == assignment && b->type->root_type == expression ) m_advanceN(1) ;
    
    if ( op == inc || op == dec ) m_advanceN(3) ;
   
    return marshmallow_new_statement(op, 0, (marshmallow_entity)a, (marshmallow_entity)b) ;
}

m_processor(static_assignment) {
    
    int n = 0 ;
    
    marshmallow_variable variable = marshmallow_new_variable() ;
    
    variable->type = marshmallow_new_type() ;
    
    if ( m_peek(n+0)->keyword == mgk(bleft) ) {
        
        variable->type->root_type = metacollection ;
        
        variable->data = m_process(collection) ;
        
        return variable ;
    }
    
    if ( m_peek(n+1)->keyword == mgk(end_of_line) || m_peek(n+1)->keyword == mgk(pright) || m_peek(n+1)->keyword == mgk(comma) ) {
        
        if (  m_peek(n+1)->keyword == mgk(comma) ) {
            
            while (m_peek(n+1)->keyword != mgk(pright)) {
                
                if ( m_peek(n+1)->keyword == mgk(end_of_line) ) {
                    
                    m_expectN(n, pright) ;
                }
                
                n++ ;
            }
            
            n = 0 ;
        }
        
        if ( marshmallow_is_token_root_type(m_peek(n+0)) ) {
            
            variable->name = RKString_CopyString(m_peek(n+0)->value) ;
            
            marshmallow_parse_type(variable->type, m_peek(n+0), 0, NULL, 0) ;
            
            marshmallow_parse_value(m_peek(n+0), variable) ;
            
            return variable ;
        }
        
    } else {
        
        m_expectN(n+1,end_of_line) ;
    }
    
    return NULL ;
}

m_processor(type) {
    
    //RKList_IterateListWith(func, symbol_list) ;
    
    int n = 1 ;
    
    int array_n = 0 ;
    
    int pointers = 0 ;
    
    int* arrays = NULL ;
    
    int num_of_arrays = 0 ;
    
    marshmallow_variable variable = marshmallow_new_variable() ;
    
    variable->type = marshmallow_new_type() ;
    
    //type***[] varname = ().
    
    if ( (m_gettoken->keyword == mgk(identifier)) || (marshmallow_is_token_root_type(m_gettoken)) ) {
        
        if ( m_peek(1)->keyword == mgk(star) ) {
            
            while (m_peek(n)->keyword == mgk(star)) {
                
                pointers++ ;
                
                n++ ;
            }
        }
        
        if ( m_peek(n)->keyword == mgk(sqleft) ) {
            
            array_n = -n ;
            
            while ( m_peek(n)->keyword == mgk(sqleft) ) {
                
                n++ ;
                
                if ( (m_peek(n)->keyword == mgk(u32type)) || (m_peek(n)->keyword == mgk(u64type)) ) {
                    
                    num_of_arrays++ ;
                    
                    if ( arrays != NULL ) arrays = RKMem_Realloc(arrays, num_of_arrays, num_of_arrays-1, int, 1) ;
                    
                    if ( arrays == NULL ) arrays = RKMem_CArray(1, int) ;
                    
                    arrays[num_of_arrays-1] = atoi(RKString_GetString(m_peek(n)->value)) ;
                    
                    n++ ;
                    
                    m_expectN(n,sqright) ;
                    
                    n++ ;
                    
                } else if (m_peek(n)->keyword == mgk(sqright)) {
                    
                    num_of_arrays++ ;
                    
                    if ( arrays != NULL ) arrays = RKMem_Realloc(arrays, num_of_arrays, num_of_arrays-1, int, 1) ;
                    
                    if ( arrays == NULL ) arrays = RKMem_CArray(1, int) ;
                    
                    arrays[num_of_arrays-1] = 0 ;
                    
                    n++ ;
                }
            }
            
            array_n += n ;
        }
        
    }
    
    variable->type->type_name = RKString_CopyString(m_gettoken->value) ;
    
    marshmallow_parse_type(variable->type, m_gettoken, pointers, arrays, num_of_arrays) ;
    
    variable->name = RKString_CopyString(m_peek(n)->value) ;
    
    n++ ;
    
    if ( pointers > 0 ) {
        
        m_advanceN(pointers) ;
    }
    
    if ( arrays != NULL ) {
        
        m_advanceN(array_n) ;
        
        n = 2 ;
    }
    
    m_advanceN(1) ;
    
    return variable ;
}

m_processor(variable) {
    
    //RKList_IterateListWith(func, symbol_list) ;
    
    int n = 1 ;
    
    int array_n = 0 ;
    
    int pointers = 0 ;
    
    int* arrays = NULL ;
    
    int num_of_arrays = 0 ;
    
    RKList_node base_node = *startnode ;
    
    marshmallow_variable variable = marshmallow_new_variable() ;
    
    variable->type = marshmallow_new_type() ;
    
    //type***[] varname = ().
    
    if ( m_gettoken->keyword == mgk(external) ) {
        
        if ( m_peek(1)->keyword == mgk(function) ) {
            
            return m_process(function) ;
        }
        
        if ( m_peek(1)->keyword == mgk(identifier) || marshmallow_is_token_root_type(m_peek(1)) ) {
            
            variable->is_external = 1 ;
            
            m_advanceN(1) ;
        }
    }
    
    if ( (m_gettoken->keyword == mgk(identifier)) || (marshmallow_is_token_root_type(m_gettoken)) ) {
        
        if ( m_peek(1)->keyword == mgk(star) ) {
            
            while (m_peek(n)->keyword == mgk(star)) {
                
                pointers++ ;
                
                n++ ;
            }
        }
        
        if ( m_peek(n)->keyword == mgk(sqleft) ) {
            
            array_n = -n ;
            
            while ( m_peek(n)->keyword == mgk(sqleft) ) {
                
                n++ ;
                
                if ( (m_peek(n)->keyword == mgk(u32type)) || (m_peek(n)->keyword == mgk(u64type)) ) {
                    
                    num_of_arrays++ ;
                    
                    if ( arrays != NULL ) arrays = RKMem_Realloc(arrays, num_of_arrays, num_of_arrays-1, int, 1) ;
                    
                    if ( arrays == NULL ) arrays = RKMem_CArray(1, int) ;
                    
                    arrays[num_of_arrays-1] = atoi(RKString_GetString(m_peek(n)->value)) ;
                    
                    n++ ;
                    
                    m_expectN(n,sqright) ;
                    
                    n++ ;
                    
                } else if (m_peek(n)->keyword == mgk(sqright)) {
                    
                    num_of_arrays++ ;
                    
                    if ( arrays != NULL ) arrays = RKMem_Realloc(arrays, num_of_arrays, num_of_arrays-1, int, 1) ;
                    
                    if ( arrays == NULL ) arrays = RKMem_CArray(1, int) ;
                    
                    arrays[num_of_arrays-1] = 0 ;
                    
                    n++ ;
                }
            }
            
            array_n += n ;
            
        }
        
        
        if ( m_peek(n)->keyword != mgk(identifier) ) {
            
            if ( (arrays != NULL) || (pointers > 0) || (marshmallow_is_token_root_type(m_gettoken)) ) {
                
                printf("%s is not a identifier. Identifiers follow types.\n",RKString_GetString(m_peek(n)->value)) ;
                
                exit(EXIT_FAILURE) ;
            }
            
        }
        
    }
    
    if ( m_gettoken->keyword == mgk(identifier) && ((arrays == NULL) && (pointers == 0)) ) {
        
        if ( m_peek(n+0)->keyword == mgk(pleft) ) {
            
            marshmallow_function_signature signature = marshmallow_new_function_signature(m_gettoken->value, 0) ;
            
            marshmallow_function_body function = marshmallow_new_function_body(signature) ;
            
            variable = m_process(arguments) ;
            
            return marshmallow_new_statement(call, 0, (marshmallow_entity)function, (marshmallow_entity)variable) ;
        }
        
        if ( is_assignment(startnode, n) || ( (m_peek(n+0)->keyword == mgk(plus)) && (m_peek(n+1)->keyword == mgk(plus)) )
            || ( (m_peek(n+0)->keyword == mgk(minus)) && (m_peek(n+1)->keyword == mgk(minus)) )) {
            
            *startnode = base_node ;
            
            return m_process(assignment) ;
        }
        
        m_expect(end_of_line) ;
    }
    
    variable->type->type_name = RKString_CopyString(m_gettoken->value) ;
    
    marshmallow_parse_type(variable->type, m_gettoken, pointers, arrays, num_of_arrays) ;
    
    variable->name = RKString_CopyString(m_peek(n)->value) ;
    
    
    n++ ;

    if ( pointers > 0 ) {
        
        m_advanceN(pointers) ;
    }
    
    if ( arrays != NULL ) {
        
        m_advanceN(array_n) ;
        
        n = 2 ;
    }
    
    if ( is_assignment(startnode, n) ) {
        
        n+=2 ;
        
        if ( marshmallow_is_token_root_type(m_peek(n)) || m_peek(n)->keyword == mgk(bleft) ) {
            
            m_advanceN(n) ;
            
            variable->static_assignment = m_process(static_assignment) ;
            
        } else {
            
            printf("Extra ':='.\n") ;
            
            exit(EXIT_FAILURE) ;
        }
    }
    
    m_advanceN(1) ;
    
    if ( variable->static_assignment == NULL ) m_advanceN(1) ;
    
    return variable ;
}

m_processor(module) {
    
    //RKList_IterateListWith(func, symbol_list) ;
    
    marshmallow_module module ;
    
    if ( m_peek(1)->keyword != mgk(identifier) ) {
        
        printf("%s is not a identifier.\n",RKString_GetString(m_peek(1)->value)) ;
        
        exit(EXIT_FAILURE) ;
    }
    
    if ( !RKStore_ItemExists(context->modules, RKString_GetString(m_peek(1)->value)) ) {
        
        module = marshmallow_new_module(m_peek(1)->value) ;
        
        RKStore_AddItem(context->modules, module, RKString_GetString(m_peek(1)->value)) ;
    }
    
    module = RKStore_GetItem(context->modules, RKString_GetString(m_peek(1)->value)) ;
    
    return module ;
}

static void marshmallow_parse_line( marshmallow_context context, RKList symbol_list, RKStack scope_stack ) {
    
    RKList_node node = RKList_GetFirstNode(symbol_list) ;
    
    marshmallow_entity entity = NULL ;
    
    RKList_node* startnode = &node ;
    
    marshmallow_token symbol = NULL ;
    
    marshmallow_entity_type entity_type = entity_nothing ;
    
    RKList_IterateListWith(func, symbol_list) ;
    
    int index = 0 ;
    
    if ( node != NULL ) {
        
        symbol = RKList_GetData(node) ;
        
        switch (symbol->keyword) {
                
            case mgk(section):
                
                entity = m_process(section) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(goto):
                
                entity = m_process(goto) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(if):
                
                entity = m_process(if) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(while):
                
                entity = m_process(while) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(switch):
                
                entity = m_process(switch) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(case):
                
                entity = m_process(case) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(default):
                
                entity = m_process(default) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(external):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(identifier):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
             
            case mgk(u8type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(i8type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(u16type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(i16type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(u32type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;

            case mgk(i32type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(u64type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(i64type):
                
                entity = m_process(variable) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(pleft):
                
                entity = m_process(assignment) ;
                
                m_expect(end_of_line) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(bleft):
                
                entity = m_process(assignment) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(module):
                
                entity = m_process(module) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(function):
                
                entity = m_process(function) ;
                
                entity_type = entity->entity_type ;
                
                break;
                
            case mgk(end):
                
                entity_type = entity_end ;
                
                break;
                
            default:
                
                printf("Unknown primary keyword or symbol: %s.\n",RKString_GetString(symbol->value)) ;
                
                exit(EXIT_FAILURE) ;
                
                break;
        }
        
        switch (entity_type) {
                
            case entity_variable:
                
                if ( RKStack_IsEmpty(scope_stack) ) {
                    
                    printf("No scope.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                if ( !(((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_module)
                    && !(((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_function) &&
                    !(((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_statement) &&
                    !(((marshmallow_statement)RKStack_Peek(scope_stack))->op == ifop || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == whileop) ) {
                    
                    printf("Expected module or function. Variables must exist within a module or function.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                if ( (((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_module)
                    || (((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_function) ) {
                
                marshmallow_add_variable_to_scope(RKStack_Peek(scope_stack), (marshmallow_variable)entity) ;
                    
                } else if ( (((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_statement) &&
                           (((marshmallow_statement)RKStack_Peek(scope_stack))->op == ifop || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == whileop) ) {
                    
                    if ( (marshmallow_scope)((marshmallow_statement)RKStack_Peek(scope_stack))->function == NULL ) {
                        
                        printf("If or while statement without a function.\n") ;
                        
                        exit(EXIT_FAILURE) ;
                    }
                    
                    marshmallow_add_variable_to_scope((marshmallow_scope)((marshmallow_statement)RKStack_Peek(scope_stack))->function, (marshmallow_variable)entity) ;
                }
                
                break;
                
            case entity_module:
                
                if ( !RKStack_IsEmpty(scope_stack) ) {
                    
                    printf("Module does not end.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                RKStack_Push(scope_stack, entity) ;
                
                break;
                
            case entity_function:
                
                if ( RKStack_IsEmpty(scope_stack) ) {
                    
                    printf("No scope.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                if ( !(((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_module) ) {
                    
                    printf("Expected module. Function and methods must exist within a module.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                if ( ((marshmallow_function_body)entity)->signature->is_declared ||
                    ((marshmallow_function_body)entity)->signature->is_external ) {
                    
                    marshmallow_add_function_to_module_declarations((marshmallow_function_body)entity, RKStack_Peek(scope_stack)) ;
                    
                } else {
                    
                    marshmallow_add_function_to_module((marshmallow_function_body)entity, RKStack_Peek(scope_stack)) ;
                    
                    RKStack_Push(scope_stack, entity) ;
                }
                
                break;
                
            case entity_statement:
                
                if ( RKStack_IsEmpty(scope_stack) ) {
                    
                    printf("No scope.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                
                if ( ((marshmallow_entity)entity)->entity_type == entity_statement &&
                    ( ((marshmallow_statement)entity)->op == caseop || ((marshmallow_statement)entity)->op == defaultop ) ) {
                    
                    if ( ((marshmallow_statement)entity)->op == caseop ) {
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == defaultop ) {
                            
                            printf("Case statements can not exist within a default statement.\n") ;
                            
                            exit(EXIT_FAILURE) ;
                            
                        }
                    }
                    
                    if ( ((marshmallow_statement)entity)->op == defaultop ) {
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == caseop ) {
                            
                            printf("Expected case statement. Default statements can not exist within a case statement.\n") ;
                            
                            exit(EXIT_FAILURE) ;
                            
                        }
                    }
                  
                    if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op != switchop && ((marshmallow_statement)RKStack_Peek(scope_stack))->op != caseop ) {
                        
                        printf("Expected switch statement. Cases and default statements can only exist within a switch statement.\n") ;
                        
                        exit(EXIT_FAILURE) ;
                        
                    }
                    
                    goto valid_statement ;
                }
                
                if ( ((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_statement &&
                    ((marshmallow_statement)RKStack_Peek(scope_stack))->op == switchop ) {
                    
                    if ( !( ((marshmallow_statement)entity)->op == caseop || ((marshmallow_statement)entity)->op == defaultop ) )  {
                        
                        printf("Expected case or default statement. Only cases and default statements can exist within a switch statement.\n") ;
                        
                        exit(EXIT_FAILURE) ;
                        
                    }
                    
                    goto valid_statement ;
                }
                
                if ( ((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_statement &&
                    ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == ifop || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == whileop
                     || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == slifop || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == switchop
                     || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == caseop || ((marshmallow_statement)RKStack_Peek(scope_stack))->op == defaultop ) ) {
                    
                        goto valid_statement ;
                    }
                
                if ( !(((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type == entity_function) ) {
                    
                    printf("Expected function. Statements must exist within a function.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
            valid_statement:
                
                marshmallow_add_statement_to_function(RKStack_Peek(scope_stack), (marshmallow_statement)entity) ;
                
                if ( ((marshmallow_entity)entity)->entity_type == entity_statement &&
                    ((marshmallow_statement)entity)->op == slifop ) {
                    
                    if ( ((marshmallow_variable)((marshmallow_statement)entity)->var_b)->type->root_type == expression ) {
                        
                        marshmallow_variable var = (marshmallow_variable)((marshmallow_statement)entity)->var_b ;
                    loop:
                        if ( var->type->root_type == expression ) {
                            
                            if ( ((marshmallow_statement)var->data)->op == slifop ) {
                                
                                var = (marshmallow_variable)((marshmallow_statement)var->data)->var_b ;
                                
                                goto loop ;
                            }
                            
                            if ( ((marshmallow_statement)var->data)->op == ifop || ((marshmallow_statement)var->data)->op == whileop ) {
                                
                                ((marshmallow_statement)var->data)->function = RKStack_Peek(scope_stack) ;
                                
                                RKStack_Push(scope_stack, var->data) ;
                            }
                            
                        }
                    }
                }
                
                if ( ((marshmallow_statement)entity)->op == ifop || ((marshmallow_statement)entity)->op == whileop || ((marshmallow_statement)entity)->op == switchop ||
                    ((marshmallow_statement)entity)->op == caseop || ((marshmallow_statement)entity)->op == defaultop) {
                    
                    RKStack_Push(scope_stack, entity) ;
                }
                
                break;
                
            case entity_end:
                
                if ( RKStack_IsEmpty(scope_stack) ) {
                    
                    printf("Scope stack is empty.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                switch ( ((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type ) {
                        
                    case entity_module:
                        
                        if ( m_peek(1)->keyword != mgk(module) ) {
                            
                            printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                            
                            printf("Expected module. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                            
                            exit(EXIT_FAILURE) ;
                        }
                        
                        break;
                        
                    case entity_function:
                        
                        if ( m_peek(1)->keyword != mgk(function) ) {
                            
                            printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                            
                            printf("Expected function. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                            
                            exit(EXIT_FAILURE) ;
                        }
                        
                        break;
                        
                    case entity_statement:
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == ifop ) {
                            
                            if ( m_peek(1)->keyword != mgk(if) ) {
                                
                                printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                                
                                printf("Expected if. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                                
                                exit(EXIT_FAILURE) ;
                            }
                        }
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == whileop ) {
                            
                            if ( m_peek(1)->keyword != mgk(while) ) {
                                
                                printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                                
                                printf("Expected while. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                                
                                exit(EXIT_FAILURE) ;
                            }
                        }
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == switchop ) {
                            
                            if ( m_peek(1)->keyword != mgk(switch) ) {
                                
                                printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                                
                                printf("Expected switch. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                                
                                exit(EXIT_FAILURE) ;
                            }
                        }
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == caseop ) {
                            
                            if ( m_peek(1)->keyword != mgk(case) ) {
                                
                                printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                                
                                printf("Expected case. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                                
                                exit(EXIT_FAILURE) ;
                            }
                        }
                        
                        if ( ((marshmallow_statement)RKStack_Peek(scope_stack))->op == defaultop ) {
                            
                            if ( m_peek(1)->keyword != mgk(default) ) {
                                
                                printf("End wrong scope, end mismatched. Ends are unbalanced.\n") ;
                                
                                printf("Expected default. Got: %s.\n",RKString_GetString(m_peek(1)->value)) ;
                                
                                exit(EXIT_FAILURE) ;
                            }
                        }
                        
                        break;
                        
                        
                    default:
                        break;
                }
                
                RKStack_Pop(scope_stack) ;
                
                break;
                
                
            default:
                break;
        }
    }
}

void marshmallow_lex_and_parse_file( marshmallow_context context, FILE* file ) {
    
    int c = 0 ;
    
    int i = 0 ;
    
    int symbol = 0 ;
    
    int balance = 0 ;
    
    int is_long = 0 ;
    
    int is_float = 0 ;
    
    int is_double = 0 ;
    
    int word_size = 1 ;
    
    int noline = 0 ;
    
    int is_string = 0 ;
    
    marshmallow_token token = NULL ;
    
    marshmallow_token symtoken = NULL ;
    
    char* word = RKMem_CArray(1, char) ;
    
    RKList symbol_list = RKList_NewList() ;
    
    RKStack scope_stack = RKStack_NewStack() ;
    
    word[word_size-1] = '\0' ;
    
    while ( (c = getc(file)) != EOF ) {
        
        if ( c == '"' ) {
            
            if ( is_string == 0 ) {
                
                is_string = 1 ;
                
                continue ;
            }
            
            if ( is_string == 1 ) is_string = 0 ;
        }
        
        if ( noline < 2 ) if ( c == '/' ) {
            
            noline++ ;
        }
        
        if ( c != '/' && (noline == 1) ) {
            
            noline = 0 ;
        }
        
        if ( c == '\n' ) {
            
            noline = 0 ;
        }
        
        if ( noline == 2 ) {
            
            if ( c == '/' ) RKList_DeleteNode(symbol_list, RKList_GetLastNode(symbol_list)) ;
            
            continue ;
        }
        
        symbol = mgk(notoken) ;
        
        if ( c == '(' ) balance++ ;
        
        if ( c == ')' ) balance-- ;
        
        if ( balance < 0 ) {
            
            printf("Error: non-balanced: ')'.\n") ;
            
            exit(EXIT_FAILURE) ;
        }
        
        if ( (c == '.') && (balance == 0) ) {
            
            symtoken = RKMem_NewMemOfType(struct marshmallow_token_s) ;
            
            symtoken->keyword = mgk(end_of_line) ;
            
            symtoken->value = rkstr("end_of_line") ;
        }
        
        if (  marshmallow_is_symbol(c,balance) && c != '.' && c != '"' && !is_string) {
            
            char symword[2] ;
            
            symword[0] = c ;
            
            symword[1] = '\0' ;
            
            if ( RKStore_GetItem(context->words, symword) == NULL ) {
                
                printf("Error: non-identifier: %s.\n",symword) ;
                
                exit(EXIT_FAILURE) ;
                
            }
            
            symbol = rkget(int, RKStore_GetItem(context->words, symword)) ;
            
            symtoken = RKMem_NewMemOfType(struct marshmallow_token_s) ;
            
            symtoken->keyword = symbol ;
            
            symtoken->value = (symbol != mgk(notoken)) ? RKString_NewStringFromCString(symword) : rkstr("notoken") ;
        }
        
        if ( ((!(isspace(c) || marshmallow_is_symbol(c,balance))) || is_string) && c != '"' ) {
            
            word = RKMem_Realloc(word, word_size+1, word_size, char, 1) ;
            
            word_size++ ;
            
            word[word_size-2] = c ;
            
            word[word_size-1] = '\0' ;
        }
        
        if ( (isspace(c) || marshmallow_is_symbol(c,balance)) && !is_string ) {
            
            if ( RKStore_GetItem(context->words, word) == NULL ) {
                
                if ( (word_size == 1) && (!marshmallow_is_symbol(c,balance)) ) continue ;
                
                symbol = mgk(identifier) ;
                
                if ( c == '"' ) symbol = mgk(string) ;
            }
            
            if ( symbol != mgk(identifier) && symbol != mgk(string) ) symbol = rkget(int, RKStore_GetItem(context->words, word)) ;
            
            if ( symbol == mgk(identifier) ) {
                
                if ( word[0] == '_' ) {
                    
                    printf("Error: User Identifiers can not start with '_'.\n") ;
                    
                    exit(EXIT_FAILURE) ;
                }
                
                if ( word_size > 1 ) if (  (word[0] == '0') && (word[1] == 'x')  ) {
                    
                    i = 2 ;
                    
                    while (i < word_size-1) {
                        
                        if ( !((isdigit(word[i])) || (word[i] == 'a') || (word[i] == 'A') || (word[i] == 'b') || (word[i] == 'B')
                               || (word[i] == 'c') || (word[i] == 'C') || (word[i] == 'd') || (word[i] == 'D') || (word[i] == 'e')
                               || (word[i] == 'e') || (word[i] == 'f') || (word[i] == 'F')) ) {
                            
                            printf("Error: %s is not a hex. Hex can only contain 0-9,a-f,A-F.\n",word) ;
                            
                            exit(EXIT_FAILURE) ;
                        }
                        
                        i++ ;
                    }
                    
                    symbol = mgk(hex) ;
                }
                
                if ( (isdigit(word[0])) && (symbol != mgk(hex)) ) {
                    
                    i = 0 ;
                    
                    is_long = 0 ;
                    
                    is_float = 0 ;
                    
                    is_double = 0 ;
                    
                    while (i < word_size-1) {
                        
                        if ( word[i] == '.' ) is_double++ ;
                        
                        if ( (!isdigit(word[i])) && !(word[i] == '.') ) {
                            
                            if ( (word[i] == 'f') && (i == word_size-2) ) {
                                
                                is_float++ ;
                                
                                i++ ;
                                
                                continue ;
                            }
                            
                            if ( (word[i] == 'l') && (i == word_size-2) ) {
                                
                                is_long++ ;
                                
                                i++ ;
                                
                                continue ;
                            }
                            
                            printf("Error: %s is not a number or identifier. Identifiers can not start with a number, and hex must start with '0x'.\n",word) ;
                            
                            exit(EXIT_FAILURE) ;
                        }
                        
                        i++ ;
                    }
                    
                    if ( is_double > 1 ) {
                        
                        printf("Error: Too many '.' in %s\n",word) ;
                        
                        exit(EXIT_FAILURE) ;
                    }
                    
                    if ( !is_double && !is_float && !is_long ) symbol = mgk(u32type) ;
                    
                    if ( !is_double && !is_float && is_long ) symbol = mgk(u64type) ;
                    
                    if ( is_double ) symbol = mgk(doubletype) ;
                    
                    if ( is_float ) symbol = mgk(floattype) ;
                }
                
            }
            
            if ( word_size > 1 ) {
                
                token = RKMem_NewMemOfType(struct marshmallow_token_s) ;
                
                token->keyword = symbol ;
                
                token->value = (symbol != mgk(notoken)) ? RKString_NewStringFromCString(word) : rkstr("notoken") ;
                
                RKList_AddToList(symbol_list, token) ;
                
            }
            
            if ( symtoken != NULL && symtoken->keyword != mgk(end_of_line) ) {
                
                RKList_AddToList(symbol_list, symtoken) ;
                
                symtoken = NULL ;
            }
            
            free(word) ;
            
            word = RKMem_CArray(1, char) ;
            
            word_size = 1 ;
            
            word[word_size-1] = '\0' ;
            
            if ( symtoken != NULL ) if ( symtoken->keyword == mgk(end_of_line) ) {
                
                RKList_AddToList(symbol_list, symtoken) ;
                
                marshmallow_parse_line(context, symbol_list, scope_stack) ;
                
                RKList_DeleteAllNodesInList(symbol_list) ;
                
                symtoken = NULL ;
            }
        }
    }
    
    if ( !RKStack_IsEmpty(scope_stack) ) {
        
        printf("Not ended. Ends are unbalanced.\n") ;
        
        switch ( ((marshmallow_entity)RKStack_Peek(scope_stack))->entity_type ) {
                
            case entity_module:
                
                printf("Module, not ended.\n") ;
                
                break;
                
            default:
                break;
        }
        
        exit(EXIT_FAILURE) ;
    }
}

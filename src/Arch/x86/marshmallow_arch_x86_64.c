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
#include "marshmallow_backend.h"

define_mlb_opcode(start_routine,arch_x86_64) {
    
    printf("start_routine\n") ;
}

define_mlb_opcode(end_routine,arch_x86_64) {
    
    printf("end_routine\n") ;
}

define_mlb_opcode(add,arch_x86_64) {
    
    printf("add\n") ;
}

define_mlb_opcode(sub,arch_x86_64) {
    
    printf("sub\n") ;
}

define_mlb_opcode(mult,arch_x86_64) {
    
     printf("mult\n") ;
}

define_mlb_opcode(div,arch_x86_64) {
    
    printf("div\n") ;
}

define_mlb_opcode(rem,arch_x86_64) {
    
    printf("rem\n") ;
}

define_mlb_opcode(inc,arch_x86_64) {
    
    printf("inc\n") ;
}

define_mlb_opcode(dec,arch_x86_64) {
    
    printf("dec\n") ;
}

define_mlb_opcode(rshift,arch_x86_64) {
    
    printf("rshift\n") ;
}

define_mlb_opcode(lshift,arch_x86_64) {
    
    printf("lshift\n") ;
}

define_mlb_opcode(and,arch_x86_64) {
    
    printf("and\n") ;
}

define_mlb_opcode(or,arch_x86_64) {
    
    printf("or\n") ;
}

define_mlb_opcode(xor,arch_x86_64) {
    
    printf("xor\n") ;
}

define_mlb_opcode(not,arch_x86_64) {
    
    printf("not\n") ;
}

define_mlb_opcode(logic_and,arch_x86_64) {
    
    printf("logic_and\n") ;
}

define_mlb_opcode(logic_or,arch_x86_64) {
    
    printf("logic_or\n") ;
}

define_mlb_opcode(logic_not,arch_x86_64) {
    
    printf("logic_not\n") ;
}

define_mlb_opcode(load,arch_x86_64) {
    
    printf("load\n") ;
}

define_mlb_opcode(store,arch_x86_64) {
    
    printf("store\n") ;
}

define_mlb_opcode(move,arch_x86_64) {
    
    printf("move\n") ;
}

define_mlb_opcode(if,arch_x86_64) {
    
    printf("if\n") ;
}

define_mlb_opcode(go,arch_x86_64) {
    
    printf("go\n") ;
}

define_mlb_opcode(go_equals,arch_x86_64) {
    
    printf("go_equals\n") ;
}

define_mlb_opcode(go_not_equals,arch_x86_64) {
    
    printf("go_not_equals\n") ;
}

define_mlb_opcode(go_greaterthan,arch_x86_64) {
    
     printf("go_greaterthan\n") ;
}

define_mlb_opcode(go_lessthan,arch_x86_64) {
    
    printf("go_lessthan\n") ;
}

define_mlb_opcode(return,arch_x86_64) {
    
    printf("return\n") ;
}

new_architecture(arch_x86_64) {
    
    define_mlb_instructions(arch_x86_64)
}
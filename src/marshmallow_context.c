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

 void func( void* data ) {
    
    marshmallow_token token = data ;
    
    printf("%s\n",RKString_GetString(token->value)) ;
}

static void marshmallow_words( RKStore words ) {
    
    #define keyword(word,string) a = mgk(word) ;\
    RKStore_AddItem(words, rkany(a), string) ;
  
    marshmallow_keyword a ;
    
    #define token(word,string) keyword(word,string) ;
    
    #include "marshmallow_tokens.h"
    
    #undef token
}

void marshmallow_compile_file( marshmallow_context context, const char* in_file, const char* out_file ) {
    
    FILE* file = fopen(in_file, "r") ;
    
    FILE* output_file = fopen(out_file, "w") ;
    
    marshmallow_lex_and_parse_file(context, file) ;
    
    marshmallow_codegen(context, output_file) ;
    
    fclose(file) ;
    
    fclose(output_file) ;
}

marshmallow_context marshmallow_new_context( void ) {
    
    marshmallow_context context = RKMem_NewMemOfType(struct marshmallow_context_s) ;
    
    context->modules = RKStore_NewStore() ;
    
    context->words = RKStore_NewStore() ;
    
    context->symbols = RKStore_NewStore() ;
    
    marshmallow_words(context->words) ;
    
    return context ;
}

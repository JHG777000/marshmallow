# marshmallow


Marshmallow is a work in progress programming language.

The goal is to create a language comparable to C in terms of flexibility, and closeness to the underlying hardware, with a more friendly syntax and modern language features.

Marshmallow aims to be an object-oriented language with support for lambdas, bounds-checking, multiple returns, and an advanced macro system that supports generics and metaprogramming.

### Goal:

The following is an example of what marshmallow aims to be:

	module mymod.

    use module marshmallow.

     typedef [int][3][x,y,z] vectype.

     function main( args main_args ).

      [int][3] vector.

      [byte][3][r,g,b][red,green,blue] pixel.

      vectype vector2.

      vector2->x += 1.

      vector2->xy += 1.

      pixel->redblue += 1.

      vector[0] += 1.

      vector[0,1] += 1.

      vector += 1.

      vector += {1,2,3}.

      int[64] array.

      int i := 0.

      float y.

      sbyte x := ($i8($$$u64($$$int*($$int[](array))))).

      y := (*($float*(&i))).

      y := ($$float(i)).

      List list := new().

      int* ptr := null.

      float value := (1.0).

      int value2 := ($int(3+value)).

      int value3 := func().

      { value2, value3 } := MyFunc().

      lambda() returns int func := lambda_start.

       return 1.

      end lambda.      

     end function.

     function alloc(type type_to_alloc) returns blank*.

       if ( _is_ptr(type_to_alloc) ) return _init(malloc(_sizeof(_typeofptr(type_to_alloc)))).

       return _init(malloc(_sizeof(type_to_alloc))).

     end function.

     function freer free(blank* ptr).

      mfree(ptr).

     end function.

     class ( int num_of_nodes, list_node first, list_node last ) *List.

     function List_NewList returns List.

       List newlist := alloc(List).

       return newlist.

     end function.

     declare function overridable new.

     function override new returns List.

      return List_NewList().

     end function.

     function MyFunc returns int, int.

      return { 1,1 }.

     end function.

    end module.

### Current Backend:

Marshmallow currently compiles to C. A [LLVM](https://llvm.org) or [QBE](https://c9x.me/compile/) backend may be implemented in the future.

Currently to compile marshmallow code you will need a C compiler and to manually invoke the compiler on the generated C code.

### Current Status:

Marshmallow as of now, is very much a work in progress. Core language features have yet to be implemented: most of type checking, classes, function calls, and lambdas, etc.

The compiler is full of bugs and memory leaks, as such marshmallow has a long way to go before v1.0, however work is ongoing and active.

helloworld.msrc provides a working example of marshmallow, while helloworld\_C\_output/module_mymod.c is the C code marshmallow will  generate from helloworld.msrc.

## Building marshmallow

Any standard C11 compliant C compiler(64-bit) should be able to compile marshmallow, and the code it generates. Make sure the compiler can handle unicode identifiers in source.

Marshmallow uses [builder][1] for its build system.

[1]:https://github.com/JHG777000/builder

Marshmallow defaults to using the clang compiler in its buildfile.

To download and build use this command:

	builder -u https://raw.githubusercontent.com/JHG777000/marshmallow/master/buildfile

To run tests, add -i __t:

	builder -i __t -u https://raw.githubusercontent.com/JHG777000/marshmallow/master/buildfile
## License


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

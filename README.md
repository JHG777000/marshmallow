# marshmallow


Marshmallow is a work in progress programming language.

The goal is to create a language comparable to C in terms of flexibility, and closeness to the underlying hardware. With a more friendly syntax and modern language features.

Marshmallow aims to be an object-oriented language with support for lambdas, bounds-checking, multiple returns, and an advanced macro system that supports generics and metaprogramming.

### Goal:

The following is an example of what marshmallow aims to be:

	module mymod.

    use module marshmallow.

    @build.

      @public os(macOS | Windows | Linux).

      @files MyAppSourceFiles(MyOtherFile.msrc, Folder::SourceFile.msrc).

      @files MyAppLibraryFiles(libs::libm.a, libs::OtherModule.mmod, libs::SomeMarshmallowLibrary.mpck).

      @sources MyAppSource(MyAppSourceFiles,MyAppLibraryFiles).

      @if ( os == macOS ).

        @output(app::macOS::x86_64,MyAppSource). // app or pck or mod or lib or obj

      @elseif( os == Windows ).

       @output(app::Windows::x86_64,MyAppSource).

      @elseif( os == Linux ).

       @output(app::Linux::x86_64,MyAppSource).

      @endif.

     @end.

     function main( args main_args ).

      int[64] array.

      int i := 0.

      float y.

      sbyte x := ($i8($$$u64($$$int*($int[](array))))).

      y := (*($float*(&i))).

      y := ($$float(i)).
 
      List list := new().

      float value := (1.0).

      int value2 := ($int(3+value)).

      int value3 := func().

      { value2, value3 } := MyFunc().

      lambda() returns int func = lambda_start.

       return 1.

      end lambda.

     end function.

     template alloc(@type type_to_alloc) returns blank*.

       if ( _is_ptr(type_to_alloc) ) return _init(malloc(_sizeof(_typeofptr(type_to_alloc)))).

       return _init(malloc(_sizeof(type_to_alloc))).

     end template.

      _free function free(blank* ptr).

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

### Module System:

The concept for marshmallow is that it be based around an advanced module system; that allows macros and high-level type information to be stored along with code in binary files using bytecode. Marshmallow would use an [AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) based system, with each "compiled" module stored in a high-level bytecode file(.mmod), and distributed in a platform neutral manner. This removes the need for header files and allows for an advanced macro and type system, while maintaining native performance. In addition the possibility for a package file exists(.mpck), a binary archive file that includes many (.mmod) files as well as additional resources.

### Current Backend:

Marshmallow currently compiles to C. A [LLVM](https://llvm.org) or [QBE](https://c9x.me/compile/) backend may be implemented in the future.

Currently to compile marshmallow code you will need a C compiler and to manually invoke the compiler on the generated C code.

### Current Status:

Marshmallow as of now, is very much a work in progress. Core language features have yet to be implemented: most of type checking, classes, function calls, and lambdas, etc.

The compiler is full of bugs and memory leaks, as such marshmallow has a long way to go before v1.0, however work is ongoing and active.

helloworld.msrc provides a working example of marshmallow, while hellowolrd\_C_output.c is the C code marshmallow will  generate from helloworld.msrc.

### File Extensions:

##### .msrc - marshmallow source

##### .mmod - marshmallow module

##### .mpck - marshmallow package

## Building marshmallow

Any standard C11 compliant C compiler(64-bit) should be able to compile marshmallow, and the code it generates.

#### Dependencies for building marshmallow: 

 -RKLib https://github.com/JHG777000/RKLib
 
## License


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
 
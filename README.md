# marshmallow


Marshmallow is a work in progress programming language.

The goal is to create a language comparable to C in terms of flexibility, and closeness to the underlying hardware, with a more friendly syntax and modern language features.

Marshmallow aims to be an object-oriented language with support for lambdas, bounds-checking, multiple returns, and an advanced macro system that supports generics and metaprogramming.

### Goal:

The following is an example of what marshmallow aims to be:

	package mypackage.

     use source "main.msrc".

     use package "marshmallow_standard_libary/package.msrc".

     myflag: flag := yes.

    end package.

    module mymod.

     use module marshmallow.

     if ( mypackage::myflag == yes ).

      value: symbol := foo.

     else.

      value: symbol := bar.

     end if.

     typedef v3i32xyz vectype.

     typedef v3i8rbg#red#green#blue pixeltype.

     class myclass.

      private system_readwrite u32 a := 42.

      private readonly u32 b := 42.

      protected private_write u32 c := 42.

      protected system_readwrite u32 d := 42.

      protected writelimited u32 e := 42.

      private writelimited u32 f := 42.

      system_readwrite u32 g := 42.

      private_write u32 h := 42.

     end class.

     function main( args_class args ).

      vectype vector.

      pixeltype pixel.

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

      list_class list := new().

      generic_list_class list2 := new(myclass).

      int* ptr := null.

      float value := (1.0).

      int value2 := ($int(3+value)).

      int value3 := func().

      lambda function() returns int mylambda := _get_lambda(func).

      int value4 := mylambda().

      { value2, value3 } := MyFunc().

      function func() returns int.

       return 1.

      end function.

     end function.

     function alloc( type_to_alloc: type, allocator: identifier := mmalloc ) returns blank*.

     if ( _is_ptr(type_to_alloc) ).

      type_to_alloc retval := allocator(_sizeof(_typeofptr(type_to_alloc))).

     else.

      type_to_alloc* retval := allocator(_sizeof(type_to_alloc)).

     end if.

     if ( _is_class(type_to_alloc) ) _init(retval).

     return retval.

    end function.

    function free( freeable blank* ptr ).

     mfree(ptr).

    end function.

    class *list_class.

     private long num_of_nodes.

     private list_node first.

     private list_node last.

     class *list_node.

      private list_node before.

      private list_node after.

      private blank* data.

     end class.

    end class.

    class *generic_list_class( dataype: type ).

     private list_type: type := dataype.

     private long num_of_nodes.

     private list_node first.

     private list_node last.

     class *list_node( dataype: type ).

      private list_node before.

      private list_node after.

      private dataype data.

     end class.

    end class.

    method add_to_list( list_class list, blank* data ) returns list_node.

     if ( list->num_of_nodes == 0 ).

      list->first := alloc(list_class::list_node).

      list->last := list->first.

     else.

      list->last->after := alloc(list_class::list_node).

      list->last->after->before := list->last.

      list->last := list->last->after.

     end if.

     list->last->data := data.

     list->num_of_nodes++.

     return list->last.

    end method.

    method add_to_list( generic_list_class list, data: list->list_type ) returns list_node.

     if ( list->num_of_nodes == 0 ).

      list->first := alloc(generic_list_class::list_node(list->list_type)).

       list->last := list->first.

     else.

      list->last->after := alloc(generic_list_class::list_node(list->list_type)).

      list->last->after->before := list->last.

      list->last := list->last->after.

     end if.

     list->last->data := data.

     list->num_of_nodes++.

     return list->last.

    end method.

    overridable function new() returns.

    override function new( allocator: identifier := mmalloc ) returns list_class.

     list_class list := alloc(list_class,allocator).

     return list.

    end function.

    override function new( list_type: type, allocator: identifier := mmalloc ) returns generic_list_class.

      generic_list_class list := alloc(generic_list_class(list_type),allocator).

      return list.

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

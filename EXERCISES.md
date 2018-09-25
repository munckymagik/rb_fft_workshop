# Exercises

## 1) Adding code to marshal between Ruby and native data

Complete the missing parts of [`ext/rb_fft/rb_fft_native_impl.cpp`](./ext/rb_fft/rb_fft_native_impl.cpp) to convert the data to and from Ruby and C++ types.

You must first convert from Ruby to C++ ready to pass to the FFI engine. Then back again to pass the results back to the Ruby layer.

Use the compiler and the tests to drive you forward. Compile and test by running:

```
$ bundle exec rake
```

## 2) Find a safer way to handle Ruby exceptions to avoid memory leaks

Continuing in [`ext/rb_fft/rb_fft_native_impl.cpp`](./ext/rb_fft/rb_fft_native_impl.cpp). Look at how an argument exception is raised after we have allocated the `complex<double> *samples` array.

Exception handling in Ruby's C environment is ultimately controlled using two C library functions `setjump` and `longjump`. Research these functions. What kinds of bugs could happen if we don't handle exceptions carefully?

Look at this section on [Exceptions](http://silverhammermba.github.io/emberb/c/#exceptions). How could our code be refactored to safely handle any possible exception that could be raised and defend against leaking memory?

## 3) Writing benchmarks for the two FFT engines

Writes some benchmarks for the two engines to compare how they perform with different inputs.

You can use the built-in [Benchmark](http://ruby-doc.org/stdlib-2.5.1/libdoc/benchmark/rdoc/Benchmark.html) extension from Ruby's standard library.

See the [`bench`](./bench) folder for a starter example.

Which is faster? Why might that be?

Vary the input sizes. Is one consistently faster than the other?

## 4) Optimising the code to improve performance

What could we do to optimise both the Ruby and native engines?

## 5) Integrating other native libraries such as FFTW or the Apple Accelerator Framework

If anyone gets this far, see me for info :)

# Resources

## Primary references

* [The Definitive Guide to Ruby's C API](http://silverhammermba.github.io/emberb/c/) - Really good resource, good examples.
* [extension_rdoc](http://ruby-doc.org/core-2.5.1/doc/extension_rdoc.html) - From the core Ruby docs. A good starting point but lacks important details, and there are few examples.
* The Ruby source code itself. Ultimately this has all the real answers you need, if you look for them
  * https://github.com/ruby/ruby/
  * https://github.com/ruby/ruby/blob/trunk/include/ruby/ruby.h
  * https://github.com/ruby/ruby/blob/trunk/include/ruby/intern.h

## Real examples

Ruby FFI - should have examples of most/all possible marshalling of types you could want

* https://github.com/ffi/ffi/tree/master/ext/ffi_c
* https://github.com/ffi/ffi/blob/master/ext/ffi_c/Types.c

A small example of integrating an external C library

* https://github.com/tenderlove/stree/tree/part2/ext/stree

A *huge* example of integrated an external C library

* https://github.com/sparklemotion/nokogiri/tree/master/ext/nokogiri

A medium size example of an extension

* https://github.com/deivid-rodriguez/byebug/tree/master/ext/byebug

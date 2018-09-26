#include "rb_fft.h"
#include "cooley_tukey.h"

#include <complex>

using std::complex;

static ID idComplex;
static ID idReal;
static ID idImag;

static inline bool is_power_of_2(const long size) {
  return size > 0 && (size & (size - 1)) == 0;
}

static VALUE NativeImpl_fft(VALUE _self, VALUE rb_samples) {
  // Checks we have been passed an array or raises a TypeError
  Check_Type(rb_samples, T_ARRAY);

  const long samples_len = RARRAY_LEN(rb_samples);

  // The size of the input must be a power-of-2 for Cooley-Tukey because it splits its input in
  // half each time it recurses
  if (!is_power_of_2(samples_len)) {
    rb_raise(rb_eArgError, "array size must be a power of 2");
  }

  // NOTE memory malloc'd here
  complex<double> *samples = new complex<double>[samples_len];

  // Marshall Ruby input into C++
  for (long i = 0; i < samples_len; ++i) {
    // Fetch a element from the array
    /* TODO complete me */
    VALUE elem = rb_samples[i]

    // The element must be of Ruby type Complex
    // if (!RB_TYPE_P(elem, T_COMPLEX)) {
    //   // NOTE memory freed here
    //   delete[] samples;

    //   rb_raise(rb_eArgError, "array elements must be Complex numbers");
    // }

    // Call accessors on the Complex to fetch the two components
    /* TODO complete me */

    // Convert Ruby values to C data
    /* TODO complete me */

    // Convert to complex<T> then add to the array
    /* TODO complete me */
  }

  // Do FFT calculation here NOTE mutates input!
  cooley_tukey::fft_in_place(samples, samples_len);

  // TODO pre-allocate as we know the size
  VALUE rb_result = rb_ary_new();

  // Marshall C++ state into Ruby output
  for (long i = 0; i < samples_len; ++i) {
    // Get the native complex
    /* TODO complete me */

    // Convert data to a Ruby representation
    /* TODO complete me */

    // Create a Ruby Complex. It has a private constructor we must call the
    // global function `Complex(...)` to construct a new instance
    /* TODO complete me */

    // Push into the result array
    /* TODO complete me */
  }

  // NOTE memory freed here
  delete[] samples;

  return rb_result;
}

void Init_RbFFT_NativeImpl(VALUE mRbFFT) {
  VALUE mRbFFTNativeImpl = rb_define_module_under(mRbFFT, "NativeImpl");
  rb_define_module_function(mRbFFTNativeImpl, "fft", RUBY_METHOD_FUNC(NativeImpl_fft), 1);

  // Fetch Ruby symbols we will need when calling methods
  idComplex = rb_intern("Complex");
  idReal = rb_intern("real");
  idImag = rb_intern("imag");
}

# RbFFT Tutorial

The purpose of this repo is to provide a basis for a tutorial on programming Ruby extensions in C/C++.

It includes a simple implementation of the [Cooley-Tukey](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm) [Fast Fourier Transform (FFT)](https://en.wikipedia.org/wiki/Fast_Fourier_transform) algorithm in both Ruby and C++. The FFT is an important algorithm in the realm of Digital Signal Processing (DSP) because it allows us to identify frequencies within signals.

## Exercises

Several tasks have been created for workshop attendees to complete. These
include:

* Adding code to marshal between Ruby and native data
* Find a safer way to handle Ruby exceptions to avoid memory leaks
* Writing benchmarks for the two FFT engines
* Optimising the code to improve performance
* Integrating other native libraries such as FFTW or the Apple Accelerator Framework

See [EXERCISES.md](./EXERCISES.md) for details.

## Usage

To set up:

    $ bundle

To build and run the tests

    $ bundle exec rake

If you need to experiment in a console

    $ ./bin/console

Then run the command-line client to experiment with the inputs and outputs of the algorithm

```
$ ./exe/rbfft --samples 32 --freqs 1,2,4,8,10,12 --engine native
Engine: RbFFT::NativeImpl
Num Samples: 32
Frequencies: 1, 2, 4, 8, 10, 12

Index	Sample
  0	0.000000
  1	3.915867
  2	0.382683
  3	1.510980
  4	2.707107
  5	0.958452
  6	0.923880
  7	0.126865
  8	1.000000
  9	2.088436
 10	0.923880
 11	0.704487
 12	1.292893
 13	0.399839
 14	0.382683
 15	3.525686
 16	0.000000
 17	3.525686
 18	0.382683
 19	0.399839
 20	1.292893
 21	0.704487
 22	0.923880
 23	2.088436
 24	1.000000
 25	0.126865
 26	0.923880
 27	0.958452
 28	2.707107
 29	1.510980
 30	0.382683
 31	3.915867

Freq	Amp	Histogram
  0	  0
  1	 16	================
  2	 16	================
  3	  0
  4	 16	================
  5	  0
  6	  0
  7	  0
  8	 16	================
  9	  0
 10	 16	================
 11	  0
 12	 16	================
 13	  0
 14	  0
 15	  0
```

The above command shows example output. We instructed the library to generate 32 samples of a signal blending 1, 2, 4, 8, 10 and 12 Hz sine waves.

The values of these 32 samples are output in the first table displayed. The data here is tab-delimited so you could copy and paste it into a spreadsheet software and plot the samples in a chart.

In the second table it shows the output of the FFT algorithm which correctly identified the 6 frequencies contained in the signal. The bars in the histogram mark the amplitude of signals detected.

# BCD Arithmetic Library in C++

This project provides a C++ library for Binary Coded Decimal (BCD) arithmetic operations. It is built using CMake as the build tool, and Google Test for unit testing.

## Table of Contents

- [BCD Representation](#bcd-representation)
- [Features](#features)
- [Implementation](#implementation)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
  - [Building the Library](#building-the-library)
  - [Running Unit Tests](#running-unit-tests)
  <!-- - [Using the Library](#using-the-library) -->

## BCD Representation

```cpp
struct BCD {
    std::vector<unsigned char> digits_before_point;
    std::vector<unsigned char> digits_after_point;
};
```

Each decimal digit is represented by a single byte (`unsigned char`). The most significant digit is stored in the first element of the vector. The digits are stored in the vector in the same order as they are in the BCD number. The digits before the point are stored in the `digits_before_point` vector, and the digits after the point are stored in the `digits_after_point` vector.

## Features

Supported operations:

- Addition
- Subtraction
- Multiplication
- ~~Division~~

## Implementation

Assembly instructions used to adjust the result of operations can be found [here](https://www.felixcloutier.com/x86/). The following instructions are used:
- [AAA](https://www.felixcloutier.com/x86/aaa): ASCII Adjust After Addition
- [AAS](https://www.felixcloutier.com/x86/aas): ASCII Adjust AL After Subtraction
- [AAM](https://www.felixcloutier.com/x86/aam): ASCII Adjust AX After Multiply
<!-- - [AAD](https://www.felixcloutier.com/x86/aad): ASCII Adjust AX Before Division -->

The assembly code is written for x86-64 architecture, and compiled using the GNU assembler (GAS).

## Prerequisites

To use this library, you need to have the following software installed on your system:

- A C++ compiler that supports C++11 or later
- CMake (version 3.14 or later)

## Getting Started

### Building the Library

To build the library on linux, follow these steps:

1. Clone the repository:

   ```sh
   git clone https://github.com/Mario-659/bcd_arithmetic
   cd bcd_arithmetic
   ```

2. Create a buld directory and change to it:

   ```sh
   mkdir build
   cd build
   ```
3. Run CMake to generate the build files:

   ```sh
   cmake ..
   ```
4. Build the library:

   ```sh
   make
   ```

If you are getting error below:
   
   ```sh
   fatal error: bits/c++config.h: No such file or directory
   #include <bits/c++config.h>
   ```
then make sure to install dependencies needed for 64-bit architecture:
      
   ```sh
   sudo apt-get update && sudo apt-get install -y g++-multilib libc6-dev-i386
   ```

### Running Unit Tests

The unit tests are implemented using [Google Test](https://github.com/google/googletest).
To run the tests, follow these steps:

1. Build the library as described in the previous section.
2. Run the unit tests:

   ```sh
   make test
   ```

<!-- ### TODO Using the Library -->


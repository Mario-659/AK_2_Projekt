# BCD Arithmetic Library in C++

This project provides a C++ library for Binary Coded Decimal (BCD) arithmetic operations. It is built using CMake as the build tool, and Google Test for unit testing.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
  - [Building the Library](#building-the-library)
  - [Running Unit Tests](#running-unit-tests)
  <!-- - [Using the Library](#using-the-library) -->

## Features

This BCD Arithmetic Library supports the following operations:

- Addition
- Subtraction
- Multiplication
- Division
- BCD-to-Decimal conversion
- Decimal-to-BCD conversion

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

### Running Unit Tests
To run the unit tests, follow these steps:

1. Build the library as described in the previous section.
2. Run the unit tests:

   ```sh
   make test
   ```

<!-- ### TODO Using the Library -->


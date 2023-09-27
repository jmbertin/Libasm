# libasm

A collection of basic C functions implemented in Assembly.

----
## Introduction

This repository contains a library of basic functions typically found in C, but these functions are implemented in Assembly using NASM.

----
## Functions

The library contains the following functions:

- `ft_strlen`: Calculate the length of a string.
- `ft_strcpy`: Copy a string to a destination.
- `ft_strcmp`: Compare two strings.
- `ft_write`: Write data to a file descriptor.
- `ft_read`: Read data from a file descriptor.
- `ft_strdup`: Duplicate a string.

----
## Compilation

The code is written in Assembly and needs the NASM assembler for compilation. The provided Makefile has several rules for building and cleaning the project:

- `make all`: Build the library `libasm.a`.
- `make clean`: Remove all object files.
- `make fclean`: Remove all object files and the `libasm.a` library.
- `make re`: Re-build everything.
- `make tests`: Compile with the test file to verify the library's functionality.

----
## Usage

Once the library is built, it can be linked with other C files and used just like any other C library.

For testing purposes, compile your C file with `libasm.a`:

``gcc your_file.c -L. -lasm -o output_name``

You can also use the provided test file (main.c):

``make tests``

----
## Contribution
If you encounter any bugs or wish to add features, please feel free to open an issue or submit a pull request.

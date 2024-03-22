Group proyect: Joshua Maldonado & Carlos Soto

# Project:Printf

This project is a simplified version of the `printf` function in C

## Contents
1. [Overview](#overview)
2. [File Descriptions](#file-description)
3. [How to use](#how-to-use)

## Overview <a name="overview"></a>
The project consists of the following files:

- `_printf.c`: Contains `_printf` function.
- `functions.c`: Contains helper functions used by `_printf`.
- `main.h`: Header file containing function prototypes.
- `man_3_printf`: Manual page for the custom _printf function.

## File Descriptions <a name="file-description"></a>

- `_printf.c`: This file contains the creation of the `_printf` function, which mimics the behavior of the standard `printf` function in C. It includes support for various format specifiers such as `%c`, `%s`, `%d`, `%i`, and `%`.

- `functions.c`: This file contains helper functions utilized by `_printf` to handle specific format specifiers. Each function corresponds to a particular format specifier and is responsible for formatting and printing the corresponding data.

- `main.h`: Header file containing function prototypes and necessary includes for the project.

- `man_3_printf`: This file provides documentation for 'printf' function in the style of a Unix manual page. It includes usage instructions and description.

## How to use <a name="how-to-use"><\a>

To use the custom "printf" function in your C program, include the "main.h" header file in your source file and call "_printf" with the desired format string and arguments.

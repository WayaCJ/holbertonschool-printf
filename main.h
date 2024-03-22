#ifndef JC_HEADER_H
#define JC_HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 *struct specifier - struct
 *@valid: char
 *@f: f
 */

typedef struct specifier
{
char *valid;
int (*f)(va_list);
} spec;
int _printf(const char *format, ...);
int i_char(va_list args);
int i_string(va_list args);
int i_int(va_list args);
int i_unint(unsigned int num);
int i_percent(__attribute__((unused)) va_list list);
int i_direct(char c);
int write_unsigned_octal(va_list args);
int write_unsigned_hex(va_list args);
int write_pointer(va_list args);
int _print_d(va_list f);
int _print_i(va_list f);

#endif /* JC_HEADER_H */

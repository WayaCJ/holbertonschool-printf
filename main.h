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
int _print_s(const char *str);
int _print_d(va_list f);
int _print_i(va_list f);
#endif

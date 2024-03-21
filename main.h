#ifndef JC_HEADER_H
#define JC_HEADER_H

#include <stdarg.h>

int _printf(const char *format, ...);
int i_char(va_list args);
int i_string(va_list args);
int i_int(va_list args);
int i_unint(unsigned int num);
int i_percent(void);
int i_direct(char c);
int write_unsigned_octal(va_list args);
int write_unsigned_hex(va_list args);
int write_pointer(va_list args);

#endif /* JC_HEADER_H */

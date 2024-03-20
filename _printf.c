#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int c = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == %)
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					c++;
					break;

#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 *_printf- output
 *@format: directives
 *Return: printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int c = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					c++;
					break;
				case 's':
					{
						c += _print_s(va_arg(args, const char *));
						break;
					}
					break;
				case '%':
					putchar('%');
					c++;
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			c++;
		}
		format++;
	}
	va_end(args);
	return (c);
}

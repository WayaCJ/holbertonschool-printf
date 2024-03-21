#include <stdarg.h>
#include <stdio.h>
#include "main.h"

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
						const char *str = va_arg(args, const char*);

						while (*str)
						{
							putchar(*str++);
							c++;
						}
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

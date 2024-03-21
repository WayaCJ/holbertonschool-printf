#include "main.h"
#include <unistd.h>
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
					c += i_char(args);
					break;
				case 's':
					c += i_string(args);
					break;
				case 'd':
				case 'i':
					c += i_int(args);
					break;
				case 'o':
					c += write_unsigned_octal(args);
					break;
				case 'x':
					c += write_unsigned_hex(args);
					break;
				case 'p':
					c += write_pointer(args);
					break;
				case '%':
					c += i_percent();
					break;
				default:
					c += i_direct(*format);
					break;
			}
		}
		else
		{
			write(1, format, 1);
			c++;
		}
		format++;
	}
	va_end(args);
	return (c);
}

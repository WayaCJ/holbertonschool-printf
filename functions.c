#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *i_char: character
 *i_string: string
 *i_int: integer
 *i_unint: unsigned int
 *i_percent: prints %
 */
int i_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

int i_string(va_list args)
{
	const char *str = va_arg(args, const char*);
	int count = 0;

	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int i_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
		count++;
	}
	count += i_unint((unsigned int)num);
	return (count);
}

int i_unint(unsigned int num)
{
	int count = 0;
	char d;

	if (num / 10)
		count += i_unint(num / 10);
	d = '0' + (char)(num % 10);
	write(1, &d, 1);
	return (count + 1);
}

int i_percent(void)
{
	char percent = '%';

	write(1, &percent, 1);
	return (1);
}

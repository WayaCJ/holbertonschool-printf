#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 *i_char- character
 *@args: arguments
 *Return: characters
 */
int i_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
/**
 *i_string- print string
 *@args: argu
 *Return: characters
 */
int i_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}
/**
 *i_int- prit int
 *@args: arguments
 *Return: characters
 */
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
/**
 *i_unint- unsigned
 *@num: number
 *Return: 1
 */
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
/**
 * i_percent- %
 *Return: void
 */
int i_percent(__attribute__((unused)) va list list)
{
	char percent = '%';

	write(1, &percent, 1);
	return (1);
}

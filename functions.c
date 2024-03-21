#include <stdio.h>
/**
 *_print_s- prints string
 *@str: string
 *Return: result
 */
int _print_s(const char *str)
{
	int c = 0;

	while (*str)
	{
		putchar(*str++);
		c++;
	}
	return (c);
}

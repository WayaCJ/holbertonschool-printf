#include "main.h"
/**
 *_print_d - print base 10
 *@f: decimal to print
 *Return: base 10
 */

int _print_d(va_list f)
{
unsigned int abs, a, count1, count;
int j;

count = 0;
j = va_arg(f, int);
if (j < 0)
{
abs = (j * -1);
count += putchar('-');
}
else
abs = j;

a = abs;
count1 = 1;
while (a > 9)
{
a /= 10;
count1 *= 10;
}
while (count1 >= 1)
{
count += putchar(((abs / count1) % 10) + '0');
count1 /= 10;
}
return (count);
}

/**
 *_print_i - print interger
 *@f: int to print
 *Return: int
 */

int _print_i(va_list f)
{
return (_print_d(f));
}
/**
 *i_direct- prints % and address of c
 *@c: character
 *Return: 2
 */
int i_direct(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

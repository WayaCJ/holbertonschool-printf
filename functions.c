#include "main.h"
#include <unistd.h>
#include <stdarg.h>
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
	return count;
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
int i_direct(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

int write_unsigned_octal(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    char buffer[20];
    int index = 0, i = index - 1;

    do {
        buffer[index++] = (num % 8) + '0';
        num /= 8;
    } while (num != 0);

    while (i >= 0) 
    {
	i--;
        write(1, &buffer[i], 1);
        count++;
    }

    return count;
}

int write_unsigned_hex(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    char buffer[20];
    const char *hex_chars = "0123456789abcdef";
    int index = 0, i = index - 1;
    do {
        buffer[index++] = hex_chars[num % 16];
        num /= 16;
    } while (num != 0);

    while (i >= 0)
    {
	i--;
        write(1, &buffer[i], 1);
        count++;
    }

    return count;
}

int write_pointer(va_list args) {
    void *ptr = va_arg(args, void *);
    unsigned long num = (unsigned long)ptr;
    int count = 0, index = 0, i = index - 1;
    char buffer[20];
    const char *hex_chars = "0123456789abcdef";

    write(1, "0x", 2);
    count += 2;

    do {
        buffer[index++] = hex_chars[num % 16];
        num /= 16;
    } while (num != 0);

    while (i >= 0)
    {
	    i--;
        write(1, &buffer[i], 1);
        count++;
    }

    return count;
}

#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int count = 0, started = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
			started = 1;
			count++;
		}
		else if (started)
		{
			_putchar('0');
			count++;
		}
		mask >>= 1;
	}
	return (count);
}


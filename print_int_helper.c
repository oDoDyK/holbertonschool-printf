#include "main.h"

/**
 * print_int_helper - recursive function to print digits
 * @num: unsigned integer
 *
 * Return: number of characters printed
 */
int print_int_helper(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_int_helper(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

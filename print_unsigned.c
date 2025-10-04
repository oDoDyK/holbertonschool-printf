#include "main.h"

/**
 * print_unsigned_number - helper to print an unsigned integer recursively
 * @n: unsigned int to print
 * Return: number of digits printed
 */
int print_unsigned_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_number(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_unsigned - prints an unsigned integer (%u)
 * @args: argument list
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	return (print_unsigned_number(num));
}

/**
 * print_octal_number - helper to print an unsigned number in octal recursively
 * @n: number
 * Return: number of digits printed
 */
int print_octal_number(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal_number(n / 8);

	_putchar((n % 8) + '0');
	count++;

	return (count);
}

/**
 * print_octal - prints an unsigned integer in octal (%o)
 * @args: argument list
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	return (print_octal_number(num));
}

/**
 * print_hex_number - helper to print number in hexadecimal (lower/upper)
 * @n: number
 * @uppercase: 0 for lowercase, 1 for uppercase
 * Return: number of digits printed
 */
int print_hex_number(unsigned int n, int uppercase)
{
	int count = 0;
	char digit;

	if (n / 16)
		count += print_hex_number(n / 16, uppercase);

	digit = n % 16;

	if (digit < 10)
		_putchar(digit + '0');
	else
		_putchar((uppercase ? 'A' : 'a') + (digit - 10));

	count++;

	return (count);
}

/**
 * print_hex - prints unsigned int in lowercase hex (%x)
 * @args: argument list
 * Return: number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return (print_hex_number(n, 0));
}

/**
 * print_HEX - prints unsigned int in uppercase hex (%X)
 * @args: argument list
 * Return: number of characters printed
 */
int print_HEX(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return (print_hex_number(n, 1));
}


#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - write a character to stdout
 * @c: character
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_text - print a string
 * @s: string
 *
 * Return: number of characters printed
 */
static int print_text(const char *s)
{
	int total = 0;
	int ret;

	if (!s)
		s = "(null)";

	while (*s)
	{
		ret = _putchar(*s);
		if (ret == -1)
			return (-1);
		total += ret;
		s++;
	}
	return (total);
}

/**
 * print_int - print an integer
 * @n: integer
 *
 * Return: number of characters printed
 */
int main(void)
{
	_printf("Hello, %s! Number: %d%%\n", "world", 42);
	return (0);
}
static int print_int(int n)
{
	unsigned int val;
	int total = 0;
	int ret;

	if (n < 0)
	{
		ret = _putchar('-');
		if (ret == -1)
			return (-1);
		total += ret;
		val = (unsigned int)(-n);
	}
	else
		val = (unsigned int)n;

	if (val / 10)
	{
		ret = print_int(val / 10);
		if (ret == -1)
			return (-1);
		total += ret;
	}

	ret = _putchar((val % 10) + '0');
	if (ret == -1)
		return (-1);
	total += ret;

	return (total);
}

/**
 * handle_format - handle one format specifier
 * @c: format character
 * @ap: argument list
 *
 * Return: number of characters printed
 */
static int handle_format(char c, va_list ap)
{
	int ret;

	if (c == 'c')
		return (_putchar((char)va_arg(ap, int)));
	if (c == 's')
		return (print_text(va_arg(ap, char *)));
	if (c == '%')
		return (_putchar('%'));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(ap, int)));

	ret = _putchar('%');
	if (ret == -1)
		return (-1);
	if (_putchar(c) == -1)
		return (-1);

	return (2);
}

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	int ret;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ret = _putchar(*format);
			if (ret == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += ret;
		}
		else
		{
			format++;
			if (!*format)
			{
				va_end(ap);
				return (-1);
			}
			ret = handle_format(*format, ap);
			if (ret == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += ret;
		}
		format++;
	}
	va_end(ap);
	return (count);
}


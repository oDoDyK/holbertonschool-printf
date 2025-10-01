#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - handles a conversion specifier
 * @specifier: the specifier character
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	char *str;
	int count = 0;

	if (specifier == 'c')
		count += _putchar(va_arg(args, int));
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
		{
			_putchar(*str++);
			count++;
		}
	}
	else if (specifier == '%')
		count += _putchar('%');
	else
	{
		count += _putchar('%');
		count += _putchar(specifier);
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string with conversion specifiers
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i]) /* lone % at end */
			{
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}


#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
			else if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}
			else
				count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);
		i++;
	}

	va_end(args);
	return (count);
}


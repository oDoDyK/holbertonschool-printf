#include "main.h"
#include <stdarg.h>

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
	char *str;

	if (!format) /* null format string */
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i]) /* lone '%' at end */
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
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
			else if (format[i] == '%')
				count += _putchar('%');
			else /* unsupported specifier: print % and char */
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
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


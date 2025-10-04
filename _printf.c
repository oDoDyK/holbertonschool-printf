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
	int (*func)(va_list);
	char buffer[1024];
	int buf_index = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			func = get_func(format[i]);
			if (func)
			{
				/* Flush buffer before calling function that uses _putchar */
				if (buf_index > 0)
				{
					write(1, buffer, buf_index);
					count += buf_index;
					buf_index = 0;
				}
				count += func(args);
			}
			else
			{
				if (buf_index >= 1024)
				{
					write(1, buffer, buf_index);
					count += buf_index;
					buf_index = 0;
				}
				buffer[buf_index++] = '%';
				buffer[buf_index++] = format[i];
			}
		}
		else
		{
			if (buf_index >= 1024)
			{
				write(1, buffer, buf_index);
				count += buf_index;
				buf_index = 0;
			}
			buffer[buf_index++] = format[i];
		}
		i++;
	}

	/* Flush remaining buffer */
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		count += buf_index;
	}

	va_end(args);
	return (count);
}


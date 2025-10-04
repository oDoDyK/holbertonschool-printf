#include "main.h"

/* Define buffer size */
#define BUF_SIZE 1024

/**
 * flush_buffer - writes the contents of buffer to stdout
 * @buffer: buffer array
 * @buf_index: number of chars currently in buffer
 * Return: number of characters written
 */
static int flush_buffer(char *buffer, int *buf_index)
{
	int count = 0;

	if (*buf_index > 0)
	{
		count = write(1, buffer, *buf_index);
		*buf_index = 0;
	}
	return (count);
}

/**
 * _printf - produces output according to a format string
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*func)(va_list);
	char buffer[BUF_SIZE];
	int buf_index = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break;

			func = get_func(format[i]);
			if (func)
			{
				/* Flush buffer before calling a function that uses _putchar */
				count += flush_buffer(buffer, &buf_index);
				count += func(args);
			}
			else
			{
				/* If unknown specifier, buffer '%' and character */
				if (buf_index >= BUF_SIZE - 2)
					count += flush_buffer(buffer, &buf_index);
				buffer[buf_index++] = '%';
				buffer[buf_index++] = format[i];
			}
		}
		else
		{
			/* Add normal character to buffer */
			if (buf_index >= BUF_SIZE)
				count += flush_buffer(buffer, &buf_index);
			buffer[buf_index++] = format[i];
		}
		i++;
	}

	/* Flush remaining characters */
	count += flush_buffer(buffer, &buf_index);

	va_end(args);
	return (count);
}


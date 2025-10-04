#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
static int print_string(const char *s)
{
	int count = 0;
	int ret;

	if (!s)
		s = "(null)";

	while (*s)
	{
		ret = _putchar(*s);
		if (ret == -1)
			return (-1);
		count += ret;
		s++;
	}
	return (count);
}

/**
 * _printf - prints according to a format
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

			if (*format == 'c')
				ret = _putchar(va_arg(ap, int));
			else if (*format == 's')
				ret = print_string(va_arg(ap, const char *));
			else if (*format == '%')
				ret = _putchar('%');
			else
				ret = _putchar('%'), ret += _putchar(*format);

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

/* Optional inline main for testing */
#ifdef TEST_PRINTF
int main(void)
{
	_printf("0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life\n");
	_printf("Character: %c, String: %s, Percent: %%\n", 'A', "Hello");
	return (0);
}
#endif


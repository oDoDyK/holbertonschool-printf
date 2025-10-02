#include "main.h"

/**
 * handle_format - Handle a format specifier and print accordingly
 * @format_char: The format specifier character
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int handle_format(char format_char, va_list args)
{
	if (format_char == 'c')
		return (print_char(args));
	if (format_char == 's')
		return (print_string(args));
	/*--*/
	if (format_char == 'd' || format_char == 'i')
        return (print_int(args));
	
	if (format_char == '%')
		return (write(1, "%", 1));

	/* Unknown specifier: print '%' and the character */
	write(1, "%", 1);
	return (write(1, &format_char, 1) + 1);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0, res;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			res = handle_format(format[i], args);
			printed += res;
		}
		else
		{
			printed += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (printed);
}


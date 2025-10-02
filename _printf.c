#include "main.h"
#include <stdarg.h>

/**
 * _printf - custom printf handling %d and %i
 * @format: format string
 * Return: number of characters printed
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
            if (format[i] == 'd' || format[i] == 'i')
                count += print_number((long int)va_arg(args, int));
            else if (format[i])  /* print unsupported specifier literally */
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
            else
                return (-1); /* dangling % at end */
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


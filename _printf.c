#include "_printf.h"
#include <unistd.h>

/**
 * print_char - prints a single character
 * @c: the character to print
 *
 * Return: number of characters printed (1)
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - prints a string
 * @s: the string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int len = 0;

    if (!s)
        s = "(null)";  /* safe for %s */

    while (*s)
    {
        write(1, s, 1);
        s++;
        len++;
    }
    return len;
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string containing characters and specifiers
 *
 * Description: Handles %c, %s, %% and unknown specifiers.
 *              If format is NULL, does nothing and returns 0.
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return 0;  /* Fixed: _printf(NULL) prints nothing */

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                count += print_char('%');
            else if (format[i] == '\0')
                break;
            else
            {
                count += print_char('%');
                count += print_char(format[i]);
            }
        }
        else
            count += print_char(format[i]);
        i++;
    }

    va_end(args);
    return count;
}


#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Print a single char */
int print_char(char c)
{
    return write(1, &c, 1);
}

/* Print a string */
int print_string(char *s)
{
    int len = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        write(1, s, 1);
        s++;
        len++;
    }
    return len;
}

/* The _printf function */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return print_string("(null)");

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

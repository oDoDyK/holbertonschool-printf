#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: the format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char ch;
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);
    ptr = format;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                ch = (char)va_arg(args, int);
                write(1, &ch, 1);
                count++;
            }
            else if (*ptr == 's')
            {
                str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*ptr == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, "%", 1);
                write(1, ptr, 1);
                count += 2;
            }
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
        ptr++;
    }

    va_end(args);
    return (count);
}


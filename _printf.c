while (format && format[i])
{
    if (format[i] == '%')
    {
        i++;
        if (!format[i])  /* if '%' is last character */
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
        else
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


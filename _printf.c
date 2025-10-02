#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_char - prints a single character
 * @c: the character to print
 * Return: number of characters printed (1)
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - prints a string
 * @s: the string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int len = 0;

    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        write(1, s, 1);
        s++;
        len++;
    }
    return len;
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
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

/* Example test cases */
int main(void)
{
    char *str = "This is a very long string to test _printf functionality.\n";

    _printf("%c\n", 'S');
    _printf("A char inside a sentence: %c. Did it work?\n", 'F');
    _printf("Let's see if the cast is correctly done: %c. Did it work?\n", 48);
    _printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c",
            'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    _printf("%%\n");
    _printf("Should print a single percent sign: %%\n");
    _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    _printf("css%ccs%scscscs\n", 'T', "Test");
    _printf("%s", str);
    _printf("man gcc:\n%s", str);
    _printf(NULL);
    _printf("%c", '\0');
    _printf("%");
    _printf("%!\n");
    _printf("%K\n");

    return 0;
}


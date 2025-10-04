#include "main.h"

/**
 * get_func - selects correct print function
 * @c: format specifier
 * Return: pointer to print function
 */
int (*get_func(char c))(va_list)
{
    print_t ops[] = {
        {'c', print_char},
        {'s', print_string},
        {'d', print_int},
        {'i', print_int},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_HEX},
        {0, NULL}
    };

    int i = 0;

    while (ops[i].spec)
    {
        if (ops[i].spec == c)
            return (ops[i].f);
        i++;
    }
    return (NULL);
}


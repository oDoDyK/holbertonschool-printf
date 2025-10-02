#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int print_number(long int n)
{
    int count = 0;
    unsigned long int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');
    return (count);
}


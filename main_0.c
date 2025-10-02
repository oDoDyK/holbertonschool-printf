#include <stddef.h>   /* for NULL */
#include "_printf.h"

/**
 * main - test _printf with edge cases
 *
 * Return: 0
 */
int main(void)
{
    char *str = "This is a long string to test _printf functionality.\n";

    /* Edge case tests */
    _printf(NULL);                  /* Output: (null) */
    _printf("%c", '\0');            /* Output: invisible character */
    _printf("%");                    /* Output: % */
    _printf("%!\n");                 /* Output: %!\n */
    _printf("%K\n");                 /* Output: %K\n */
    _printf("%s", str);              /* Output: long string */
    _printf("Hello %% World!\n");    /* Output: Hello % World! */

    return 0;
}

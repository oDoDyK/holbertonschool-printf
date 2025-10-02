#include <stdio.h>

/* Declare _printf so main knows about it */
int _printf(const char *format, ...);

int main(void)
{
    int len;

    len = _printf("Hello %s! This is a test: %c %%\n", "world", 'A');
    _printf("Number of characters printed: %d\n", len);

    /* Test NULL string */
    _printf("Testing NULL string: %s\n", NULL);

    /* Test just percent */
    _printf("Show percent: %%\n");

    return 0;
}

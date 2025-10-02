/* Test _printf */

int _printf(const char *format, ...);

int main(void)
{
    _printf("Hello World!\n");
    _printf("Character: %c, String: %s, Percent: %%\n", 'A', "Test");
    return 0;
}

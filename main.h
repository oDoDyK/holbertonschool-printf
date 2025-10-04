#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct print - structure for format specifiers and their functions
 * @spec: format specifier character (e.g., 'c', 's', 'd')
 * @f: function pointer to the corresponding print function
 */
typedef struct print
{
    char spec;
    int (*f)(va_list);
} print_t;

/* Main printf function */
int _printf(const char *format, ...);

/* Helper print functions */
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);

/* Function selector */
int (*get_func(char c))(va_list);

#endif /* MAIN_H */

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Main function */
int _printf(const char *format, ...);
int _putchar(char c);

/* Helpers */
int _putchar(char c);
int print_int(va_list args);
int print_int_helper(unsigned int num);

#endif /* MAIN_H */

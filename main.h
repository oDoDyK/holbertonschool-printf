#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - struct for specifiers
 * @c: character representing the specifier
 * @f: pointer to function to handle the specifier
 */
typedef struct specifier
{
	char c;
	int (*f)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int (*get_func(char s))(va_list);

#endif


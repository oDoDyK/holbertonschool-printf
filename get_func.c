#include "main.h"

/**
 * get_func - selects the correct function for a format specifier
 * @s: specifier character
 *
 * Return: pointer to function or NULL if not found
 */
int (*get_func(char s))(va_list)
{
	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{0, NULL}
	};
	int i = 0;

	while (specifiers[i].c)
	{
		if (s == specifiers[i].c)
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}


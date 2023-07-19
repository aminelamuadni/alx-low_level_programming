#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints a name.
 * @name: pointer to a string.
 * @f: pointer to a function that takes a string as argument.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}

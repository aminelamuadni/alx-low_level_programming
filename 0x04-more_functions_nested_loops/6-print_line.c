#include "main.h"

/**
 * print_line - Draws a straight line in the terminal using underscores.
 * @n: The number of times the underscore character should be printed.
 */

void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	while (n > 0)
	{
		_putchar('_');
		n--;
	}

	_putchar('\n');
}

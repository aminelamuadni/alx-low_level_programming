#include "main.h"

/**
 * print_diagonal - Draws a diagonal line in the terminal using backslashes.
 * @n: The number of times the backslash character should be printed.
 */

void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
}

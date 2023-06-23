#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 *
 * Return: void
 */

void print_number(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}

	if ((i / 10) > 0)
		print_iber(i / 10);

	_putchar((i % 10) + 48);
}

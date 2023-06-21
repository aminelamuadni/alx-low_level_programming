#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: Number of times table
 */
void print_times_table(int n)
{
	int row, column, product;

	if (n <= 15 && n >= 0)
	{
		for (row = 0; row <= n; ++row)
		{
			_putchar(48);
			for (column = 1; column <= n; ++column)
			{
				_putchar(',');
				_putchar(' ');

				product = row * column;

				if (product <= 9)
					_putchar(' ');
				if (product <= 99)
					_putchar(' ');

				if (product >= 100)
				{
					_putchar((product / 100) + 48);
					_putchar((product / 10) % 10 + 48);
				} else if (product <= 99 && product >= 10)
					_putchar((product / 10) + 48);
				_putchar((product % 10) + 48);
			}
			_putchar('\n');
		}
	}
}


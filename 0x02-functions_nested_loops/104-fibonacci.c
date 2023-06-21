#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a, b, c, d1, d2, e1, e2;

	b = 1;
	c = 2;

	printf("%lu", b);

	for (a = 1; a < 91; a++)
	{
		printf(", %lu", c);
		c = c + b;
		b = c - b;
	}

	d1 = b / 1000000000;
	d2 = b % 1000000000;
	e1 = c / 1000000000;
	e2 = c % 1000000000;

	for (a = 92; a < 99; ++a)
	{
		printf(", %lu", e1 + (e2 / 1000000000));
		printf("%lu", e2 % 1000000000);
		e1 = e1 + d1;
		d1 = e1 - d1;
		e2 = e2 + d2;
		d2 = e2 - d2;
	}

	printf("\n");

	return (0);
}


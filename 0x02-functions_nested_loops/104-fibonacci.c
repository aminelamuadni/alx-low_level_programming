#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a, b, c, d1, d2, e1, e2;

	a = 1;
	b = 2;

	printf("%lu", a);

	for (unsigned long int i = 1; i < 91; i++)
	{
		printf(", %lu", b);
		c = b + a;
		a = b - a;
		b = c;
	}

	d1 = a / 1000000000;
	d2 = a % 1000000000;
	e1 = b / 1000000000;
	e2 = b % 1000000000;

	for (unsigned long int i = 92; i < 99; ++i)
	{
		printf(", %lu", e1 + (e2 / 1000000000));
		printf("%lu", e2 % 1000000000);
		e1 = e1 + d1;
		d1 = e1 - d1;
		e2 = e2 + d2;
		d2 = e2 - d2;
	}

	printf("\n");

	return 0;
}


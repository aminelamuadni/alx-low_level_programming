#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number1 = 0, number2;

	while (number1 <= 99)
	{
		number2 = number1;
		while (number2 <= 99)
		{
			if (number2 != number1)
			{
				putchar((number1 / 10) + 48);
				putchar((number1 % 10) + 48);
				putchar(' ');
				putchar((number2 / 10) + 48);
				putchar((number2 % 10) + 48);

				if (number1 != 98 || number2 != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
			++number2;
		}
		++number1;
	}
	putchar('\n');

	return (0);
}


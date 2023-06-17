#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number1 = 0;
	int number2, number3;

	while (number1 <= 9)
	{
		number2 = 0;
		while (number2 <= 9)
		{
			number3 = 0;
			while (number3 <= 9)
			{
				if (number1 != number2 &&
				    number1 < number2 &&
				    number2 != number3 &&
				    number2 < number3)
				{
					putchar(number1 + 48);
					putchar(number2 + 48);
					putchar(number3 + 48);

					if (number1 + number2 + number3 != 24)
					{
						putchar(',');
						putchar(' ');
					}
				}
				++number3;
			}
			++number2;
		}
		++number1;
	}
	putchar('\n');

	return (0);
}


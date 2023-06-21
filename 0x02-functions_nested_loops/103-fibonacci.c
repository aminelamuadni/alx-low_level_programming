#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long num1 = 0, num2 = 2, next;
	unsigned long sum;

	while (1)
	{
		next = num1 + num2;

		if (next > 4000000)
			break;

		if ((next % 2) == 0)
			sum += next;

		num1 = num2;
		num2 = next;
	}
	printf("%lu\n", sum);

	return (0);
}


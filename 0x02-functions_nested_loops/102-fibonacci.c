#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long num1 = 0, num2 = 1, next;
	int count;

	for (count = 0; count < 50; ++count)
	{
		next = num1 + num2;
		printf("%lu", next);

		num1 = num2;
		num2 = next;

		if (count == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}


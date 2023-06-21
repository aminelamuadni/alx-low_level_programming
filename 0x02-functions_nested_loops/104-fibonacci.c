#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long long num1 = 1, num2 = 2, next;

	printf("%llu, %llu, ", num1, num2);

	for (count = 2; count < 98; count++)
	{
		next = num1 + num2;
		printf("%llu", next);

		if (count != 97)
			printf(", ");

		num1 = num2;
		num2 = next;
	}

	printf("\n");
	return 0;
}


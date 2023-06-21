#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned int a = 1, b = 2, next;

	printf("%d, %d, ", a, b);

	for (count = 2; count < 98; count++)
	{
		next = a + b;
		printf("%u", next);

		if (count != 97)
			printf(", ");

		a = b;
		b = next;
	}

	printf("\n");
	return 0;
}


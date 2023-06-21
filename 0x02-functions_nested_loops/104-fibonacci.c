#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned int a = 1, b = 2, temp;
	int count;

	printf("%u, %u", a, b);

	for (count = 3; count <= 98; count++)
	{
		temp = a + b;
		printf(", %u", temp);

		a = b;
		b = temp;
	}

	printf("\n");

	return 0;
}


#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number = 0;

	while (number <= 9)
	{
		printf("%i", number);
		++number;
	}
	printf("\n");

	return (0);
}


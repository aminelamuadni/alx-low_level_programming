#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = 0;
	int n;

	srand(time(NULL));

	while (sum < 2772)
	{
		n = rand() % 94 + 33;
		sum += n;

		if (sum > 2772)
		{
			sum -= n;
			continue;
		}
		else
		{
			printf("%c", n);
		}
	}
	printf("\n");

	return (0);
}

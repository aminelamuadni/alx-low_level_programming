#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 * @num: The number to find the largest prime factor of
 *
 * Return: The largest prime factor of the number
 */

unsigned long largest_prime_factor(unsigned long num)
{
	unsigned long largest_factor = 2;

	while (num % 2 == 0)
	{
		num /= 2;
	}

	for (unsigned long i = 3; i <= sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			largest_factor = i;
			num /= i;
		}
	}

	if (num > 2)
		largest_factor = num;

	return largest_factor;
}

int main(void)
{
	unsigned long number = 612852475143;
	unsigned long largest_factor = largest_prime_factor(number);

	printf("%lu\n", largest_factor);

	return 0;
}


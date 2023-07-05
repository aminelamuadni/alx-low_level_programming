#include "main.h"

/**
 * helper_function - helper function for the square root calculation.
 * @n: the number to find the square root of
 * @i: the incrementing counter to check for square root
 *
 * Return: natural square root of a number, -1 if no natural square root
 */
int helper_function(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	else if (i * i == n)
	{
		return (i);
	}
	else
	{
		return (helper_function(n, i + 1));
	}
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the number to find the square root of
 *
 * Return: natural square root of a number, -1 if no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (helper_function(n, 1));
	}
}

#include "main.h"

/**
 * _abs - Computes the absolute value of an integer.
 * @n: The integer.
 *
 * Return: The absolute value of the integer.
 */
int _abs(int n)
{
	if (n < 0)
		n = (-1) * n;
	return (n);
}


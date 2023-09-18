#include <stdio.h>

/**
 * add - adds two integers.
 * @a: the first integer.
 * @b: the second integer.
 *
 * Return: the sum of a and b.
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtracts two integers.
 * @a: the first integer.
 * @b: the second integer.
 *
 * Return: the difference between a and b.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiplies two integers.
 * @a: the first integer.
 * @b: the second integer.
 *
 * Return: the product of a and b.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - divides two integers.
 * @a: the dividend.
 * @b: the divisor.
 *
 * Return: the quotient of a and b. If b is 0, returns 0.
 */
int div(int a, int b)
{
	if (b == 0)
		return (0);
	return (a / b);
}

/**
 * mod - calculates the modulus of two integers.
 * @a: the dividend.
 * @b: the divisor.
 *
 * Return: the remainder of a divided by b. If b is 0, returns 0.
 */
int mod(int a, int b)
{
	if (b == 0)
		return (0);
	return (a % b);
}

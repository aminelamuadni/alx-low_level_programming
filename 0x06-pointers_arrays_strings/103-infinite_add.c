#include "main.h"
#include <stdio.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result, 0 if result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, sum, max_length, carry = 0;
	int digit1, digit2;

	while (*(n1 + len1) != '\0')
		len1++;
	while (*(n2 + len2) != '\0')
		len2++;

	if (len1 >= len2)
		max_length = len1;
	else
		max_length = len2;

	if (size_r <= max_length + 1)
		return (0);

	r[max_length + 1] = '\0';
	len1--, len2--, size_r--;
	digit1 = *(n1 + len1) - 48, digit2 = *(n2 + len2) - 48;

	while (max_length >= 0)
	{
		sum = digit1 + digit2 + carry;
		if (sum >= 10)
			carry = sum / 10;
		else
			carry = 0;

		if (sum > 0)
			*(r + max_length) = (sum % 10) + 48;
		else
			*(r + max_length) = '0';

		if (len1 > 0)
			len1--, digit1 = *(n1 + len1) - 48;
		else
			digit1 = 0;

		if (len2 > 0)
			len2--, digit2 = *(n2 + len2) - 48;
		else
			digit2 = 0;

		max_length--, size_r--;
	}

	if (*r == '0')
		return (r + 1);
	else
		return (r);
}

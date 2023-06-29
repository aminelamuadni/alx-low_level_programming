#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first input string
 * @n2: second input string
 * @r: buffer that the function will use to store the result
 * @size_r: buffer size
 *
 * Return: pointer to the result.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, op, bigger, i, j, carry = 0;

	while (*(n1 + len1) != '\0')
		len1++;
	while (*(n2 + len2) != '\0')
		len2++;
	if (len1 >= len2)
		bigger = len1;
	else
		bigger = len2;
	if (size_r <= bigger + 1)
		return (0);
	r[bigger + 1] = '\0';
	len1--, len2--, size_r--;
	i = *(n1 + len1) - 48, j = *(n2 + len2) - 48;
	while (bigger >= 0)
	{
		op = i + j + carry;
		if (op >= 10)
			carry = op / 10;
		else
			carry = 0;
		if (op > 0)
			*(r + bigger) = (op % 10) + 48;
		else
			*(r + bigger) = '0';
		if (len1 > 0)
			len1--, i = *(n1 + len1) - 48;
		else
			i = 0;
		if (len2 > 0)
			len2--, j = *(n2 + len2) - 48;
		else
			j = 0;
		bigger--, size_r--;
	}
	if (*(r) == '0')
		return (r + 1);
	else
		return (r);
}

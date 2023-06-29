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
	int i, j, k, l, m, n;
	int carry = 0;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;
	if (i > size_r || j > size_r)
		return (0);
	i--;
	j--;
	l = 0;
	for (k = 0; k < size_r - 1; k++, i--, j--, l++)
	{
		m = (i >= 0) ? n1[i] - '0' : 0;
		n = (j >= 0) ? n2[j] - '0' : 0;
		if ((m + n + carry) / 10 != 0)
			r[l] = (m + n + carry) % 10 + '0', carry = 1;
		else
			r[l] = (m + n + carry) + '0', carry = 0;
	}
	if (carry == 1)
		r[l] = 1 + '0', l++;
	if (l == size_r)
		return (0);
	r[l] = '\0';
	for (i = 0, j = l - 1; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}
	return (r);
}

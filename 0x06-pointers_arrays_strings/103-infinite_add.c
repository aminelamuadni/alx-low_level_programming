#include "main.h"

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
	int i, j, k, l, m, n;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;
	if (i > j)
		l = i;
	else
		l = j;
	if (size_r <= l + 1)
		return (0);
	m = 0;
	for (k = 0; k <= l; k++)
	{
		n = m;
		if (i > 0)
			n += n1[--i] - '0';
		if (j > 0)
			n += n2[--j] - '0';
		if (n > 9)
		{
			m = 1;
			r[k] = (n % 10) + '0';
		}
		else
		{
			m = 0;
			r[k] = n + '0';
		}
	}
	if (m == 1)
		r[l] = '1';
	else
		l--;
	for (k = 0; k <= l / 2; k++)
	{
		m = r[k];
		r[k] = r[l - k];
		r[l - k] = m;
	}
	r[l + 1] = '\0';
	return (r);
}

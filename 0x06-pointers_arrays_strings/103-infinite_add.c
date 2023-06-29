#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first string number
 * @n2: second string number
 * @r: buffer that the function will use to store the result
 * @size_r: buffer size
 * Return: pointer to result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, bigger, op, ad = 0;

	len1 = 0;
	while (n1[len1] != '\0')
		len1++;
	len2 = 0;
	while (n2[len2] != '\0')
		len2++;

	bigger = (len1 >= len2) ? len1 : len2;

	if (size_r <= (bigger + 1))
		return (0);

	r[bigger + 1] = '\0';
	len1--;
	len2--;

	while (bigger >= 0)
	{
		op = ad;
		if (len1 >= 0)
			op += n1[len1--] - '0';
		if (len2 >= 0)
			op += n2[len2--] - '0';

		if (op >= 10)
		{
			ad = 1;
			op -= 10;
		}
		else
		{
			ad = 0;
		}

		r[bigger--] = (op + '0');
	}

	if (r[0] == '0')
		return (r + 1);

	return (r);
}

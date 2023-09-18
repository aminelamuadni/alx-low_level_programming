#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: the number contained in the string
 */
int _atoi(char *s)
{
	int i, d, n = 0, len = 0, f = 0, sign = 1;

	while (s[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			d = s[i] - '0';
			if (sign < 0)
			{
				d *= -1;
			}
			n = n * 10 + d;
			f = 1;
		}
		else if (f == 1)
		{
			break;
		}
	}
	return (n);
}

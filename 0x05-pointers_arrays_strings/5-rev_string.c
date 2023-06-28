#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0;
	int i;
	char temp;

	/* Determine the length of the string */
	while (s[length] != '\0')
	{
		length++;
	}

	/* Swap characters */
	for (i = 0; i < length / 2; i++)
	{
		temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
	}
}

#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i, len = 0, n;

	/* Calculate string length */
	while (str[len] != '\0')
		len++;

	/* Calculate starting index for printing */
	if (len % 2 == 0)
		n = len / 2;
	else
		n = (len + 1) / 2;

	/* Print from 'n' to the end of the string */
	for (i = n; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

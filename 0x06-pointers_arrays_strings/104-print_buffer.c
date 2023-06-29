#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of the buffer
 *
 * Return: nothing
 */
void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		for (j = 0; j < 10; j++)
		{
			if (j % 2 == 0 && j != 0)
				printf(" ");
			if (j + i < size)
				printf("%02x", b[j + i]);
			else
				printf("  ");
		}
		printf(" ");
		for (j = 0; j < 10; j++)
		{
			if (j + i < size && b[j + i] >= 32 && b[j + i] <= 126)
				printf("%c", b[j + i]);
			else if (j + i < size)
				printf(".");
		}
		printf("\n");
	}
	if (size <= 0)
		printf("\n");
}

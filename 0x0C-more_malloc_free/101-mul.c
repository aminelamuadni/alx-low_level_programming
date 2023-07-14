#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 0 if string contains non-digits, 1 otherwise
 */
int is_digit(char *s)
{
	int i, length = strlen(s);

	for (i = 0; i < length; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * print_error - prints error message and exits program
 */
void print_error(void)
{
	int i;
	char *error = "Error\n";

	for (i = 0; error[i]; i++)
	{
		_putchar(error[i]);
	}

	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	long num1, num2, product;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	product = num1 * num2;

	printf("%ld\n", product);

	return (0);
}

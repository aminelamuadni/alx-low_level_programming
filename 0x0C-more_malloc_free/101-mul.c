#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error - prints an error message and exits with status 98
 */
void error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit - checks if a string only contains digits
 * @s: the string to check
 *
 * Return: 1 if the string only contains digits, otherwise 0
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * mul - multiplies two numbers
 * @num1: the first number
 * @num2: the second number
 *
 * Return: the result of the multiplication
 */
char *mul(char *num1, char *num2)
{
	/* implement multiplication of num1 and num2 */
}

/**
 * main - entry point
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 if the program completed successfully, otherwise a status number
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3)
		error();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		error();

	result = mul(num1, num2);

	printf("%s\n", result);
	free(result);

	return (0);
}

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
	printf("Error\n");
	exit(98);
}

/**
 * multiply - performs multiplication of two positive numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: pointer to the result of multiplication
 */
char *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_res = len1 + len2;
	int i, j, k, carry;
	char *result = malloc((len_res + 1) * sizeof(char));

	if (result == NULL)
		print_error();

	for (i = 0; i < len_res; i++)
		result[i] = '0';
	result[len_res] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1, k = len_res - (len1 - i); j >= 0; j--, k--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0') + (result[k] - '0') + carry;

			carry = product / 10;
			result[k] = (product % 10) + '0';
		}
		result[k] += carry;
	}

	return (result);
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
	char *num1, *num2, *product;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	num1 = argv[1];
	num2 = argv[2];
	product = multiply(num1, num2);

	printf("%s\n", product);

	free(product);
	return (0);
}

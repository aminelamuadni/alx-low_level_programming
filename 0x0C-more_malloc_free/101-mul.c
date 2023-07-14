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
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
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
	char *result = calloc(len_res + 1, sizeof(char));

	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

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
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];
	product = multiply(num1, num2);

	while (*product == '0' && *(product + 1) != '\0')
		product++;

	printf("%s\n", product);

	free(product);
	return (0);
}

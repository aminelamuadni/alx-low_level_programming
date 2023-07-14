#include "main.h"

/**
 * print_error - Prints "Error" followed by a new line to stderr
 *
 * Return: void
 */
void print_error(void)
{
	char *error = "Error\n";

	while (*error)
		_putchar(*error++);

	exit(98);
}

/**
 * multiply - Multiplies two positive numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The result of the multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
	int len1, len2, len, i, j, prod, carry;
	int *result;
	char *mul;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;
	result = calloc(len, sizeof(int));
	if (!result)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			result[i + j + 1] = prod % 10;
			carry = prod / 10;
		}
		result[i] += carry;
	}

	if (result[0] == 0)
	{
		mul = malloc(len);
		if (!mul)
			print_error();

		for (i = 1, j = 0; i <= len; i++, j++)
			mul[j] = result[i] + '0';
		mul[j] = '\0';
	}
	else
	{
		mul = malloc(len + 1);
		if (!mul)
			print_error();

		for (i = 0, j = 0; i < len; i++, j++)
			mul[j] = result[i] + '0';
		mul[j] = '\0';
	}

	free(result);
	return (mul);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	if (!_isdigit(num1) || !_isdigit(num2))
		print_error();

	result = multiply(num1, num2);
	_print(result);
	free(result);

	return (0);
}

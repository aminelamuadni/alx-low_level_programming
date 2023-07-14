#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * error - print error message and exit program
 */
void error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit - check if a string is a number
 * @str: string to check
 * Return: 0 if str is a number, 1 otherwise
 */
int is_digit(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i++) > '9')
			return (0);
	}
	return (1);
}

/**
 * multiply - multiply two numbers and print the result
 * @n1: first number
 * @n2: second number
 */
void multiply(char *n1, char *n2)
{
	int len1, len2, tot, i, j;
	int *result;

	len1 = strlen(n1);
	len2 = strlen(n2);
	tot = len1 + len2;

	result = calloc(tot, sizeof(int));
	if (!result)
		error();

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += ((n1[i] - '0') * (n2[j] - '0'));
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}
	for (i = *result; !i && tot > 1; tot--)
		result++;
	for (i = 0; i < tot; i++)
		printf("%d", result[i]);
	printf("\n");
}

/**
 * main - multiply two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		error();
	multiply(argv[1], argv[2]);
	return (0);
}

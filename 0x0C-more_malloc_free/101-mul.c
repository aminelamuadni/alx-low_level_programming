#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * check_zero - checks if either of the numbers is zero
 * @argv: command line arguments
 *
 * Return: void
 */
void check_zero(char *argv[])
{
	int i, n1 = 1, n2 = 1;

	for (i = 0; argv[1][i]; i++)
		if (argv[1][i] != '0')
		{
			n1 = 0;
			break;
		}

	for (i = 0; argv[2][i]; i++)
		if (argv[2][i] != '0')
		{
			n2 = 0;
			break;
		}

	if (n1 == 1 || n2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * initialize_array - initializes an array with '0'
 * @ar: the array to initialize
 * @lar: the length of the array
 *
 * Return: the initialized array
 */
char *initialize_array(char *ar, int lar)
{
	int i = 0;

	for (i = 0; i < lar; i++)
		ar[i] = '0';
	ar[lar] = '\0';
	return (ar);
}

/**
 * check_num - checks if the given argument is a valid number
 * @argv: command line arguments
 * @n: index of the argument to check
 *
 * Return: the length of the number
 */
int check_num(char *argv[], int n)
{
	int length;

	for (length = 0; argv[n][length]; length++)
		if (!isdigit(argv[n][length]))
		{
			printf("Error\n");
			exit(98);
		}

	return (length);
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
	int len1, len2, len_out, sum, addl, i, j, k, count;
	char *out;

	if (argc != 3)
		printf("Error\n"), exit(98);
	len1 = check_num(argv, 1), len2 = check_num(argv, 2);
	check_zero(argv), len_out = len1 + len2, out = malloc(len_out + 1);
	if (out == NULL)
		printf("Error\n"), exit(98);
	out = initialize_array(out, len_out);
	k = len_out - 1, i = len1 - 1, j = len2 - 1, count = carry = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (carry > 0)
			{
				sum = (out[k] - '0') + carry;
				if (sum > 9)
					out[k - 1] = (sum / 10) + '0';
				out[k] = (sum % 10) + '0';
			}
			i = len1 - 1, j--, carry = 0, count++, k = len_out - (1 + count);
		}
		if (j < 0)
		{
			if (out[0] != '0')
				break;
			len_out--;
			free(out), out = malloc(len_out + 1), out = initialize_array(out, len_out);
			k = len_out - 1, i = len1 - 1, j = len2 - 1, count = carry = 0;
		}
		if (j >= 0)
		{
			sum = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (out[k] - '0') + carry;
			carry = sum / 10, out[k] = (sum % 10) + '0';
		}
	}
	printf("%s\n", out);
	return (0);
}

#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to evaluate
 * Return: Length of string
 */

int _strlen_recursion(char *s)
{
	if (*s)
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}

/**
 * check_palindrome - checks if string is a palindrome
 * @s: string to check
 * @len: length of string
 * Return: 1 if palindrome, 0 if not
 */

int check_palindrome(char *s, int len)
{
	if (len <= 1)
	{
		return (1);
	}
	else if (*s != *(s + len - 1))
	{
		return (0);
	}
	else
	{
		return (check_palindrome(s + 1, len - 2));
	}
}

/**
 * is_palindrome - states if string is a palindrome
 * @s: string to check
 * Return: 1 if palindrome, 0 if not
 */

int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (check_palindrome(s, len));
}

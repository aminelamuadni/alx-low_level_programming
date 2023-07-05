#include "main.h"

/**
 * check_match - helper function to handle wildcard matches
 * @s1: string to compare
 * @s2: string to compare with possible wildcard(s)
 * @wild: flag to track if wildcard has been encountered
 *
 * Return: 1 if match, 0 if not
 */
int check_match(char *s1, char *s2, char *wild)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == '\0' && *s2 == '*' && wild == 0)
		return (check_match(s1, s2 + 1, s2));

	if (*s1 == *s2)
		return (check_match(s1 + 1, s2 + 1, 0));

	if (*s1 != *s2 && *s2 == '*')
		return (check_match(s1, s2 + 1, s2));

	if (wild)
		return (check_match(s1 + 1, wild, wild));

	return (0);
}

/**
 * wildcmp - compares two strings considering wildcard
 * @s1: string to compare
 * @s2: string to compare with possible wildcard(s)
 *
 * Return: 1 if match, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	return (check_match(s1, s2, 0));
}

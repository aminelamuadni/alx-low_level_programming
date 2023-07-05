#include "main.h"

/**
 * wildcard_match - helper function to handle wildcard matches
 * @s1: string to compare
 * @s2: string to compare with possible wildcard(s)
 * @wildcard: flag to track if wildcard has been encountered
 * 
 * Return: 1 if match, 0 if not
 */
int wildcard_match(char *s1, char *s2, int wildcard)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
		return (wildcard_match(s1, s2 + 1, 1));

	if (*s1 == '\0' && *s2 != '\0' && wildcard == 0)
		return (0);

	if (*s1 == '\0' && *s2 != '\0' && *s2 != '*' && wildcard == 1)
		return (0);

	if (*s1 == *s2)
		return (wildcard_match(s1 + 1, s2 + 1, 0));

	if (*s1 != *s2 && wildcard == 1)
		return (wildcard_match(s1 + 1, s2, 1));

	if (*s1 != *s2 && wildcard == 0)
		return (0);

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
	return (wildcard_match(s1, s2, 0));
}

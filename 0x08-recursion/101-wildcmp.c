#include "main.h"

/**
 * wildcmp - function that compares two strings
 * @s1: string to compare
 * @s2: string to compare with possible wildcard(s)
 *
 * Return: 1 if considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0') /* if end of both strings, they match */
        return (1);

    if (*s1 == *s2) /* if chars match, increment both strings */
        return (wildcmp(s1 + 1, s2 + 1));

    if (*s1 != *s2 && *s2 == '*') /* if wildcard, try both advancing and not advancing s1 */
        return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));

    return (0); /* if no match and no wildcard, return 0 */
}

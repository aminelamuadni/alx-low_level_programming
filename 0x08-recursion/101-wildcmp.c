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
    /* if the end of both strings is reached */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    /* comparing each character of both strings */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));
    /* when '*' is found in s2 */
    if (*s2 == '*')
    {
        /* move the s2 pointer until it points to a character other than '*' */
        s2 = s2 + 1;
        if (*s2 == '\0')
            return (1);
        /* call the function recursively for every match after '*' */
        while (*s1 != '\0')
        {
            if (wildcmp(s1, s2))
                return (1);
            s1++;
        }
    }
    return (0);
}

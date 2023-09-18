#include "main.h"

/**
 * _strcpy - Copies string from src to dest
 * @dest: Destination for copied string
 * @src: Source of string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

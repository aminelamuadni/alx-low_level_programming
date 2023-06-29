/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;

	/* Find the end of the destination string */
	while (dest[i])
		i++;

	/* Append the source string to the destination string */
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	/* Null-terminate the destination string */
	dest[i + j] = '\0';

	return dest;
}

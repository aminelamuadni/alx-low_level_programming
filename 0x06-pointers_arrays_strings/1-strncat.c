/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string
 * @src: The source string
 * @n: The number of bytes to use from src
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of the destination string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Append the first n characters of the source string to the destination string */
	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[i + j] = src[j];

	/* If src has less than n characters, null-terminate dest */
	if (j < n)
		dest[i + j] = '\0';

	return (dest);
}

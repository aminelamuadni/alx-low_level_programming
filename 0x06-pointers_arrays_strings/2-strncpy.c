/**
 * _strncpy - Copies a string
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes to be copied from source
 *
 * Return: A pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy the first n characters from source to destination */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* For the remaining bytes, replace with null bytes */
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}

	return dest;
}

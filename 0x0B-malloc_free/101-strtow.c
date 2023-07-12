#include "main.h"
#include <stdlib.h>

/**
 * count_words - count the number of words in a string
 * @str: the string to check
 *
 * Return: number of words in the string
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * strtow - split a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of words
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, l, count;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	count = count_words(str);
	if (count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0, k = 0; i < count; i++)
	{
		while (str[k] == ' ')
			k++;
		for (j = k; str[j] != ' ' && str[j] != '\0'; j++)
			;
		words[i] = malloc(j - k + 1);
		if (words[i] == NULL)
		{
			for (; i >= 0; i--)
				free(words[i]);
			free(words);
			return (NULL);
		}
		for (l = 0; k < j; k++, l++)
			words[i][l] = str[k];
		words[i][l] = '\0';
	}
	words[i] = NULL;

	return (words);
}

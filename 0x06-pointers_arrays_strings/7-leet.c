/**
 * leet - encodes a string into 1337
 * @s: input string.
 *
 * Return: the pointer to dest.
 */
char *leet(char *s)
{
	int i = 0, j;
	char letters[] = "aAeEoOtTlL";
	char leet_letters[] = "4433007711";

	while (s[i] != '\0')
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = leet_letters[j];
				break;
			}
		}
		i++;
	}

	return (s);
}

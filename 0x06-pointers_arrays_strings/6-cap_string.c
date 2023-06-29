/**
 * string_toupper - Changes all lowercase letters of a string to uppercase
 * @s: The string to change
 *
 * Return: A pointer to the changed string
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			if (i == 0)
			{
				s[i] -= 32;
			}

			if (s[i - 1] == 32 || s[i - 1] == 9 || s[i - 1] == 10 ||
				s[i - 1] == 44 || s[i - 1] == 59 || s[i - 1] == 46 ||
				s[i - 1] == 33 || s[i - 1] == 63 || s[i - 1] == 34 ||
				s[i - 1] == 40 || s[i - 1] == 41 || s[i - 1] == 123 ||
				s[i - 1] == 124)
			{
				s[i] -= 32;
			}
		}

		i++;
	}

	return (s);
}

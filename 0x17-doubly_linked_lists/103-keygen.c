#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * generate_char - Generates a character for the password based on method.
 * @username: The user's name string.
 * @method: Method number to use for generating char.
 *
 * Return: The generated character.
 */
char generate_char(char *username, int method)
{
	unsigned int calc = 0, i;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	switch (method)
	{
		case 1:
			return (l[(strlen(username) ^ 59) & 63]);
		case 2:
			for (i = 0; i < strlen(username); i++)
				calc += username[i];
			return (l[(calc ^ 79) & 63]);
		case 3:
			calc = 1;
			for (i = 0; i < strlen(username); i++)
				calc *= username[i];
			return (l[(calc ^ 85) & 63]);
		case 4:
			for (i = 0, calc = username[0]; i < strlen(username); i++)
				if ((char)calc <= username[i])
					calc = username[i];
			srand(calc ^ 14);
			return (l[rand() & 63]);
		case 5:
			for (i = 0; i < strlen(username); i++)
				calc += username[i] * username[i];
			return (l[(calc ^ 239) & 63]);
		default:
			for (i = 0, calc = 0; (char)i < username[0]; i++)
				calc = rand();
			return (l[(calc ^ 229) & 63]);
	}
}

/**
 * main - Main function to generate password based on username.
 * @argc: The argument count.
 * @argv: The argument values.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	int i;
	char password[7];

	if (argc != 2)
	{
		return (1);
	}

	for (i = 0; i < 6; i++)
		password[i] = generate_char(argv[1], i + 1);

	password[6] = '\0';
	printf("%s\n", password);
	return (0);
}

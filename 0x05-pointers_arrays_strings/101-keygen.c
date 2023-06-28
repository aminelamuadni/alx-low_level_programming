#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10  /* Adjust this to match the requirement */

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	char password[PASSWORD_LENGTH + 1];

	srand(time(0));

	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		/* Generate a random printable ASCII character */
		password[i] = rand() % 94 + 33;
	}
	password[i] = '\0';
	printf("%s\n", password);

	return (0);
}

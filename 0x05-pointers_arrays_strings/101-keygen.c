#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PASSWORD_LENGTH 10  /* Adjust this to match the requirement */
#define CHECKSUM 1275 /* Example checksum value */

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, sum = 0;
	char password[PASSWORD_LENGTH + 1];

	srand(time(0));

	for (i = 0; i < PASSWORD_LENGTH - 1; i++)
	{
		/* Generate a random printable ASCII character */
		password[i] = rand() % 94 + 33;
		sum += password[i];
	}

	/* Make sure the sum of all characters equals the required checksum */
	password[i] = CHECKSUM - sum;
	password[i + 1] = '\0';

	printf("%s\n", password);

	return (0);
}

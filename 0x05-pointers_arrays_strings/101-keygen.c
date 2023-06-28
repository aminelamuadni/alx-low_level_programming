#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    srand(time(0));
    int password_length = 10; /* you can adjust this to match the requirement */
    char password[password_length + 1];
    int i;

    for (i = 0; i < password_length; i++)
    {
        /* Generate a random printable ASCII character */
        password[i] = rand() % 94 + 33;
    }
    password[i] = '\0';
    printf("%s\n", password);

    return (0);
}

#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char text[] = "_putchar";
	int i;

	for (i = 0; i < 8; ++i)
		_putchar(text[i]);
	_putchar('\n');

	return (0);
}


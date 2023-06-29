#include"main.h"

/**
 * print_number - print an integer.
 * @n: integer to be printed.
 *
 * Return: Nothing.
 */
void print_number(int n)
{
    unsigned int m, d, count;

    if (n < 0)
    {
        _putchar('-');
        m = n * -1;
    }
    else
    {
        m = n;
    }

    d = m;
    count = 1;

    while (d > 9)
    {
        d /= 10;
        count *= 10;
    }

    while (count >= 1)
    {
        _putchar(((m / count) % 10) + '0');
        count /= 10;
    }
}

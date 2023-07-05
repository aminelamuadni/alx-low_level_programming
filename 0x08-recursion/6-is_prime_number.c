#include "main.h"

/**
 * check_prime - checks if a number is prime
 * @n: the number to check
 * @i: the divisor
 *
 * Return: 1 if the number is a prime, 0 otherwise
 */
int check_prime(int n, int i)
{
    if (n <= 1)
    {
        return (0);
    }
    else if (n % i == 0)
    {
        return (0);
    }
    else if (i * i > n)
    {
        return (1);
    }
    else
    {
        return (check_prime(n, i + 1));
    }
}

/**
 * is_prime_number - checks if a number is a prime number
 * @n: the number to check
 *
 * Return: 1 if the input integer is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
    return (check_prime(n, 2));
}

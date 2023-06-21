#include"main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    unsigned int num1 = 1, num2 = 2, next;
    int count;

    printf("%u, %u", num1, num2);

    for (count = 3; count <= 98; count++)
    {
        next = num1 + num2;
        printf(", %u", next);
        num1 = num2;
        num2 = next;
    }

    printf("\n");

    return 0;
}


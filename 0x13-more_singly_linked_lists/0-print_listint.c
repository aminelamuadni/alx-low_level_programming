#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes = 0;
	int n, copy;
	char c;

	while (h)
	{
		n = h->n;
		if (n < 0)
		{
			_putchar('-');
			n = -n;
		}
		copy = n;
		while (copy /= 10)
			n = n / 10;
		while (n > 0)
		{
			c = (n % 10) + '0';
			_putchar(c);
			n = n / 10;
		}
		_putchar('\n');
		h = h->next;
		nodes++;
	}

	return (nodes);
}

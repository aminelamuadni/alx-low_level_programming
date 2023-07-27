#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to the start of the list
 *
 * Return: number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	const list_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}

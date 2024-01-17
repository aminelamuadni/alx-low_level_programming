#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *			 the Jump search algorithm.
 * @list: Pointer to the head of the list.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located, or NULL if not
 * present or list is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_step = sqrt(size);
	size_t i = 0;
	listint_t *node = list, *prev = list;

	if (!list)
		return (NULL);

	while (node->next != NULL && node->n < value)
	{
		size_t j;

		prev = node;
		for (j = 0; j < jump_step && node->next != NULL; j++)
			node = node->next;

		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, node->index);
	for (i = prev->index; i <= node->index && prev != NULL; i++)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}

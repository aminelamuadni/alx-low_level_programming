#include "search_algos.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 * Return: Pointer on the first node where value is located, or NULL if not
 * present or list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list, *express = NULL;

	if (!list)
		return (NULL);

	while (node->express && node->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->express->index,
			node->express->n);
		node = node->express;
	}

	if (node->express)
	{
		express = node->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index,
			express->n);
	}
	else
	{
		express = node;
		while (express->next)
			express = express->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", node->index,
		express->index);

	while (node && node->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}

	return (NULL);
}

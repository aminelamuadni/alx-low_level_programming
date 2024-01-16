#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 *			   using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if not found or array
 * is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t prev = 0, i;

	if (array == NULL)
		return (-1);

	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += jump;
	}

	i = prev < size ? prev - jump : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", i, prev);
	i = i < size ? i : size - 1;

	for (; i < size && i <= prev; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] >= value)
			break;
	}

	if (i < size && array[i] == value)
		return ((int)i);

	return (-1);
}

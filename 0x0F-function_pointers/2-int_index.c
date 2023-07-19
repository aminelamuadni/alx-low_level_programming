#include "function_pointers.h"

/**
 * int_index - Searches for an integer in array using a comparison function
 * @array: The array to search
 * @size: The size of the array
 * @cmp: The comparison function to use (returns 0 if match)
 *
 * Return: The index of the first match, or -1 if no match or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		{
			return (i);
		}
	}

	return (-1);
}

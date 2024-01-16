#include "search_algos.h"
#include <stdio.h>

/**
 * exponential_search - Searches for a value using the Exponential search
 * algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: The first index where value is located, or -1 if not present or
 * array is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t low;
	size_t high;

	if (!array)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	return (binary_search_print(array, low, high, value));
}

/**
 * binary_search_print - Prints an array and performs a binary search.
 * @array: Pointer to the first element of the array to search in.
 * @left: The left index of the subarray to search.
 * @right: The right index of the subarray to search.
 * @value: The value to search for.
 * Return: The first index where value is located, or -1.
 */
int binary_search_print(int *array, size_t left, size_t right, int value)
{
	size_t mid;
	size_t i;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");
		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return ((int)mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

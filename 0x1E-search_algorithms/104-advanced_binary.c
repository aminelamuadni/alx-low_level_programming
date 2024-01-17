#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the array being searched.
 * @array: Pointer to the first element of the array.
 * @left: The left index of the subarray.
 * @right: The right index of the subarray.
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Performs a recursive binary search.
 * @array: Pointer to the first element of the array.
 * @left: The left index of the subarray.
 * @right: The right index of the subarray.
 * @value: The value to search for.
 * Return: The first index where value is located, or -1.
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);

	print_array(array, left, right);
	mid = left + (right - left) / 2;

	if ((mid == 0 || value > array[mid - 1]) && array[mid] == value)
		return (mid);
	else if (array[mid] < value)
		return binary_search_recursive(array, mid + 1, right, value);
	else
		return binary_search_recursive(array, left, mid, value);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *				   using an advanced binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: The first index where value is located, or -1 if not present or array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return binary_search_recursive(array, 0, size - 1, value);
}

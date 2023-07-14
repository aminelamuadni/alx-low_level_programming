#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @nmemb: The number of elements to allocate
 * @size: The size of each element
 *
 * Return: If nmemb = 0, size = 0, or the function fails - NULL.
 *         Otherwise - a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(nmemb * size);

	if (mem == NULL)
		return (NULL);

	memset(mem, 0, nmemb * size);

	return (mem);
}

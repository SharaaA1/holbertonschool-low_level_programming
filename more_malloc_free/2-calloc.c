#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc, and sets it to zero
 * @nmemb: number of elements in the array
 * @size: size in bytes of each element
 *
 * Return: pointer to the allocated memory, or NULL if nmemb or size is 0
 * or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i, total_bytes;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_bytes = nmemb * size;
	ptr = malloc(total_bytes);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total_bytes; i++)
		ptr[i] = 0;

	return (ptr);
}

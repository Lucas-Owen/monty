#include "utils.h"

/**
 * my_malloc - Wrapper around malloc to print to stderr if it fails
 * @size: Allocation size
 * Return: void*
 */
void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

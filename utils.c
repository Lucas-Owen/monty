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

/**
 * string_is_int - Checks if a string is an integer
 * @str: The string
 * Return: true if it is an integer, false otherwise
 */
bool string_is_int(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

/**
 * my_strdup - Duplicates a string and returns a pointer to the heap
 * containing the duplicate
 * @src: The string to duplicate
 * Return: char *
 */
char *my_strdup(char *src)
{
	char *res = my_malloc(strlen(src) + 1);

	strcpy(res, src);
	return (res);
}

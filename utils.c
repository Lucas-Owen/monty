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


/**
 * my_fgets - gets a line of input from the specified file descriptor
 * @buf: Buffer to store input, ensure it has enough size to fit input
 * @size: Size to read
 * @fd: File descriptor to read from
 * Return: The number of bytes read, or -1 on error
 */
int my_fgets(char *buf, size_t size, int fd)
{
	static char buffer[BUFSIZ];
	static int start, end;
	int stop, res;

	if (buf == NULL)
		return (-1);

	buf[0] = '\0';
	if (start >= end)
	{
		buffer[0] = '\0';
		res = read(fd, buffer, size);
		if (res <= 0)
			return (-1);
		start = 0;
		end = res;
	}
	for (stop = start; buffer[stop] && buffer[stop] != '\n'; ++stop)
		;
	res = stop - start;
	strncat(buf, buffer + start, res);
	start = stop + 1;
	return (res);
}


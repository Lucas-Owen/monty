#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "monty.h"
#include "externs.h"

/**
 * main - An interpreter for the monty bytecode
 * @argc: Argcount
 * @argv: Args
 * Return: (0) Success, (1) Failure
 */
int main(int argc, char **argv)
{
	char buffer[BUFSIZ];
	size_t line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globals.fd = open(argv[1], O_RDONLY);
	if (globals.fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (my_fgets(buffer, BUFSIZ - 1, globals.fd) >= 0)
	{
		++line_number;
		eval_input(buffer, line_number);
		if (globals.current_instruction.f)
		{
			globals.current_instruction.f(&globals.operands, line_number);
			free(globals.current_instruction.opcode);
			globals.current_instruction.f = NULL;
			globals.current_instruction.opcode = NULL;
		}
	}
	exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	instruction_t instruction = {NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globals.fp = fopen(argv[1], "r");
	if (!globals.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFSIZ - 1, globals.fp))
	{
		++line_number;
		eval_input(buffer, line_number, &instruction);
		if (instruction.f)
		{
			instruction.f(&globals.operands, line_number);
			free(instruction.opcode);
			instruction.f = NULL;
		}
	}
	exit(EXIT_SUCCESS);
}

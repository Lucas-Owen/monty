#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fp;
	extern stack_t *operands;
	char buffer[BUFSIZ];
	size_t line_number = 0;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFSIZ - 1, fp))
	{
		++line_number;
		eval_input(buffer, line_number, &instruction);
		if (instruction.f)
			{
				instruction.f(&operands, line_number);
				free(instruction.opcode);
				instruction.f = NULL;
			}
	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}

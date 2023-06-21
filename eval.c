#include "monty.h"

stack_t *operands = NULL;

/**
 * validate_opcode - Checks if an opcode is valid, returns the type of function
 * as in macros I_PUSH, I_PALL etc
 * @opcode: The opcode
 * @line_number: Line number
 * Return: int
 */
int validate_opcode(char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		return (I_PUSH);
	if (strcmp(opcode, "pall") == 0)
		return (I_PALL);
	if (strcmp(opcode, "pint") == 0)
		return (I_PINT);
	if (strcmp(opcode, "pop") == 0)
		return (I_POP);
	if (strcmp(opcode, "swap") == 0)
		return (I_SWAP);
	if (strcmp(opcode, "add") == 0)
		return (I_ADD);
	if (strcmp(opcode, "nop") == 0)
		return (I_NOP);
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * eval_input - parses a line of input and evaluates the instruction obtained
 * @buffer: Line of input
 * @line_number: Line number
 * @instruction: Pointer to store instruction
 * Return: void
 */
void eval_input(char *buffer, unsigned int line_number,
	instruction_t *instruction)
{
	int func;
	char *token = strtok(buffer, " \n");

	if (!token)
		return;
	func = validate_opcode(token, line_number);
	instruction->opcode = my_strdup(token);
	switch (func)
	{
		case I_PUSH:
				token = strtok(NULL, " \n");
				if (!token || !string_is_int(token))
				{
					free(instruction->opcode);
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				s_push(&operands, atoi(token));
				instruction->f = i_push;
				break;
		case I_PALL:
				instruction->f = i_pall;
				break;
		case I_PINT:
				instruction->f = i_pint;
				break;
		case I_POP:
				instruction->f = i_pop;
				break;
		case I_SWAP:
				instruction->f = i_swap;
				break;
		case I_ADD:
				instruction->f = i_add;
				break;
		case I_NOP:
				instruction->f = i_nop;
				break;
	}
}

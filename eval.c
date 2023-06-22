#include "monty.h"

global_vars_t globals = {-1, NULL};

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
	if (strcmp(opcode, "nop") == 0)
		return (I_NOP);
	if (strcmp(opcode, "add") == 0)
		return (I_ADD);
	if (strcmp(opcode, "sub") == 0)
		return (I_SUB);
	if (strcmp(opcode, "mul") == 0)
		return (I_MUL);
	if (strcmp(opcode, "div") == 0)
		return (I_DIV);
	if (strcmp(opcode, "mod") == 0)
		return (I_MOD);
	if (strcmp(opcode, "pchar") == 0)
		return (I_PCHAR);
	if (strcmp(opcode, "pstr") == 0)
		return (I_PSTR);
	if (strcmp(opcode, "rotl") == 0)
		return (I_ROTL);
	if (strcmp(opcode, "rotr") == 0)
		return (I_ROTR);
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
	const void (*funcs[])(stack_t **, unsigned int) = {i_push, i_pall, i_pop,
				i_pint, i_swap, i_nop,
				i_add, i_sub, i_mul, i_div, i_mod,
				i_pchar, i_pstr,
				i_rotl, i_rotr};
	int func;
	char *token = strtok(buffer, " \n");

	if (!token || token[0] == '#')
		return;
	func = validate_opcode(token, line_number);
	instruction->opcode = my_strdup(token);
	if (func == I_PUSH)
	{
		token = strtok(NULL, " \n");
		if (!token || !string_is_int(token))
		{
			free(instruction->opcode);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		s_push(&globals.operands, atoi(token));
	}
	instruction->f = funcs[func];
}

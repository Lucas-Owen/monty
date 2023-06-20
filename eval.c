#include "monty.h"

#define I_PUSH 0
#define I_PALL 1

stack_t *operands = NULL;

/**
 * arg_count - Checks if an opcode is valid, returns the type of function
 * as in macros I_PUSH, I_PALL etc
 * @opcode: The opcode
 * @line_number: Line number
 * Return: int
 */
int arg_count(char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		return (I_PUSH);
	if (strcmp(opcode, "pall") == 0)
		return (I_PALL);
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
	{
		instruction->f = NULL;
		return;
	}
	func = arg_count(token, line_number);
	instruction->opcode = my_malloc(strlen(token) + 1);
	strcpy(instruction->opcode, token);
	switch (func)
	{
		case I_PUSH: token = strtok(NULL, " ");
				if (!token || !isdigit(token[0]))
				{
					free(instruction->opcode);
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				s_push(&operands, atoi(token));
				instruction->f = i_push;
				break;
		case I_PALL: instruction->f = i_pall;
					break;
		
	}
}
/**
 * i_push - Pushes a value to the stack
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	return;
}
/**
 * i_pall - Prints all the values on the stack, starting from the top
 * @stack: The stack
 */
void i_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

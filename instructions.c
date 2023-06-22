#include "monty.h"


/**
 * i_pop - Pops a value to the stack
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_pop(stack_t **stack, unsigned int line_number)
{
	if (s_isEmpty(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	s_pop(stack);
}

/**
 * i_swap - Swap the top two elements of the stack
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_swap(stack_t **stack, unsigned int line_number)
{
	if (!s_swap(stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}



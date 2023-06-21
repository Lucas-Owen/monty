#include "monty.h"

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
 * i_pint - Pops a value to the stack
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_pint(stack_t **stack, unsigned int line_number)
{
	if (s_isEmpty(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", s_top(*stack));
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


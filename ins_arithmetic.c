#include "monty.h"

/**
 * i_add - Add the top two elements of the stack, pop the first element,
 * and store the result in the top element
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (s_isEmpty((*stack)) || s_isEmpty((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = s_top(*stack);
	s_pop(stack);
	(*stack)->n += result;
}

/**
 * i_sub - Subtract the top from the second element of the stack,
 pop the first element, and store the result in the top element
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (s_isEmpty((*stack)) || s_isEmpty((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = s_top(*stack);
	s_pop(stack);
	(*stack)->n -= result;
}

/**
 * i_mul - Multiply the top two elements of the stack,
 pop the first element, and store the result in the top element
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (s_isEmpty((*stack)) || s_isEmpty((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = s_top(*stack);
	s_pop(stack);
	(*stack)->n *= result;
}

/**
 * i_div - Subtract the top from the second element of the stack,
 pop the first element, and store the result in the top element
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (s_isEmpty((*stack)) || s_isEmpty((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = s_top(*stack);
	s_pop(stack);
	(*stack)->n /= result;
}

/**
 * i_mod - Subtract the top from the second element of the stack,
 pop the first element, and store the result in the top element
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (s_isEmpty((*stack)) || s_isEmpty((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = s_top(*stack);
	s_pop(stack);
	(*stack)->n %= result;
}

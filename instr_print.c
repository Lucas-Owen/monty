#include "monty.h"

/**
 * i_pall - Prints all the values on the stack, starting from the top
 * @stack: The stack
 * @line_number: Line number of the function call
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
 * i_pchar - Prints the top value as a character
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_pchar(stack_t **stack, unsigned int line_number)
{
	if (s_isEmpty(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isprint(s_top(*stack)))
	{
		fprintf(stderr,
			"L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", s_top(*stack));
}

/**
 * i_pstr - Prints all the values on the stack, starting from the top
 * prints values as characters
 * @stack: The stack
 * @line_number: Line number of the function call
 */
void i_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
		
	while (temp)
	{
		if (top(&temp) == 0)
			break;
		if (!isprint(s_top(*stack)))
		{
			fprintf(stderr,
				"L%d: can't pstr, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%d", top(&temp));
		temp = temp->next;
	}
	putchar('\n');
}

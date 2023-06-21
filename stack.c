#include "stack.h"

/*
 * s_push - performs a s_push operation on the stack
 * @stack: Pointer to the head of the stack
 * @n: Data to be inserted
 * Return: void
 */
void s_push(stack_t **stack, int n)
{
	stack_t *new;

	new = my_malloc(sizeof(stack_t));
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	(*stack)->prev = new;
	new->next = (*stack);
	*stack = new;
}

/*
 * s_pop - performs a s_pop operation on the stack
 * @stack: Pointer to the head of the stack
 * Return: void
 */
void s_pop(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/*
 * s_top - performs a s_top operation on the stack
 * @stack: Pointer to the head of the stack
 * Return: int
 */
int s_top(stack_t *stack)
{
	return (stack->n);
}
/*
 * s_swap - swap the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * Return: bool, true if swapped, false otherwise
 */
bool s_swap(stack_t *stack)
{
	int temp;

	if (stack == NULL || stack->next == NULL || stack->next == NULL)
		return (false);
	temp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = temp;
	return (true);
}

/*
 * s_isEmpty - Checks if the stack is empty
 * @stack: Pointer to the head of the stack
 * Return: int
 */
bool s_isEmpty(stack_t *stack)
{
	return (stack == NULL);
}

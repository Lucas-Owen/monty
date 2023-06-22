#include "stack.h"

/**
 * s_swap - swap the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * Return: bool, true if swapped, false otherwise
 */
bool s_swap(stack_t **stack)
{
	int temp;

	if ((*stack) == NULL || (*stack)->next == NULL || (*stack)->next == NULL)
		return (false);
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
	return (true);
}

/**
 * s_rotl - Moves the top element to be the last in the stack
 * @stack: Pointer to the head of the stack
 * Return: void
 */
void s_rotl(stack_t **stack)
{
	stack_t *temp = *stack, *first = *stack;

	if (temp == NULL || temp->next == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = temp;
	temp->next = first;
}

/**
 * s_rotr - Moves the bottom element to be the first in the stack
 * @stack: Pointer to the head of the stack
 * Return: void
 */
void s_rotr(stack_t **stack)
{
	stack_t *second_last = *stack, *first = *stack;

	if (first == NULL || first->next == NULL)
		return;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next->prev = NULL;
	second_last->next->next = (*stack);
	(*stack)->prev = second_last->next;
	(*stack) = second_last->next;
	second_last->next = NULL;
}

/**
 * s_reverse - Reverse the stack such that the top becomes the bottom
 * @stack: Pointer to the head of the stack
 * Return: void
 */
void s_reverse(stack_t **stack)
{
	stack_t *temp, *next;

	if (*stack == NULL)
		return;
	temp = *stack;
	while (temp)
	{
		*stack = temp;
		next = temp->next;
		temp->next = temp->prev;
		temp->prev = next;
		temp = next;
	}
}

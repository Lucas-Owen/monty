#include "monty.h"

/**
 * cleanup - Free space allocated to the stack when the program exits
 */
void cleanup(void)
{
	extern stack_t *operands;

	while (!s_isEmpty(operands))
		s_pop(&operands);
}

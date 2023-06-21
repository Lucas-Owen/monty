#include "monty.h"
#include "externs.h"

/**
 * cleanup - Free space allocated to the stack when the program exits
 */
void cleanup(void)
{

	while (!s_isEmpty(operands))
		s_pop(&operands);
}

#include "monty.h"

void cleanup()
{
	extern stack_t *operands;

	while (!s_isEmpty(operands))
		s_pop(&operands);
}

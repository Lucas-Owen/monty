#include "monty.h"
#include "externs.h"

/**
 * cleanup - Free space allocated to the stack when the program exits
 */
void cleanup(void)
{
	if (globals.fp)
		fclose(globals.fp);
	while (!s_isEmpty(globals.operands))
		s_pop(&globals.operands);
}

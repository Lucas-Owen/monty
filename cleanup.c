#include "monty.h"
#include "externs.h"

/**
 * cleanup - Free space allocated to the stack when the program exits
 */
void cleanup(void)
{
	if (globals.fd != -1)
		close(globals.fd);
	free(globals.current_instruction.opcode);
	s_clear(&globals.operands);
}

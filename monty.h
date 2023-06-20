#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <string.h>

#include "stack.h"
#include "utils.h"

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void eval_input(char *buffer, unsigned int line_number, instruction_t *instruction);
void i_push(stack_t **stack, unsigned int line_number);
void i_pall(stack_t **stack, unsigned int line_number);

__attribute__((destructor)) void cleanup();


#endif /* MONTY_H */

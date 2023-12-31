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

/**
 * struct global_vars_s - Structure to hold global variables
 * @fd: File pointer to the file being read
 * @operands: The main stack used to store variables
 * @opmode: Whether as a queue or stack
 * @current_instruction: Instruction under execution
 *
 * Description: To keep track of fd, operands (stack), and
 * instruction.opcode to be freed at exit
 */
typedef struct global_vars_s
{
	FILE *fd;
	stack_t *operands;
	char opmode;
	instruction_t current_instruction;
} global_vars_t;

void eval_input(char *buffer, unsigned int);

#define MODE_STACK 0
#define MODE_QUEUE 1

#define I_PUSH	0
#define I_PALL	1
#define I_POP	2
#define I_PINT	3
#define I_SWAP	4
#define I_NOP	5
#define I_ADD	6
#define I_SUB	7
#define I_MUL	8
#define I_DIV	9
#define I_MOD	10
#define I_PCHAR 11
#define I_PSTR	12
#define I_ROTL	13
#define I_ROTR	14
#define I_STACK	15
#define I_QUEUE	16

void i_push(stack_t **stack, unsigned int line_number);
void i_nop(stack_t **stack, unsigned int line_number);
void i_pall(stack_t **stack, unsigned int line_number);
void i_pop(stack_t **stack, unsigned int line_number);
void i_pint(stack_t **stack, unsigned int line_number);

void i_swap(stack_t **stack, unsigned int line_number);
void i_rotl(stack_t **stack, unsigned int line_number);
void i_rotr(stack_t **stack, unsigned int line_number);

void i_add(stack_t **stack, unsigned int line_number);
void i_sub(stack_t **stack, unsigned int line_number);
void i_mul(stack_t **stack, unsigned int line_number);
void i_div(stack_t **stack, unsigned int line_number);
void i_mod(stack_t **stack, unsigned int line_number);

void i_pchar(stack_t **stack, unsigned int line_number);
void i_pstr(stack_t **stack, unsigned int line_number);

__attribute__((destructor)) void cleanup(void);


#endif /* MONTY_H */

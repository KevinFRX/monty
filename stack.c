#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: the stack
 * @line: the line where the opcode is
 */
void _stack(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;

	gv.mode = stack_mode;
}

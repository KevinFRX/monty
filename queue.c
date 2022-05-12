#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @stack: the stack
 * @line: the line where the opcode is
 */
void _queue(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;

	gv.mode = queue_mode;
}

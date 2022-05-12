#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line)
{
	stack_t *cnode = *stack;
	(void)line;

	if (*stack && (*stack)->next)
	{
		while (cnode->next)
			cnode = cnode->next;
		cnode->next = *stack;
		(*stack)->prev = cnode;
		cnode->prev->next = NULL;
		cnode->prev = NULL;
		*stack = cnode;
	}		
}

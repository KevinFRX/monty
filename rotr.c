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
	int aux;
	stack_t *cnode = *stack;
	(void)line;

	if (*stack && (*stack)->next)
	{
		while (cnode->next)
			;
		aux = cnode->n;
		cnode = *stack;
		while (cnode->next)
		{
			cnode->next->n = cnode->n;
			cnode = cnode->next;
		}
		(*stack)->n = aux;
	}
}

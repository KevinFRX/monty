#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line)
{
	int aux;
	stack_t *cnode = *stack;
	(void)line;

	if (*stack && (*stack)->next)
	{
		aux = cnode->n;
		while (cnode->next)
		{
			cnode->n = cnode->next->n;
			cnode = cnode->next;
		}
		cnode->n = aux;
	}
}

#include "monty.h"

/**
 * _pall - rints all the values on the stack, starting from the top
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *cnode = *stack;
	(void)line;

	while (cnode != NULL)
	{
		printf("%d\n", cnode->n);
		cnode = cnode->next;
	}
}

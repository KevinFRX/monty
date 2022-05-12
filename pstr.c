#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line)
{
	stack_t *cnode = *stack;
	(void)line;

	while (cnode != NULL && cnode->n != 0)
	{
		if (cnode->n > 31 && cnode->n < 128)
			printf("%c", cnode->n);
		cnode = cnode->next;
	}
	printf("\n");
}

#include "monty.h"

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

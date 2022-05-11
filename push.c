#include "monty.h"
#include <ctype.h>

void _push(stack_t **stack, unsigned int line)
{
	stack_t *node, *end = *stack;

	if (gv.n == NULL || !(isdigit(gv.n)))
	{
		free_stack(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(gv.n);
	if (gv.mode == stack_mode || (*stack) == NULL)
	{
		node->prev = NULL;
		node->next = *stack;
		if (*stack)
			(*stack)->prev = node;
		*stack = node;
	}
	else
	{
		while (end->next != NULL)
			end = end->next;
		end->next = node;
		node->prev = end;
		node->next = NULL;
	}
}

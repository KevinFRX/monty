#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *dnode = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(dnode);
	}
	else
	{
		*stack = NULL;
		free(dnode);
	}
}

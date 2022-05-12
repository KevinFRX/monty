#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	_pop(stack, line);
}

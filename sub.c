#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	_pop(stack, line);
}

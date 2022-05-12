#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	_pop(stack, line);
}

#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

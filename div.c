#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	_pop(stack, line);
}

#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 65 || (*stack)->n > 90)
	{
		if ((*stack)->n < 97 || (*stack)->n > 122)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	printf("%c\n", (*stack)->n);
}

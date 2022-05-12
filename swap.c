#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line)
{
	stack_t *aux = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next = aux->next;
	(*stack)->prev = aux;
	aux->next = *stack;
	aux->prev = NULL;
	*stack = aux;
}

#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *remove = stack;

	while (stack)
	{
		stack = stack->next;
		free(remove);
		remove = stack;
	}
	free(gv.token);
	fclose(gv.input_file);
}

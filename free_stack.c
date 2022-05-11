#include "monty.h"

/**
 * free_all - frees all allocated memory
 * @stack: pointer to linked list
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

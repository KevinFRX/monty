#include "monty.h"
#include <ctype.h>

/**
 * is_number - checks if the string is a number
 * @n: the string/number
 *
 * Return: -1 if is not a number 0 if it is
 */
int is_number(char *n)
{
	int i = 0;

	if (n[0] == '-')
		i = 1;

	for (; n[i] != '\0'; i++)
	{
		if (n[i] < 48 || n[i] > 57)
			return (-1);
	}
	return (0);
}

/**
 * _push - pushes an element to the stack
 * @stack: the stack
 * @line: the line where the opcode is
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line)
{
	stack_t *node, *end = *stack;

	if (gv.n == NULL || is_number(gv.n) == -1)
	{
		free_stack(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(gv.n);
	if (gv.mode == stack_mode || (*stack) == NULL)
	{
		node->prev = NULL;
		node->next = *stack;
		if (*stack)
			(*stack)->prev = node;
		*stack = node;
	}
	else
	{
		while (end->next != NULL)
			end = end->next;
		end->next = node;
		node->prev = end;
		node->next = NULL;
	}
}

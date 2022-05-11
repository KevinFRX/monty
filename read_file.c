#include "main.h"

void read_file(void)
{
	int i;
	char *contents = NULL;
	size_t len;
	unsigned int line = 0;
	stack_t *stack = NULL;
	instruction_t op_matrix[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{"stack", _stack}, {"queue", _queue},
		{NULL, NULL}
	};

	while (getline(&contents, &len, gv.input_file) != -1)
	{
		line++;
		gv.token = strtok(contents, "\n");
		if (gv.token == NULL || gv.token[0] == '#')
			continue;
		for (i = 0; op_matrix[i].opcode != NULL; i++)
		{
			if (strcmp(op_matrix[i].opcode, gv.token) == 0)
			{
				gv.n = strtok(NULL, "\n");
				op_matrix[i].f(&stack, line);
				break;
			}
		}
		if (op_matrix[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, gv.token);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
}

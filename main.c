#include "monty.h"

global_variables_t gv;

int main(int argc, char const *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	gv.mode = stack_mode;

	gv.input_file = fopen(argv[1], "r");
	if (gv.input_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	read_file();
	return (0);
}

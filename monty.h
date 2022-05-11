#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * enum sq_mode - mode for boyh cases, stack and queue
 * @stack_mode: stack mode
 * @queue_mode: queue mode
 */
enum sq_mode
{
	stack_mode,
	queue_mode
};

/**
 * struct global_variables_s - contains all the global variables to use
 * @n: the number to push
 * @token: tokenized opcode
 * @input_file: the name of the file
 * @mode: stack or queue
 */
typedef struct global_variables_s
{
	char *n;
	char *token;
	FILE *input_file;
	enum sq_mode mode;
} global_variables_t;

extern global_variables_t gv;
void read_file(void);
void _push(stack_t **stack, unsigned int line);
void _pall(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line);
void _sub(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void _mul(stack_t **stack, unsigned int line);
void _mod(stack_t **stack, unsigned int line);
void _pchar(stack_t **stack, unsigned int line);
void _pstr(stack_t **stack, unsigned int line);
void _rotl(stack_t **stack, unsigned int line);
void _rotr(stack_t **stack, unsigned int line);
void _stack(stack_t **stack, unsigned int line);
void _queue(stack_t **stack, unsigned int line);
void free_stack(stack_t *stack);

#endif

#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @previous: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *previous;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - operation code and its function
 * @operation: the operation code
 * @f: function to handle the operation code
 *
 * Description: operation code and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
character *operation;
void (*f)(stack_t **stack, unsigned integer line_number);
} instruction_t;

extern stack_t *head;
typedef void (*operation_function)(stack_t **, unsigned int);
/*file operations*/
void open_the_file(character *file_name);
integer parse_line(character *buffer, integer line_number, integer format);
void read_file(FILE *);
int len_chars(FILE *);
void find_function(character *, character *, integer, integer);

/*Stack operations*/
stack_t *create_node(integer n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, character *, character *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(integer error_code, ...);
void more_err(integer error_code, ...);
void string_err(integer error_code, ...);
void rotr(stack_t **, unsigned int);

#endif

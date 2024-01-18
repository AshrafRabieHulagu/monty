#ifndef MONTY_H
#define MONTY_H

/** HEADERS **/
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/** DATA STRUCTURES **/
/* Stack */
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

/** External Main Structure (Stack/Queue)**/
extern stack_t *head;

/** FILE Operation **/
void Open_FILE(char *file_name);
void Read_FILE(FILE *);
int tokenize_line(char *buffer, int line_number, int format);

/** Operation Functions **/
typedef void (*EXE_Func)(stack_t **, unsigned int);
void opcode_FUNC(char *, char *, int, int);
void CALL_Func(EXE_Func, char *, char *, int, int);

/** NODE Operation **/
stack_t *create_NODE(int n);
void free_NODEs(void);
void swap_NODEZ(stack_t **, unsigned int);
void LnodeF(stack_t **, unsigned int);
void FnodeL(stack_t **, unsigned int);

/*Structure (Stack/Queue) operations*/
void print_STACK(stack_t **, unsigned int);
void Push_STACK(stack_t **, unsigned int);
void in_QUEUE(stack_t **, unsigned int);
void Pop_STACK(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/** NODES Math Operations **/
void mul_NODEZ(stack_t **, unsigned int);
void add_NODEZ(stack_t **, unsigned int);
void div_NODEZ(stack_t **, unsigned int);
void mod_NODEZ(stack_t **, unsigned int);
void sub_NODEZ(stack_t **, unsigned int);

/** Print **/
void print_n_cASCII(stack_t **, unsigned int);
void print_n_strASCII(stack_t **, unsigned int);
void print_Lnode(stack_t **, unsigned int);

/** ERROR Hanlding Functions **/
void ERRor1(int error_code, ...);
void ERRor2(int error_code, ...);
void ERROR_handler(int error_code, ...);

#endif

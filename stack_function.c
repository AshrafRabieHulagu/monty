this codes and function Presenter from
Arafa Khalaf / Ashraf Rabie team project solution
#include "monty.h"


/**
 * add_to_stack - Adds node to stack.
 * @new_node: Pointer the new node.
 * @ln: Interger representing the line number of of the opertion code.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tmp = head;
head = *new_node;
head->next = tmp;
tmp->previous = head;
}

/**
 * print_stack - Adds node to stack.
 * @stack: pointing the top node of stack.
 * @line_number: line number of  the operation code.
 */
void print_stack(stack_t **stack, unsigned integer line_number)
{
stack_t *tmp;

(void) line_number;
if (stack == NULL)
exit(EXIT_FAILURE);
tmp = *stack;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opertion code.
 */
void pop_top(stack_t **stack, unsigned integer line_number)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL)
more_error(7, line_number);

tmp = *stack;
*stack = tmp->next;
if (*stack != NULL)
(*stack)->previous = NULL;
free(tmp);
}

/**
 * print_top - Prints top node of stack.
 * @stack: pointer a pointing to the top node of the stack.
 * @line_number: An integer that represents
 *               the line number of the opertion code.
 */
void print_top(stack_t **stack, unsigned integer line_number)
{
if (stack == NULL || *stack == NULL)
more_error(6, line_number);
printf("%d\n", (*stack)->n);
}

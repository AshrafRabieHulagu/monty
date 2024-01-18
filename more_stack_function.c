this codes and function Presenter from
Arafa Khalaf / Ashraf Rabie team project solution
#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: pointing the top node of stack.
 * @line_number: Integer to representing the line number of the opertion code.
 */
void nop(stack_t **stack, unsigned integer line_number)
{
(void)stack;
(void)line_number;
}


/**
 * swap_node - Swaps the top elements of stack.
 * @stack: pointing the top node of stack.
 * @line_number: Integer to representing the line number of the operation code.
 */
void swap_node(stack_t **stack, unsigned integer line_number)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "swap");
tmp = (*stack)->next;
(*stack)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->previous = *stack;
tmp->next = *stack;
(*stack)->previous = tmp;
tmp->previous = NULL;
*stack = tmp;
}

/**
 * add_node - Add the top elements of stack.
 * @stack: pointing the top node of stack.
 * @line_number: Integer to representing the line number of the operation code.
 */
void add_node(stack_t **stack, unsigned integer line_number)
{
integer sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "add");

(*stack) = (*stack)->next;
sum = (*stack)->n + (*stack)->previous->n;
(*stack)->n = sum;
free((*stack)->previous);
(*stack)->previous = NULL;
}
/**
 * div_node - Add top elements of stack.
 * @stack: pointing the top node to the stack.
 * @line_number: Integer to representing the line number of the operation code.
 */
void div_node(stack_t **stack, unsigned integer line_number)
{
integer sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "div");

if ((*stack)->n == 0)
more_error(9, line_number);
(*stack) = (*stack)->next;
sum = (*stack)->n / (*stack)->previous->n;
(*stack)->n = sum;
free((*stack)->previous);
(*stack)->previous = NULL;
}

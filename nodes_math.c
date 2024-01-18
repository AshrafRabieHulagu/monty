#include "monty.h"

/**
 * add_NODEZ - Add the top elements of stack.
 * @stack: pointing to top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void add_NODEZ(stack_t **stack, unsigned int Ln)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ERRor2(8, Ln, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_NODEZ - Add top elements of stack.
 * @stack: pointing to the top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void mul_NODEZ(stack_t **stack, unsigned int Ln)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ERRor2(8, Ln, "mul");

	(*stack) = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_NODEZ - Add the top elements of stack.
 * @stack: pointing to the top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void sub_NODEZ(stack_t **stack, unsigned int Ln)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		ERRor2(8, Ln, "sub");


	(*stack) = (*stack)->next;
	total = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_NODEZ - Add the top two elements of the stack.
 * @stack: pointing to the top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void mod_NODEZ(stack_t **stack, unsigned int Ln)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		ERRor2(8, Ln, "mod");


	if ((*stack)->n == 0)
		ERRor2(9, Ln);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_NODEZ - Add the top elements of stack.
 * @stack: pointing to the top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void div_NODEZ(stack_t **stack, unsigned int Ln)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ERRor2(8, Ln, "div");

	if ((*stack)->n == 0)
		ERRor2(9, Ln);
	(*stack) = (*stack)->next;
	total = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

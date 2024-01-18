#include "monty.h"

/**
 * create_NODE - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer of the node. Otherwise NULL.
 */
stack_t *create_NODE(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		ERRor1(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_NODEs - Free nodes in stack.
 */
void free_NODEs(void)
{
	stack_t *Temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		Temp = head;
		head = head->next;
		free(Temp);
	}
}

/**
 * swap_NODEZ - Swap the top elements of stack.
 * @stack: pointing the top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void swap_NODEZ(stack_t **stack, unsigned int Ln)
{
	stack_t *Temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ERRor2(8, Ln, "swap");
	Temp = (*stack)->next;
	(*stack)->next = Temp->next;
	if (Temp->next != NULL)
		Temp->next->prev = *stack;
	Temp->next = *stack;
	(*stack)->prev = Temp;
	Temp->prev = NULL;
	*stack = Temp;
}

/**
 * LnodeF - Rotates to the first node of stack to reach to the bottom.
 * @stack: pointing to the top node of stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void LnodeF(stack_t **stack, __attribute__((unused))unsigned int Ln)
{
	stack_t *Temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	Temp = *stack;
	while (Temp->next != NULL)
		Temp = Temp->next;

	Temp->next = *stack;
	(*stack)->prev = Temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * FnodeL - Rotate the node of stack to the top.
 * @stack: pointing to the top node of the stack.
 * @Ln: Integer to representing the line number of the operation code.
 */
void FnodeL(stack_t **stack, __attribute__((unused))unsigned int Ln)
{
	stack_t *Temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	Temp = *stack;

	while (Temp->next != NULL)
		Temp = Temp->next;

	Temp->next = *stack;
	Temp->prev->next = NULL;
	Temp->prev = NULL;
	(*stack)->prev = Temp;
	(*stack) = Temp;
}

#include "monty.h"


/**
 * Push_STACK - ADD Node to Stack.
 * @new_node: New-Node Pointer.
 * @Ln: the opcode line number.
 * Return: Nothing.
 */
void Push_STACK(stack_t **new_node, __attribute__((unused))unsigned int Ln)
{
	stack_t *Temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	Temp = head;
	head = *new_node;
	head->next = Temp;
	Temp->prev = head;
}


/**
 * print_STACK - Print the stack nodes.
 * @stack: Pointer to Stack TOP-node Pointer.
 * @Ln: the opcode line number.
 * Return: Nothing.
 */
void print_STACK(stack_t **stack, unsigned int Ln)
{
	stack_t *Temp;

	(void) Ln;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	Temp = *stack;
	while (Temp != NULL)
	{
		printf("%d\n", Temp->n);
		Temp = Temp->next;
	}
}

/**
 * Pop_STACK - POP top_node from stack.
 * @stack: Pointer to Stack TOP-node Pointer.
 * @Ln: the opcode line number.
 * Return: Nothing.
 */
void Pop_STACK(stack_t **stack, unsigned int Ln)
{
	stack_t *Temp;

	if (stack == NULL || *stack == NULL)
		ERRor2(7, Ln);

	Temp = *stack;
	*stack = Temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(Temp);
}

/**
 * in_QUEUE - inqueue a new-node to the queue.
 * @new_node: Pointer to the new node.
 * @Ln: the opcode line number.
 * Return: Nothing.
 */
void in_QUEUE(stack_t **new_node, __attribute__((unused))unsigned int Ln)
{
	stack_t *Temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	Temp = head;
	while (Temp->next != NULL)
		Temp = Temp->next;

	Temp->next = *new_node;
	(*new_node)->prev = Temp;

}

/**
 * nop - Does Nothing.
 * @stack: Pointer to Stack TOP-node Pointer.
 * @Ln: the opcode line number.
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int Ln)
{
	(void)stack;
	(void)Ln;
}

#include "monty.h"

/**
 * print_n_cASCII - Prints the Ascii char value.
 * @stack: Stack TOP-node Pointer.
 * @Ln: the opcode line number.
 */
void print_n_cASCII(stack_t **stack, unsigned int Ln)
{
	int _ASCII;

	if (stack == NULL || *stack == NULL)
		ERROR_handler(11, Ln);

	_ASCII = (*stack)->n;
	if (_ASCII < 0 || _ASCII > 127)
		ERROR_handler(10, Ln);
	printf("%c\n", _ASCII);
}

/**
 * print_Lnode - Print Stack Last(top) node.
 * @stack: Pointer to Stack TOP-node Pointer.
 * @Ln: the opcode line number.
 */
void print_Lnode(stack_t **stack, unsigned int Ln)
{
	if (stack == NULL || *stack == NULL)
		ERRor2(6, Ln);
	printf("%d\n", (*stack)->n);
}


/**
 * print_n_strASCII - Print the top_node->n string.
 * @stack: Pointer to Stack TOP-node Pointer.
 * @ln: the opcode line number.
 */
void print_n_strASCII(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int _ASCII;
	stack_t *Temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	Temp = *stack;
	while (Temp != NULL)
	{
		_ASCII = Temp->n;
		if (_ASCII <= 0 || _ASCII > 127)
			break;
		printf("%c", _ASCII);
		Temp = Temp->next;
	}
	printf("\n");
}

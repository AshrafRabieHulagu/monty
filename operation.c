include "monty.h"

/**
 * opcode_FUNC - find Function for the opcode.
 * @opcode: the opcode.
 * @value: the opcode argument.
 * @Data_Type:  storage format.  0 => stack,	1 => queue.
 * @Line: the line-number.
 * Return: Nothing.
 */
void opcode_FUNC(char *opcode, char *value, int Line, int Data_Type)
{
	int i;
	int flg;

	instruction_t func_list[] = {
		{"push", Push_STACK},
		{"pall", print_STACK},
		{"pint", print_Lnode},
		{"pop", Pop_STACK},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_n_cASCII},
		{"pstr", print_n_strASCII},
		{"LnodeF", LnodeF},
		{"FnodeL", FnodeL},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			CALL_Func(func_list[i].f, opcode, value, Line, Data_Type);
			flg = 0;
		}
	}
	if (flg == 1)
		ERRor1(3, Line, opcode);
}


/**
 * CALL_Func - Function to Call FUNCTION.
 * @func: required function pointer.
 * @op: the opcode as string.
 * @str_val: the numeric value of the string.
 * @Line: the instruction line numeber.
 * @Data_Type: Format specifier.	0 => stack. 1 => queue.
 * Return: Nothing.
 */
void CALL_Func(EXE_Func func, char *op, char *str_val, int Line, int Data_Type)
{
	stack_t *node;
	int flg;
	int i;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (str_val != NULL && str_val[0] == '-')
		{
			str_val = str_val + 1;
			flg = -1;
		}
		if (str_val == NULL)
			ERRor1(5, Line);
		for (i = 0; str_val[i] != '\0'; i++)
		{
			if (isdigit(str_val[i]) == 0)
				ERRor1(5, Line);
		}
		node = create_NODE(atoi(str_val) * flg);
		if (Data_Type == 0)
			func(&node, Line);
		if (Data_Type == 1)
			in_QUEUE(&node, Line);
	}
	else
		func(&head, Line);
}

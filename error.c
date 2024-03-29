#include "monty.h"
/**
 * ERRor1 - Prints the appropriate error messages identified by error code.
 * @error_code: error codes in the following:
 * (1) => user does not give any file or more than one file to the program.
 * (2) => file provided is not a file that can be opened or read.
 * (3) => file provided contains an invalid instruction.
 * (4) => When program is unable to malloc memory.
 * (5) => When parameter passed to the instruction "push" is not an integer.
 * (6) => When stack it empty for print.
 * (7) => When the stack it empty from pop.
 * (8) => When stack is short for operation.
 */
void ERRor1(int error_code, ...)
{
	va_list _ag;
	char *op;
	int Ln_num;

	va_start(_ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(_ag, char *));
			break;
		case 3:
			Ln_num = va_arg(_ag, int);
			op = va_arg(_ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", Ln_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(_ag, int));
			break;
		default:
			break;
	}
	free_NODEs();
	exit(EXIT_FAILURE);
}

/**
 * ERRor2 - handle error.
 * @error_code: The error codes are the following:
 * (6) => When stack it empty from print.
 * (7) => When stack it empty from pop.
 * (8) => When stack is short for operation.
 * (9) => Division get zero.
 */
void ERRor2(int error_code, ...)
{
	va_list _ag;
	char *op;
	int Ln_num;

	va_start(_ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(_ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(_ag, int));
			break;
		case 8:
			Ln_num = va_arg(_ag, unsigned int);
			op = va_arg(_ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", Ln_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(_ag, unsigned int));
			break;
		default:
			break;
	}
	free_NODEs();
	exit(EXIT_FAILURE);
}

/**
 * ERROR_handler - handles errors.
 * @error_code: error codes are the following:
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> stack is empty.
 */
void ERROR_handler(int error_code, ...)
{
	va_list _ag;
	int Ln_num;

	va_start(_ag, error_code);
	Ln_num = va_arg(_ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", Ln_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", Ln_num);
			break;
		default:
			break;
	}
	free_NODEs();
	exit(EXIT_FAILURE);
}

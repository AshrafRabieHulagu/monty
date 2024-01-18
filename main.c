#include "monty.h"

stack_t *head = NULL;

/**
 * main - MAIN Project Function
 * @argc: arguments count
 * @argv: list of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	Open_FILE(argv[1]);
	free_NODEs();
	return (0);
}

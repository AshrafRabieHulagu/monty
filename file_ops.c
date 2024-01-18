#include "monty.h"

/**
 * Open_FILE - Function to Open File.
 * @FileName: the File name full PATH.
 * Return: Nothing.
 */

void Open_FILE(char *FileName)
{
	FILE *std_fd = fopen(FileName, "r");

	if (FileName == NULL || std_fd == NULL)
		ERRor1(2, FileName);

	Read_FILE(std_fd);
	fclose(std_fd);
}


/**
 * Read_FILE - Function to Read File.
 * @std_fd: std-stream file descriptor pointer.
 * Return: Nothing.
 */

void Read_FILE(FILE *std_fd)
{
	int Ln_n;
	int formated = 0;
	size_t len = 0;
	char *Ln_buffer = NULL;

	for (Ln_n = 1; getline(&Ln_buffer, &len, std_fd) != -1; Ln_n++)
	{
		formated = tokenize_line(Ln_buffer, Ln_n, formated);
	}
	free(Ln_buffer);
}


/**
 * tokenize_line - Line Tokenization Function.
 * @Ln_buffer: Line from File
 * @Ln_n: the Line number
 * @Data_Type:  storage format. If 0 => stack,	1 n=> queue.
 * Return: Returns 0 => stack. 1 => queue.
 */

int tokenize_line(char *Ln_buffer, int Ln_n, int Data_Type)
{
	char *opcode;
	char *token;
	const char *separator = "\n ";

	if (Ln_buffer == NULL)
		ERRor1(4);

	opcode = strtok(Ln_buffer, separator);
	if (opcode == NULL)
		return (Data_Type);
	token = strtok(NULL, separator);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	opcode_FUNC(opcode, token, Ln_n, Data_Type);
	return (Data_Type);
}

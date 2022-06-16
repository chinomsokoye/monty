#include "monty.h"

/**
 * parse_line - parses line
 * @line: the line
 * Return: pointer
 */

instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	instruction->opcode = opcode;
	instruction->f = NULL;

	if (instruction->opcode)
	{
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = push;
		if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = pall;
		if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = pint;
		if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = pop;
		if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = swap;
		if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = add;
		if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = nop;
	}
	return (instruction);
}

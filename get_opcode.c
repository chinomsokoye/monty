#include "monty.h"

/**
 * get_opcode - gets opcode
 * @string: string line
 * Return: opcode
 */

char *get_opcode(char *string)
{
	char *opcode;

	opcode = strtok(string, "\n\t ");
	return (opcode);
}

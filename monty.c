#include "monty.h"
int SQ = 1;

/**
 * main - main function
 * @argc: count
 * @argv: array
 * Return: exit code
 */

int main(int argc, char **argv)
{
	FILE *file_in;
	unsigned int line_number = 0;
	char *line = NULL;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	size_t glsize = 0;

	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &glsize, file_in) != -1)
	{
		line_number++;
		instruction = parse_line(line);
		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}
		if (instruction->f)
			instruction->f(&top, line_number);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n",
				line_number, instruction->opcode);
			if (line)
				free(line);
			if (top)
				free_stack(top);
			free(instruction);
			fclose(file_in);
			exit(EXIT_FAILURE);
		}
		if (line)
			free(line);
		line = NULL;
		free(instruction);
	}
	if (line)
		free(line);
	free_stack(top);
	fclose(file_in);
	return (0);
}

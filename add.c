#include "monty.h"

/**
 * add - add elements in stack
 * @stack: the stack
 * @line_number: line number
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int summation;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	summation = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = summation;
}

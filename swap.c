#include "monty.h"

/**
 * swap - swap stack, queue
 * @stack: the stack
 *@line_number: line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int swaps;

	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	swaps = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swaps;
}

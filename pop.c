#include "monty.h"

/**
 * pop - remove top element
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pop and empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

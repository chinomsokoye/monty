#include "monty.h"

/**
 * pall - print stack queue
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	UNUSED(line_number);

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

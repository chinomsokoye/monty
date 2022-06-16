#include "monty.h"

/**
 * is_int - valid string for atoi
 * @str: string
 * Return: 0 or 1
 */

int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (*str == '-')
		i++;
	for (i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

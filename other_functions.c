#include "monty.h"
/**
 * _pint - prints the number of the head node
 * @stack: the stack
 * @line_number: line number
 * Return: None
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

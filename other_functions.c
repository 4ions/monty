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

/**
 * _pop - pop the top element off the stack, i.e. remove head
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	else if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		next->prev = NULL;
		free(*stack);
		*stack = next;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
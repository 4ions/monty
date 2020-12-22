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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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

/**
 * _swap - swap the top two elements
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: Pointer to head of stack)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *coun_temp = *stack;
	int count, sum;

	while (coun_temp)
		coun_temp = coun_temp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}

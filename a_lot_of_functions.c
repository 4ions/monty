#include "monty.h"

/**
 *_pchar - prints the char of the head 
 *@stack_t: stack
 *@line_number: Current line number
 *
 *Return: No return
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the char type of the head node integer
 * @stack: the stack
 * @line_number: line number
 *
 * Return: None
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	for (tmp = *stack; tmp; tmp = tmp->next)
	{
		if (tmp->n < 1 || tmp->n > 127)
		{
			break;
		}
		printf("%c", tmp->n);
	}
	putchar('\n');
}

/**
 * _rotl - rotates the stack top to bottom
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *tmp;
	(void)line_number;

	if (stack && *stack)
	{
		num  = (*stack)->n;

		for (tmp = *stack; tmp->next; tmp = tmp->next)
			tmp->n = tmp->next->n;
		tmp->n = num;
	}
}

/**
 * _rotr - rotates the stack bottom to top
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *copy;
	(void)line_number;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}

/**
 * _stack  LIFO
 * @stack: the stack
 * @line_number: current line number
 *
 * Return: void
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	(void)line_number;

	things.value = 0;
}

/**
 * _queue -  FIFO
 * @stack: the stack
 * @line_number: Current line number
 *
 * Return: None
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	(void)line_number;

	things.value = 1;
}

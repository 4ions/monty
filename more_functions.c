#include "monty.h"
/**
 * _nop - does not print, do not pass go, do not collect $200
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - sub the top two elements of the stack
 * @stack: Pointer to head of stack)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *coun_temp = *stack;
	int count, res;

	while (coun_temp)
		coun_temp = coun_temp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	res = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = res;
}

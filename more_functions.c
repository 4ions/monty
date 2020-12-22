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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	res = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * _div - div the top two elements of the stack
 * @stack: Pointer to head of stack)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *coun_temp = *stack;
	int count, div;

	while (coun_temp)
		coun_temp = coun_temp->next, count++;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 *_mul - mul the top two elemets of the stack
 *@stack: pointer to head of stack
 *@line_number: Current line number
 *
 *Return: No return
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *count_temp = *stack;
	int count, mul;

	while (count_temp)
		count_temp = count_temp->next, count++;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n * (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = mul;
}

/**
 * _mod - div the top two elements of the stack
 * @stack: Pointer to head of stack)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *coun_temp = *stack;
	int count, mod;

	while (coun_temp)
		coun_temp = coun_temp->next, count++;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = mod;
}

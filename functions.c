#include "monty.h"

/**
 *add_dnodeint - add a new node at the beginning of a list
 *@head: head of de dobly linked list
 *@n: number to the new node
 *
 *Return: adress to the new node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}


/**
 *are_numbers - check if the user wrote a number
 *
 *@num: num
 *
 *Return: Return 0 if is success or 1 its fails
 */
int are_numbers(char *num)
{
	int i = 0;

	if (!num)
		return (0);
	if (*num == '-')
		num++;
	for (i = 0; num[i] != '\0'; i++)
	{
		if (!isdigit(*num))
			return (0);
	}
	return (1);

}


/**
 *_push - add the new node at the benning of a list
 *
 *@stack: head of stack
 *@line_number: number in
 *
 *Return: No return
 */
void _push(stack_t **stack, unsigned int line_number)
{

	int number;

	(void)line_number;

	if (!are_numbers(things.data_num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", things.line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	number = atoi(things.data_num);

	add_dnodeint(stack, number);

}

/**
 *_pall - print all nodes in the list
 *
 *@stack: head of the list
 *@line_number: number
 *
 *Return: No return
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

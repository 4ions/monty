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
 * add_dnodeint_end - adds a new node at the end of list.
 * @head: pointer to head of linked list
 * @n: numeric value
 *
 * Return: the new node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *tmp = *head;

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

	if (!(*head))
	{
		new_node->prev = NULL, new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next)
		tmp = tmp->next;

	new_node->prev = tmp;
	new_node->next = NULL;
	tmp->next = new_node;

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
	if (!num)
		return (0);

	if (*num == '-')
		num++;

	for (; *num; num++)
		if (!isdigit(*num))
			return (0);
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

	if (things.data && are_numbers(things.data_num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	number = atoi(things.data_num);
	
	if (things.value == 0)
		add_dnodeint(stack, number);
	else
		add_dnodeint_end(stack,number);

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

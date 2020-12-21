#include "monty.h"
/**
 *free_stack - free all the list
 *
 *Return: No return
 */
void free_stack()
{
	stack_t *temp;
	stack_t *head;

	if (things->stack)
	{
		head = things->stack;

		while (head)
		{
			temp = head->next;
			free(head);
			head = temp;
		}
	}
}


/**
 *free_all - free struct
 *Return: No return
 */

void free_all(void)
{
	if (things != NULL)
	{
		
		if (things->buffer != NULL)
			free(things->buffer);
		
		if (things->data != NULL)
			free(things->data);

		if (things->data_num != NULL)
			free(things->data_num);
		free_stack();
		free(things);
	}
}

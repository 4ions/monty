#include "monty.h"
/**
 *free_stack - free all the list
 *
 *Return: No return
 */
void free_stack(void)
{
	stack_t *tmp;

	while (things.stack)
	{
		tmp = things.stack;
		things.stack = things.stack->next;
		free(tmp);
	}

}


/**
 *free_all - free struct
 *Return: No return
 */

void free_all(void)
{

	if (things.buffer != NULL)
		free(things.buffer);

	free_stack();
	fclose(things.fp);
}

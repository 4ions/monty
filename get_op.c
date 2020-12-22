#include "monty.h"
#include <stddef.h>
#include <stdio.h>


/**
 *get_function - get what functions want do the users
 *
 *Return: No return
 *
 */

void (*get_function(void))(stack_t **stack, unsigned int line_number)
{
	int  i = 0;
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{NULL, NULL}
	};


	while (instructions[i].opcode && things.data)
	{
		if (strncmp(things.data, instructions[i].opcode, strlen(things.data)) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		things.line_num, things.data);
	free_all();
	exit(EXIT_FAILURE);
}

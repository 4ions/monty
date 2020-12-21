#include "monty.h"
#include <stddef.h>
#include <stdio.h>


/**
 *get_function - get what functions want do the users
 *
 *Return: No return
 *
 */

void(*get_function(void))(stack_t **stack, unsigned int line_number)
{

	static instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int  i = 0;

	while (instructions[i].opcode)
	{
		if (strncmp(things->data, instructions[i].opcode, strlen(things->data)) == 0)
		{
			return (instructions[i].f);
		}
		i++;

	}

	printf("Salio sin encontrar\n");
	exit(EXIT_FAILURE);
}

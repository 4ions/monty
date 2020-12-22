#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *save_things - save variables
 *
 *Return: No return
 */

void save_things(void)
{
	things.stack = NULL;
	things.buffer = NULL;
	things.line_num = 0;
}

/**
 *main - start of the program
 *@argc: count of arguments
 *@argv: arguments wrotes by the user
 *
 *Return: 0 is success or 1 its fail
 */

int main(int argc, char *argv[])
{
	int check = 0;
	FILE *fp;
	size_t nbytes = 0;
	void (*function)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	things.fp = fp;
	save_things();
	while ((check = getline(&things.buffer, &nbytes, things.fp)) != -1)
	{
		things.line_num++;
		things.data = strtok(things.buffer, "\t\n ");
		if (!(things.buffer[0] == '\n') && !(things.buffer[0] == '#') &&
		    things.buffer && things.data && !(things.data[0] == '#'))
		{
			things.data_num = strtok(NULL, "\t\n ");
			function = get_function();
			function(&things.stack, things.line_num);
		}
	}
	free_all();
	exit(EXIT_SUCCESS);
}


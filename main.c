#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *save_things - save variables
 *
 *Return: No return
 */


int save_things(void)
{

	things = malloc(sizeof(thing_s));
	if (!things)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}


	things->data = malloc(sizeof(char *) * 3);
	if (!things->data)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	things->stack = NULL;
	things->num = 0;
	things->data_num = NULL;
	things->buffer = NULL;

	return (EXIT_SUCCESS);
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

	FILE *fp;
	int check = 0;
	size_t nbytes = 0;
	char *buffer = NULL;
	void (*function)(stack_t **stack, unsigned int line_number);

	if (argc < 2)
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

	save_things();
	check = getline(&things->buffer, &nbytes, fp);
	things->buffer[strlen(things->buffer) - 1] = '\0';

	while (check >= 0)
	{
		if (!(things->buffer[0] == '\n') && !(things->buffer[0] == '#'))
		{
			things->data = strtok(things->buffer, "\n ");
			things->data_num = strtok(NULL, "\n ");
			function = get_function();
			function(&things->stack, things->num);
		}
		check = getline(&things->buffer, &nbytes, fp);
		things->line_num++;
	}
	fclose(fp);
	free(buffer);
	free(things);
	exit(EXIT_SUCCESS);
}


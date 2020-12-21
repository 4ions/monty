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
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}


	things->data = malloc(sizeof(char *) * 3);
	if (!things->data)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	things->stack = NULL;
	things->num = 0;
	things->data_num = NULL;

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
	int line_count = 0;
	void (*function)(stack_t **stack, unsigned int line_number);
	
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	save_things();
	check = getline(&buffer, &nbytes, fp);
	buffer[strlen(buffer) - 1] = '\0';

	while (check >= 0)
	{

		things->data = strtok(buffer, " \n\t");

		things->data_num = strtok(NULL, " \n\t");
		function = get_function();
		function(&things->stack, things->num);
		line_count++;

		check = getline(&buffer, &nbytes, fp);
	}

	fclose(fp);
	free(buffer);
	free(things);
	/* free(things->data); */
	/* free(things->data_num); */
	exit (EXIT_SUCCESS);
}


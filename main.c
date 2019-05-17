#include "monty.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 *main - Entry point for monty program
 *@argc: number of arguments to main
 *@argv: array of arguments to main
 *
 *Return: 0 for success, else EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t size;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n"
		, argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &size, file)) != -1)
	{
		line_number++;
		execute_command(&stack, line, line_number);
	}
	free(line);
	free_stack(&stack);
	fclose(file);
	exit(EXIT_SUCCESS);
	return (0);
}
/**
 *execute_command - find commands in current line of monty file
 *@line: current line of monty file
 *@l_num: number of line in monty file
 *@stack: linked list that monty files modify
 *
 *Return: void, else EXIT_FAILURE
 */
void execute_command(stack_t **stack, char *line, unsigned int l_n)
{
	char *token;
	int flag = 0;
	int i;
	instruction_t command[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{NULL, NULL}
	};

	token = strtok(line, DELIMITERS);
	for (i = 0; command[i].opcode; i++)
	{
		if (!strcmp(token, command[i].opcode))
		{
			command[i].f(stack, l_n);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_n, token);
		exit(EXIT_FAILURE);
	}
}
/**
 *is_int - check if parameter is an int
 *@line: string being checked
 *
 *Return: 1 if digit, else 0
 */
int is_int(char *line)
{
	int i;

	if (!line)
		return (0);
	if (line[0] == '-')
		i = 1;
	else
		i = 0;
	for (; line[i]; i++)
	{
		if (!isdigit(line[0]))
			return (0);
	}
	return (1);
}
/**
 *free_stack - frees the stack
 *@stack: linked list to be freed
 *
 *Return: Void.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = NULL;

	for (current = *stack; current; current = (*stack)->next)
	{
		if (current->prev)
			free(current->prev);
		if (!current->next)
			free(current);
	}
}

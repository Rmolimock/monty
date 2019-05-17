#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 *push - add node to the top of the stack
 *@stack: linked list modified by monty files
 *@l_n: current line of monty file
 *
 *Return: Void.
 */
void push(stack_t **stack, unsigned int l_n)
{
	stack_t *current;
	char *argument;

	(void) l_n;
	argument = strtok(NULL, "-");
	if (!is_int(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_n);
		exit(EXIT_FAILURE);
	}
	current = malloc(sizeof(stack_t));
	if (!current)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!*stack)
		current->next = NULL;
	else
	{
		current->next = *stack;
		(*stack)->prev = current;
	}
	current->prev = NULL;
	*stack = current;
	current->n = atoi(argument);
}
/**
 *pall - print all node values in the stack
 *@stack: the stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (*stack)
	{
		for (current = *stack; current; current = current->next)
			printf("%d\n", current->n);
	}
}
/**
 *pint - print first value in the stack
 *@stack: stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void pint(stack_t **stack, unsigned int line_number)
{

	(void) line_number;
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 *pop - delete top node in the stack
 *@stack: stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(temp);
}
/**
 *swap - switch top two node in the stack
 *@stack: stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	(void) line_number;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

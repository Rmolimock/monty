#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *add - add top two node of the stack
 *@stack: stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if ((*stack)->next)
	{
		n = (*stack)->n + (*stack)->next->n;
		printf("%d\n", n);
		(*stack)->next->n = n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 *nop - do nothing without error
 *@stack: stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
/**
 *_sub - subtract top node value from second
 *@stack: stack linked list
 *@line_number: current line of monty file
 *
 *Return: Void.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	(void) line_number;
	if ((*stack)->next)
	{
		result = (*stack)->next->n - (*stack)->n;
		printf("%d\n", result);
		(*stack)->next->n = result;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

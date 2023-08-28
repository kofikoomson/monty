#include "monty.h"
/**
 * _push - pushes int to stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *topp;
	(void)line_number;

	topp = malloc(sizeof(stack_t));
	if (topp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	topp->n = var_global.push_arg;
	topp->next = *stack;
	topp->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = topp;
	*stack = topp;
}

/**
 * _pall - prints all function
 * @stack: points to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *run_ner;

	run_ner = *stack;
	while (run_ner != NULL)
	{
		printf("%d\n", run_ner->n);
		run_ner = run_ner->next;
	}
}

/**
 * _pint - prints int a top of stack
 * @stack: points to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *run_ner;

	run_ner = *stack;
	if (run_ner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", run_ner->n);
}

/**
 * _pop - removes element of a list
 *@stack: points to first node
 *@line_number: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_ = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node_->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node_);
}

/**
 * free_dlistint - frees a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

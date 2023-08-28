#include "monty.h"

/**
 * _pstr - mods top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int m = 0;

	(void)line_number;


	while (temp)
	{
		m = temp->n;
		if (m == 0 || _isalpha(m) == 0)
			break;
		putchar(m);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * _rotl - mods top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *run_ner = *stack;


	int input_1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	input_1 = run_ner->n;

	while (run_ner->next)
	{
		run_ner = run_ner->next;
		run_ner->prev->n = run_ner->n;
	}

	run_ner->n = input_1;
}

/**
 * _rotr - mods top of stack y second top stacks
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *run_ner = *stack;

	int input_1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (run_ner->next)
		run_ner = run_ner->next;

	input_1 = run_ner->n;

	while (run_ner->prev)
	{
		run_ner = run_ner->prev;
		run_ner->next->n = run_ner->n;
	}

	run_ner->n = input_1;
}

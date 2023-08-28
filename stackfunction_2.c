#include "monty.h"
/**
 * _swap - swaps top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *run_ner;
	int temp;

	run_ner = *stack;
	if (run_ner == NULL || run_ner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = run_ner->n;
	run_ner->n = run_ner->next->n;
	run_ner->next->n = temp;
}

/**
 * _add - adds top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0, k = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		k++;
	}

	if (stack == NULL || (*stack)->next == NULL || k <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * _nop - nop top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: points to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int value_;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	value_ = (*stack)->n;
	if (value_ > 127 || value_ < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value_);
	putchar('\n');
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

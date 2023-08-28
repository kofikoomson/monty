#include "monty.h"

/**
 * _sub - subs top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub_ = 0, j = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		j++;
	}

	if (stack == NULL || (*stack)->next == NULL || j <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub_ = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sub_;
}

/**
 * _mul - mul top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int inpt;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		inpt = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= inpt;
	}
}

/**
 * _div - div top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int divi_ = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		divi_ = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= divi_;
	}
}

/**
 * _mod - mod top of stack y second top stack
 * @stack: points to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int moded = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		moded = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= moded;
	}
}

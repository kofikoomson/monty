#include "monty.h"
/**
 * push - add int to stack
 * @stack: list containing stacked int
 * @line_number: line number of opcode
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
 *  * _pall - prints all function
 *   * @stack: points to linked list stack
 *    * @line_number: number of line opcode occurs on
 *     */


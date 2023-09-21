#include "monty.h"

/**
 * opcode_nop - Does nothing.
 * @stack: Pointer to pointer to the first node.
 * @n: Integer value (unused).
 * Return: None.
 */
void opcode_nop(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{

}

/**
 * opcode_add - Adds the top two elements of the stack.
 * @stack: Pointer to pointer to the first node.
 * @n: Integer value (unused).
 * Return: None.
 **/
void opcode_add(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_ADD, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, n + m);
}

void opcode_sub(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_SUB, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, m - n);
}

/**
 * opcode_div - 
 * @stack: pointer to pointer to first node
 * @n: int value to be in added node
 * Return:
 **/
void opcode_div(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_DIV, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, m / n);
}

/**
 * opcode_mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to pointer to the first node.
 * @n: Integer value (unused).
 * Return: None.
 */
void opcode_mul(__attribute__((unused))stack_t **stack,
	__attribute__((unused))unsigned int line_number)
{
	int n;
	int m;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_MUL, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	m = pop(stack);
	insert_dnodeint_at_index(stack, 0, m * n);
}

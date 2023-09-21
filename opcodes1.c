#include "monty.h"

/**
 * `push_node_to_stack` - Pushes a node onto the stack.
 * @stack: Pointer to pointer to the first node.
 * @n: Integer value to be added to the node.
 * Return: 1 if added, 0 otherwise.
 */
void opcode_push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (data()->num_words < 2 || !is_num(data()->words[1]))
	{
		dprintf(STDERR_FILENO, ERR_PUSH, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
		return;
	}

	if (!push(stack, atoi(data()->words[1])))
	{
		dprintf(STDERR_FILENO, ERR_MALLOC);
		free_data(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * `pop_node_from_stack` - Pops a node from the stack.
 * @stack: Pointer to pointer to the first node.
 * @n: Pointer to an integer to store the value from the popped node (unused).
 * Return: None.
 */
void opcode_pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		dprintf(STDERR_FILENO, ERR_POP, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	pop(stack);
}

/**
 * peek - 
 * @stack: pointer to pointer to first node
 * @n: int value to be in added node
 * Return:
 **/
void opcode_pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (!get_dnodeint_at_index(*stack, 0))
	{
		dprintf(STDERR_FILENO, ERR_PINT, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", peek(stack));
}

/**
 * `opcode_pall` - Prints all the values on the stack.
 * @stack: Pointer to pointer to the first node.
 * @n: Integer value (unused).
 * Return: None.
 */
void opcode_pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	print_dlistint(*stack);
}

void opcode_swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int n;

	if (!get_dnodeint_at_index(*stack, 1))
	{
		dprintf(STDERR_FILENO, ERR_SWAP, data()->line_number);
		free_data(1);
		exit(EXIT_FAILURE);
	}
	n = pop(stack);
	insert_dnodeint_at_index(stack, 1, n);
}

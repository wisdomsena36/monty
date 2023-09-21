#include "monty.h"

/**
 * `push_node_to_stack` - Pushes a node onto the stack.
 * @head: Pointer to pointer to the first node.
 * @n: Integer value to be added to the node.
 * Return: 1 if added, 0 otherwise.
 */
int push(stack_t **head, int n)
{
	return (!!add_dnodeint(head, n));
}

/**
 * `pop_node_from_stack` - Pops a node from the stack.
 * @head: Pointer to pointer to the first node.
 * @n: Pointer to an integer to store the value from the popped node.
 * Return: None.
 */
int pop(stack_t **head)
{
	stack_t *node = get_dnodeint_at_index(*head, 0);
	int n = 0;
	
	n = node->n;
	delete_dnodeint_at_index(head, 0);
	return n;
}

/**
 * peek - 
 * @head: pointer to pointer to first node
 * @n: int value to be in added node
 * Return:
 **/
int peek(stack_t **head)
{
	stack_t *node = get_dnodeint_at_index(*head, 0);

	if (node)
		return (node->n);
	return (FAILURE);
}

/**
 * is_empty - 
 * @head: pointer to pointer to first node
 * @n: int value to be in added node
 * Return:
 **/
int is_empty(stack_t **head)
{
	return (!get_dnodeint_at_index(*head, 0));
}

void pall(stack_t *head)
{
	print_dlistint(head);
}

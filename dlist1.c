#include "lists.h"

/**
 * print_dlistint - It prints all the elements of dlistint_t list.
 * @h: Pointer to head node.
 * Return: total num of nodes or 0 Otherwise.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * dlistint_len - It counts all the elements in dlistint_t list.
 * @h: Pointer to head node.
 * Return: Num of nodes in list, 0 if NULL.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * sum_dlistint - It returns sum of all data contained.
 * @head: Pointer to first node.
 * Return: Sum of all elements in linked list or 0 if list is empty.
 **/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}

/**
 * add_dnodeint_end - It adds new node at the end of linked list.
 * @head: pointer to pointer to first node.
 * @n: int value to be help in added node.
 * Return: Address to new node, NULL if failed.
 **/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	dlistint_t *tmp;

	if (!head)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));

	if (!newNode)
		return (NULL);

	newNode->n = n;

	if (!*head)
	{
		*head = newNode;
		newNode->next = NULL;
		return (newNode);
	}
	tmp = *head;

	while (tmp->next)
		tmp = tmp->next;

	newNode->prev = tmp;
	tmp->next = newNode;
	newNode->next = NULL;
	return (newNode);
}

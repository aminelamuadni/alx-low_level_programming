#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;

	while (head)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
}

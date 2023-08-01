#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *slow, *fast;

	if (head == NULL)
		exit(98);

	slow = head;
	fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				printf("[%p] %d\n", (void *)slow, slow->n);
				slow = slow->next;
				nodes++;
			}
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			return (nodes);
		}
	}

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes++;
	}

	return (nodes);
}

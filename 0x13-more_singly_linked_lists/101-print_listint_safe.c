#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to head of list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num = 0;
	long int diff;
	const listint_t *temp;

	while (head)
	{
		diff = head - head->next;
		num++;

		temp = head;
		while (temp)
		{
			_putchar((temp->n / 10) + '0');
			_putchar((temp->n % 10) + '0');
			temp = temp->next;
		}
		_putchar('\n');

		if (diff > 0)
			head = head->next;
		else
		{
			temp = head->next;
			while (temp)
			{
				_putchar((temp->n / 10) + '0');
				_putchar((temp->n % 10) + '0');
				temp = temp->next;
			}
			_putchar('\n');
			break;
		}
	}

	return (num);
}

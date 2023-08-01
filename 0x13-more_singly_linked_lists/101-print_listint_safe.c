#include "lists.h"
#include <stdlib.h>

/**
 * print_hex - prints an address in hexadecimal
 * @n: the address to print
 *
 * Return: void
 */
void print_hex(unsigned long n)
{
	if (n > 15)
		print_hex(n / 16);
	n = n % 16;
	_putchar(n < 10 ? n + '0' : 'a' + n % 10);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: a pointer to the first element of listint_t list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num = 0;
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
				print_node(slow);
				slow = slow->next;
				num++;
			}
			print_node(slow);
			return (num);
		}
	}

	while (head != NULL)
	{
		print_node(head);
		head = head->next;
		num++;
	}

	return (num);
}

/**
 * print_node - prints a node
 * @node: a pointer to the node to print
 *
 * Return: void
 */
void print_node(const listint_t *node)
{
	_putchar('[');
	print_hex((unsigned long)node);
	_putchar(']');
	_putchar(' ');
	if (node->n < 0)
	{
		_putchar('-');
		print_int(-node->n);
	}
	else
	{
		print_int(node->n);
	}
	_putchar('\n');
}

/**
 * print_int - prints an integer
 * @n: the integer to print
 *
 * Return: void
 */
void print_int(int n)
{
	if (n / 10)
		print_int(n / 10);
	_putchar(n % 10 + '0');
}

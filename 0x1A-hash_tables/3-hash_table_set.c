#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * update_value - updates the value of a key in the hash table
 * @node: the hash node
 * @value: the new value
 *
 * Return: 1 if successful, 0 otherwise
 */
int update_value(hash_node_t *node, const char *value)
{
	free(node->value);
	node->value = strdup(value);
	if (!node->value)
		return (0);
	return (1);
}

/**
 * add_new_node - adds a new node to the hash table
 * @head: pointer to the head of the list
 * @key: the key
 * @value: the value
 *
 * Return: 1 if successful, 0 otherwise
 */
int add_new_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = *head;
	*head = new_node;
	return (1);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *temp;

	if (!ht || !key || !*key || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (update_value(temp, value));
		temp = temp->next;
	}

	return (add_new_node(&ht->array[idx], key, value));
}

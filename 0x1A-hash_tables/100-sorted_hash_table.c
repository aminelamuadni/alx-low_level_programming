#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 * Return: pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int i;

	new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return (NULL);

	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * create_new_node - creates a new node for the sorted hash table
 * @key: the key for the new node
 * @value: the value for the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (!new_node->key || !new_node->value)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (NULL);
	}
	return (new_node);
}

/**
 * handle_existing_key - Updates value of an existing node in the table.
 * @node: The node with the key that already exists.
 * @key: The key associated with the node.
 * @value: The new value to update the node with.
 *
 * Return: 1 if the value was updated successfully, 0 otherwise.
 */
int handle_existing_key(shash_node_t *node, const char *key, const char *value)
{
	if (strcmp(node->key, key) == 0)
	{
		free(node->value);
		node->value = strdup(value);
		if (!node->value)
			return (0);
		return (1);
	}
	return (0);
}

/**
 * insert_into_sorted_list - Inserts a node into the sorted doubly linked list
 *						   of the hash table.
 * @ht: The sorted hash table.
 * @new_node: The new node to insert into the sorted list.
 * @key: The key associated with the node.
 *
 * Return: void
 */
void insert_into_sorted_list(shash_table_t *ht,
							 shash_node_t *new_node,
							 const char *key)
{
	shash_node_t *current_node = ht->shead, *prev_node = NULL;

	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return;
	}

	while (current_node && strcmp(key, current_node->key) > 0)
	{
		prev_node = current_node;
		current_node = current_node->snext;
	}

	if (!current_node)
	{
		prev_node->snext = new_node;
		new_node->sprev = prev_node;
		new_node->snext = NULL;
		ht->stail = new_node;
	}
	else
	{
		new_node->snext = current_node;
		new_node->sprev = current_node->sprev;

		if (current_node->sprev)
			current_node->sprev->snext = new_node;
		else
			ht->shead = new_node;

		current_node->sprev = new_node;
	}
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *current_node, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	while (current_node)
	{
		if (handle_existing_key(current_node, key, value))
			return (1);
		current_node = current_node->next;
	}

	new_node = create_new_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	insert_into_sorted_list(ht, new_node, key);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key
 * Return: value associated with the key, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the sorted hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the sorted hash table in reverse
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *temp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}
	free(ht->array);
	free(ht);
}

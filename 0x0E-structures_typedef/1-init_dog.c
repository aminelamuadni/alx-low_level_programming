#include "dog.h"

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: The dog structure to initialize
 * @name: The name to set
 * @age: The age to set
 * @owner: The owner to set
 *
 * Return: Nothing.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

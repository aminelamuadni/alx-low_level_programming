#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints a struct dog
 * @d: the pointer to struct dog to print
 *
 * Return: Nothing.
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		printf("Name: ");
		d->name == NULL ? printf("(nil)\n") : printf("%s\n", d->name);
		printf("Age: ");
		d->age < 0 ? printf("(nil)\n") : printf("%.6f\n", d->age);
		printf("Owner: ");
		d->owner == NULL ? printf("(nil)\n") : printf("%s\n", d->owner);
	}
}

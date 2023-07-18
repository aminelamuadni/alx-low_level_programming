#ifndef DOG_H
#define DOG_H

/**
 * struct dog - new type
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Description: data about a dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
int _strlen(char *str);
char *_strcopy(char *dest, char *src);

#endif /* DOG_H */

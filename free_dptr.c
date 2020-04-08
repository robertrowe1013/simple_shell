#include "vrshell.h"

/**
 * free_dptr - frees all elements then the double pointer
 * @ptr: double pointer to free
 *
 * Return: void
 */
void free_dptr(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
		free(ptr[i]);

	free(ptr);
}

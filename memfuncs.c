#include "vrshell.h"
/**
  * _realloc - reallocate memory
  * @ptr: pointer
  * @old_size: size of old block
  * @new_size: size of new block
  *
  * Return: pointer, null if failed.
  */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *np;
	char *p;
	unsigned int i, n;

	if (ptr == NULL)
	{
		ptr = malloc(sizeof(char) * new_size);
		if (ptr == NULL)
		{
			free(ptr);
			return (NULL);
		}
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	np = malloc(sizeof(char) * new_size);
	if (np == NULL)
	{
		free(np);
		return (NULL);
	}
	if (new_size > old_size)
		n = old_size;
	else
		n = new_size;
	p = ptr;
	for (i = 0; i < n; i++)
		np[i] = p[i];
	free(ptr);
	p = np;
	return (p);
}
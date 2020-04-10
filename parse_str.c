#include "vrshell.h"
/**
 * parse_str - parse string based on space delimiter
 * @str: the string to parse
 * @delim: delimiter used to parse string
 *
 * Return: parsed string
 */
char **parse_str(char *str, char *delim)
{
	char *token, *clone;
	char **tok_arr;
	int words = 0, i, j, d;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (d = 0; delim[d] != '\0'; d++)
		{
			if (str[i] == delim[d])
				words++;
		}
	}
	/* malloc plus two, one for last word one for NULL pointer */
	tok_arr = malloc(sizeof(char *) * (words + 2));
	if (tok_arr == NULL)
	{
		free(str);
		perror("Out of memory");
		exit(ENOMEM);
	}
	clone = _strdup(str);
	token = strtok(clone, delim);
	free(str);
	for (j = 0; token != NULL; j++)
	{
		tok_arr[j] = _strdup(token);
		if (tok_arr[j] == NULL)
		{
			free_dptr(tok_arr);
			free(clone);
			perror("Out of memory");
			exit(ENOMEM);
		}
		token = strtok(NULL, delim);
	}
	tok_arr[j] = NULL;
	free(clone);
	return (tok_arr);
}

#include "vrshell.h"
/**
 * parse_str - parse string based on space delimiter
 * @str: the string to parse
 *
 * Return: parsed string
 */
char **parse_str(char *str, char *delim)
{
	char *token;
	char **tok_arr;
	int words, i, j;

	if (str == NULL)
		return (NULL);

	i = words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n')
			words++;
		i++;
	}
	/* malloc plus one for NULL pointer */
	tok_arr = malloc(sizeof(char *) * (words + 1));
	if (tok_arr == NULL)
	{
		free(str);
		perror("Out of memory");
		exit(ENOMEM);
	}

	token = strtok(str, delim);
	j = 0;
	while (token != NULL)
	{
		tok_arr[j] = _strdup(token);
		token = strtok(NULL, delim);
		j++;
	}
	tok_arr[j] = NULL;
	return (tok_arr);
}

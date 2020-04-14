#include "vrshell.h"
/**
 * count_words - count words based on delimiter
 * @str: the string to count
 * @delim: delimiter used to count number of words
 *
 * Return: number of words
 */
int count_words(char *str, char *delim)
{
	int wc = 0, i, j;
	int isword, isdelim;

	if (str == NULL)
		return (0);

	isword = isdelim = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[j])
			{
				if (isword)
					isdelim = 1;
				break;
			}

			if (delim[j + 1] == '\0' && (!isword && !isdelim))
				isword = 1;
		}
		if (isword && isdelim)
			wc++;
	}
	if (i == 0)
		wc = 0;
	else
		wc += 1;
	return (wc);
}

/**
 * parse_str - parse string, malloc n words
 * @str: the string to parse
 * @delim: delimter used to parse
 * @n: number of words
 *
 * Return: parsed string
 */
char **parse_str(char *str, char *delim, int n)
{
	char *token, *clone;
	char **tok_arr;
	int i;

	if (str == NULL)
		return (NULL);

	/* malloc plus one for NULL pointer */
	tok_arr = malloc(sizeof(char *) * (n + 1));
	if (tok_arr == NULL)
	{
		free(str);
		perror("Out of memory");
		exit(ENOMEM);
	}
	clone = _strdup(str);
	token = strtok(clone, delim);
	free(str);
	for (i = 0; token != NULL; i++)
	{
		tok_arr[i] = _strdup(token);
		if (tok_arr[i] == NULL)
		{
			free_dptr(tok_arr);
			free(clone);
			perror("Out of memory");
			exit(ENOMEM);
		}
		token = strtok(NULL, delim);
	}
	tok_arr[i] = NULL;
	free(clone);
	return (tok_arr);
}

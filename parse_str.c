#include "vrshell.h"
/**
 * parse_str - parse string based on space delimiter
 * @str: the string to parse
 *
 * Return: parsed string
 */
char **parse_str(char *str)
{
	const char *delim = " \n";
	char *token;
	char **tok_arr;
	int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	/* malloc one for the pointer, one for NULL*/
	tok_arr = malloc(sizeof(char *) * 2);
	if (tok_arr == NULL)
	{
		perror("malloc failed");
		exit(99);
	}

	token = malloc(sizeof(char) * (len));
	if (token == NULL)
	{
		perror("malloc failed");
		exit(99);
	}

	token = strtok(str, delim);
	tok_arr[0] = token;
	tok_arr[1] = NULL;

	return (tok_arr);
}

/**
 * _strlen - get length of string
 * @str: string to process
 *
 * Return: length of str
 */
int _strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;

	return (count);
}

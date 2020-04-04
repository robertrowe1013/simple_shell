#include "vrshell.h"
/**
 * parse_str - parse string based on space delimiter
 * @str: the string to parse
 *
 * Return: parsed string
 */
char *parse_str(char *str)
{
	char *delim = " ";
	char *token;
	int len;

	len = _strlen(str);
	token = malloc(sizeof(char) * (len + 1));
	if (token == NULL)
	{
		perror("parse_str malloc failed");
		exit(98);
	}

	token = strtok(str, delim);
	while (token != NULL)
		token = strtok(NULL, delim);

	return (token);
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

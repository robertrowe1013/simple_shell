#include "vrshell.h"
/**
 * parse_str - parse string based on space delimiter
 * @str: the string to parse
 * @n: number of chars in str
 *
 * Return: parsed string
 */
char *parse_str(char *str, int n)
{
	char *delim = " ";
	char *token;

	token = malloc(sizeof(char) * n);
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

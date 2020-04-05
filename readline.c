#include "vrshell.h"
/**
 * read_line - reads input from stdin
 *
 * Return: number of characters read
 */
char *read_line(void)
{
	int chars_read;
	char *buffer;
	size_t BUF_SIZE = 1024;

	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (buffer == NULL)
	{
		perror("read_line malloc failed");
		exit(98);
	}

	chars_read = getline(&buffer, &BUF_SIZE, stdin);
	if (chars_read == -1)
	{
		perror("logout");
		exit(98);
	}
	return (buffer);
}

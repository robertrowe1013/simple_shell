#include "vrshell.h"
/**
 * read_line - reads input from stdin
 *
 * Return: number of characters read
 */
int read_line(void)
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

	return (chars_read);
}

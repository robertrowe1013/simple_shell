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
		perror("Out of memory");
		exit(ENOMEM);
	}

	chars_read = getline(&buffer, &BUF_SIZE, stdin);
	if (chars_read == -1)
	{
		free(buffer);
		write(STDOUT_FILENO, "logout\n", 8);
		exit(0);
	}
	return (buffer);
}

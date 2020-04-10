#include "vrshell.h"
/**
 * read_line - reads input from stdin
 *
 * Return: number of characters read
 */
char *read_line(void)
{
	int chars_read;
	char *buffer = NULL;
	size_t buf_size = 0;

	chars_read = getline(&buffer, &buf_size, stdin);
	if (chars_read == -1)
	{
		free(buffer);
		write(STDOUT_FILENO, "logout\n", 8);
		exit(0);
	}
	buffer[chars_read - 1] = '\0';
	if (_strncmp(buffer, "exit", 4) == 0)
	{
		free(buffer);
		write(STDOUT_FILENO, "logout\n", 8);
		exit(0);
	}
	return (buffer);
}

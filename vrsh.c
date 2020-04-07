#include "vrshell.h"

/**
  * main - simple shell
  *
  * Return: 0
  */
int main(void)
{
	int status = 1;
	char *prompt = "$ ";
	char *arg;
	char **tokens;

	while (status)
	{
		write(STDOUT_FILENO, prompt, 2);
		arg = read_line();
		tokens = parse_str(arg);
		status = executearg(tokens);
		free(tokens);
		free(arg);
	}
	return (0);
}

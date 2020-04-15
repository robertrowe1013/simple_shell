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
	int wc = 0;
	int bi;

	while (status)
	{
		if (isatty(0))
			write(STDOUT_FILENO, prompt, 2);
		else
			status = 0;
		arg = read_line();
		if (arg[0] == '\0')
		{
			free(arg);
			continue;
		}
		wc = count_words(arg, " ");
		tokens = parse_str(arg, " ", wc);
		bi = checkbi(tokens);
		if (bi == 0)
			status = runbi(tokens);
		else
			status = executearg(tokens);
	}
	return (0);
}

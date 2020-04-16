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
	int wc = 0, counter = 0;
	int bi, errstatus = 0;
	char *shell, *cmd;

	while (status)
	{
		if (isatty(0))
			write(STDOUT_FILENO, prompt, 2);
		arg = read_line(errstatus);
		wc = count_words(arg, " ");
		if (wc == 0)
		{
			free(arg);
			counter++;
			continue;
		}
		tokens = parse_str(arg, " ", wc);
		cmd = _strdup(tokens[0]);
		bi = checkbi(tokens);
		if (bi == 0)
		{
			status = runbi(tokens);
			if (status == 1)
				errstatus = 0;
		}
		else
			errstatus = executearg(tokens);
		counter++;
		if (errstatus == 127)
		{
			shell = _getenv("_");
			badcom(shell, counter, cmd);
			free(shell);
		}
		free(cmd);
	}
	return (errstatus);
}

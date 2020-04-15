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
	int bi;
	char *shell, *cmd;

	while (status)
	{
		write(STDOUT_FILENO, prompt, 2);
		arg = read_line(status);
		if (arg[0] == '\0')
		{
			free(arg);
			counter++;
			continue;
		}
		wc = count_words(arg, " ");
		tokens = parse_str(arg, " ", wc);
		cmd = _strdup(tokens[0]);
		bi = checkbi(tokens);
		if (bi == 0)
			status = runbi(tokens);
		else
			status = executearg(tokens);
		counter++;
		if (status == 127)
		{
			shell = _getenv("_");
			badcom(shell, counter, cmd);
			free(shell);
			free(cmd);
		}
	}
	return (0);
}

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
	char *arg, *cmd;
	char **tokens;
	int bi, wc = 0, counter = 0, errstatus = 0;

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
		{
			errstatus = executearg(tokens);
			free_dptr(tokens);
		}
		counter++;
		if (errstatus > 1)
		{
			badcom(errstatus, counter, cmd);
		}
		free(cmd);
	}
	return (errstatus);
}

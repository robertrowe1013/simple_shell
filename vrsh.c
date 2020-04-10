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
		write(STDOUT_FILENO, prompt, 2);
		arg = read_line();
		wc = count_words(arg, " \n");
		tokens = parse_str(arg, " \n", wc);
		bi = checkbi(tokens);
		if (bi == 0)
			status = runbi(tokens);
		else
			status = executearg(tokens);
		free(tokens);
		/*free(arg);*/
	}
	return (0);
}

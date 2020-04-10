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
	int i = 0;
	int j = 0;

	while (status)
	{
		write(STDOUT_FILENO, prompt, 2);
		arg = read_line();
		if (_strncmp(arg, "env", 3) == 0)
		{
			while (environ[i] != NULL)
			{
				while (environ[i][j] != '\0')
				{
					_putchar(environ[i][j]);
					j++;
				}
				_putchar('\n');
				i++;
				j = 0;
			}
		}
		else 
		{
			tokens = parse_str(arg, " \n");
			status = executearg(tokens);
			free(tokens);
			free(arg);
		}
	}
	return (0);
}

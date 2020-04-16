
#include "vrshell.h"
/**
  * executearg - execute argument
  * @arg: argument to execute
  *
  * Return: 0
  */

int executearg(char **arg)
{
	pid_t c_pid, pid;
	int status, ac;

	arg = pathfinder(arg);
	if (arg[0] == NULL)
	{
		free_dptr(arg);
		return (127);
	}
	ac = access(arg[0], X_OK);
	if (ac != 0)
	{
		free_dptr(arg);
		return (126);
	}
	c_pid = fork();
	if (c_pid == 0)
	{
		execve(arg[0], arg, NULL);
		free_dptr(arg);
		perror("execve failed");
		exit(98);
	}
	else if (c_pid > 0)
	{
		pid = waitpid(c_pid, &status, WUNTRACED);
		if (pid < 0)
		{
			free_dptr(arg);
			perror("wait");
			exit(98);
		}
	}
	else
	{
		free_dptr(arg);
		perror("fork failed");
		exit(98);
	}
	free_dptr(arg);
	return (0);
}

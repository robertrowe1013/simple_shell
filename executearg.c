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
	int status;
	char **path_array;
	struct stat stats;

	path_array = _paths();
	arg[0] = _finder(path_array, arg[0]);
	c_pid = fork();
	if (c_pid == 0)
	{
		if (stat(arg[0], &stats) == -1)
		{
			perror("./vrsh");
			exit(127);
		}
		execve(arg[0], arg, NULL);
		perror("execve failed");
		exit(98);
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
		if (pid < 0)
		{
			perror("wait");
			exit(98);
		}
	}
	else
	{
		perror("fork failed");
		exit(98);
	}
	return (1);
}

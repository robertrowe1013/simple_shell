
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
	int status, fd;
	char **path_array;

	if (arg[0][0] != '/')
	{
		path_array = _paths();
		arg[0] = _finder(path_array, arg[0]);
		free_dptr(path_array);
	}
	fd = access(arg[0], X_OK);
	c_pid = fork();
	if (c_pid == 0)
	{
		if (fd == -1)
		{
			free_dptr(arg);
			perror("./vrsh");
			exit(127);
		}
		execve(arg[0], arg, NULL);
		free_dptr(arg);
		perror("execve failed");
		exit(98);
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
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
	return (1);
}

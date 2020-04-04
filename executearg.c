#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

	c_pid = fork();
	if (c_pid == 0)
	{
		execve(arg[0], arg, NULL);
		perror("execve failed");
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
	return (0);
}

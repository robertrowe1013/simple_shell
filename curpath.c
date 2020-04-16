#include "vrshell.h"
/**
 * pstart - run command in current working directory
 * @cmd: the command to run
 *
 * Return: cwd with command appended
 */
char *pstart(char *cmd)
{
	int len_cwd, len_cmd, new_len;
	char *cwd;

	cwd = getcwd(NULL, 0);
	len_cwd = _strlen(cwd);
	len_cmd = _strlen(cmd);
	new_len = len_cwd + len_cmd;
	cwd = _realloc(cwd, len_cwd, (new_len + 2));
	_strcat(cwd, "/");
	_strcat(cwd, cmd);
	
	if (access(cwd, F_OK) != 0)
		return (NULL);

	return (cwd);
}
/**
 * pend - append current working directory to end of PATH
 *
 * Return: PATH with command appended
 */
char *pend()
{
	char *path;
	int len_path, len_cwd, new_len;
	char *cwd = NULL;

	path = _getenv("PATH");

	len_path = _strlen(path);
	if (path[len_path - 1] == ':')
	{
		cwd = getcwd(NULL, 0);
		len_cwd = _strlen(cwd);
		new_len = len_path + len_cwd;
		path = _realloc(path, len_path, (new_len + 1));
		_strcat(path, cwd);
	}
	if (cwd != NULL)
        	free(cwd);
	return (path);
}

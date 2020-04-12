#include "vrshell.h"
/**
 * _getenv - get environment variable
 * @name: string to search through
 *
 * Return: environment variable
 */
char *_getenv(const char *name)
{
	char *new_name, *env;
	int i, len_name, len_env, len_new_name;

	len_name = _strlen((char *)name);
	/* Plus two accounts for = and \0 */
	new_name = malloc(sizeof(char) * (len_name + 2));
	if (new_name == NULL)
	{
		perror("Out of memory");
		exit(ENOMEM);
	}

	_strncpy(new_name, (char *)name, 0, len_name);
	_strcat(new_name, "=");

	len_new_name = _strlen(new_name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(new_name, environ[i], len_new_name) == 0)
			break;
	}

	free(new_name);
	/* Returns NULL if name not found */
	if (environ[i] == NULL)
		return (NULL);

	len_env = _strlen(environ[i]);
	env = malloc(sizeof(char) * (len_env - len_name + 1));
	if (env == NULL)
	{
		perror("Out of memory");
		exit(ENOMEM);
	}

	_strncpy(env, environ[i], len_new_name, (len_env - len_name));
	return (env);
}
/**
  * pathfinder - finds which path to use
  * @arg: arg array
  *
  * Return: arg array
  */
char **pathfinder(char **arg)
{
	char **path_array;

	if (arg[0][0] != '/')
	{
		path_array = _paths();
		if (path_array[0] == NULL)
			return (arg);
		arg[0] = _finder(path_array, arg[0]);
		free_dptr(path_array);
	}
	return (arg);
}

/**
  * _paths - turns path env to string array
  *
  * Return: Path array
  */
char **_paths(void)
{

	char *allpaths;
	char **path_array;
	int wc = 0;

	allpaths = _getenv("PATH");
	wc = count_words(allpaths, ":");
	if (wc == 0)
	{
		path_array = malloc(sizeof(char *));
		path_array[0] = NULL;
	}
	else
		path_array = parse_str(allpaths, ":", wc);
	return (path_array);
}
/**
  * _finder - finds valid path name
  * @paths: array of paths
  * @cmd: command or executable filename
  *
  * Return: full path for file
  */
char *_finder(char **paths, char *cmd)
{
	int i = 0;
	int path_len, cmd_len;
	char *testpath;

	if (paths == NULL || paths[i] == NULL)
		return (cmd);
	while (paths[i] != NULL)
	{
		path_len = _strlen(paths[i]);
		testpath = malloc(sizeof(char) * (path_len + 1));
		_strncpy(testpath, paths[i], 0, path_len);
		cmd_len = _strlen(cmd);
		testpath = _realloc(testpath, path_len, (path_len + cmd_len + 2));
		_strcat(testpath, "/");
		_strcat(testpath, cmd);
		if (access(testpath, X_OK) == 0)
		{
			break;
		}
		free(testpath);
		i++;
	}
	free(cmd);
	return (testpath);
}

#include "vrshell.h"
/**
  * _paths - turns path env to string array
  *
  * Return: Path array
  */
char **_paths(void)
{

	char *allpaths;
	char **path_array;

	allpaths = _getenv("PATH");
	path_array = parse_str(allpaths, ":");
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
	struct stat stats;

	while (paths[i] != NULL)
	{
		path_len = _strlen(paths[i]);
		testpath = malloc(sizeof(char) * (path_len + 1));
		_strncpy(testpath, paths[i], 0, path_len);
		cmd_len = _strlen(cmd);
		testpath = _realloc(testpath, path_len, (path_len + cmd_len + 2));
		_strcat(testpath, "/");
		_strcat(testpath, cmd);
		if (stat(testpath, &stats) == 0)
		{
			break;
		}
		i++;
	}
	return (testpath);
}

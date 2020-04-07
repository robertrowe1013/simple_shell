#include "vrshell.h"
/**
  * _paths - turns path env to string array
  *
  * Return: Path array
  */
char **_paths(void)
{

	char *allpaths;
	int len;
	int i = 0;
	int paths = 1;
	char *token;
	char **path_array;

	allpaths = _getenv("PATH");
	len = _strlen(allpaths);
	for (i = 0; i < len; i++)
	{
		if (allpaths[i] == ':')
			paths++;
	}
	path_array = malloc(sizeof(char *) * paths);
	token = strtok(allpaths, ":");
	for (i = 0; token != NULL; i++)
	{
		len = _strlen(token);
		path_array[i] = malloc(sizeof(char) * len);
		path_array[i] = token;
		token = strtok(NULL, ":");
	}
	free(allpaths);
	return (path_array);
}

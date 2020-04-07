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
	new_name = malloc(sizeof(char) * (len_name + 2));
	_strncpy(new_name, (char *)name, 0, len_name);
	_strcat(new_name, "=");
	len_new_name = _strlen(new_name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(new_name, environ[i], len_new_name) == 0)
			break;
	}

	len_env = _strlen(environ[i]);
	env = malloc(sizeof(char) * (len_env - len_name));
	_strncpy(env, environ[i], len_new_name, len_env);

	return (env);
}

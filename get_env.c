#include "main.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len = _strlen2(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (&(*env)[len + 1]);
		}
	}

	return (NULL);
}

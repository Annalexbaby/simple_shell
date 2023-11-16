#include "main.h"

/**
 * set_env - Set the value of an environment variable
 * @arg: name and value of the environment variable
 *
 * Return: Nothing
 */
int set_env(char **arg)
{
	char *name, *value;

	if (arg[1] == NULL || arg[2] == NULL)
	{
		print_error("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = arg[1];
	value = arg[2];

	if (setenv(name, value, 1) != 0)
	{
		print_error("setenv");
		return (-1);
	}
	return (0);
}

/**
 * unset_env - Unset an environment variable
 * @arg: name of the environment variable
 *
 * Return: Nothing
 */
int unset_env(char **arg)
{
	char *name;

	if (arg[1] == NULL)
	{
		print_error("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = arg[1];

	if (unsetenv(name) != 0)
	{
		print_error("unsetenv");
	}
	return (0);
}

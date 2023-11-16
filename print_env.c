#include "main.h"

/**
 * all_env - Prints all the environment variables.
 *
 * Return: void.
 */
int all_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		print_message("\n");
	}

	return (0);
}

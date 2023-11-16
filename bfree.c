#include "main.h"

/**
 * free_tokens - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
 * free_path - Frees the global variable containing the PATH environment
 *              variable value
 *
 * Return: Nothing
 */
void free_path(void)
{
	if (environ != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}

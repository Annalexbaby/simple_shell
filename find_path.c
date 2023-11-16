#include "main.h"

/**
 *find_path - The PATH been searched for
 *@command: The argument
 *Return: Nothing
 */

void find_path(const char *command)
{
	char *token;
	char full_path[250];

	char *path = getenv("PATH");

	if (path == NULL)
	{
		print_error("PATH environment variable not set.\n");

	return;
	}

		token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

	if (access(full_path, F_OK) == 0)
	{
		printf("Command '%s' found in: %s\n", command, token);
	return;
	}

	token = strtok(NULL, ":");
	}

		printf("Command '%s' not found in PATH.\n", command);
}

#include"main.h"

/**
 * read_cmd - reads commands
 * @cmd:command to be rread
 * @n:size of command space
 *
 * Return:0
 */
void read_cmd(char *cmd, size_t n)
{
	size_t length;
	length = 0;
	if (getline(&cmd, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			print_message("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("ERROR");
			exit(EXIT_FAILURE);
		}
	}
	length = _strlen(cmd);
	if (length > 0 && cmd[length - 1] == '\n')
	{
		cmd[length - 1] = '\0';
	}
}
/**
 * exe_cmd - executes commands
 * @cmd:command to be executed
 *
 * Return:0
 */
int exe_cmd(const char *cmd)
{
	int status;
	char *argv[] = {"/bin/sh", "-c", NULL, NULL};
	char *const envp[] = {NULL};

	pid_t child_p = fork();

	argv[2] = (char *) cmd;

	if (child_p == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_p == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("execve:");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
		exit (status);
	}
	return (0);
}

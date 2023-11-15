#include"main.h"

/**
 * main - run the shell program
 * @argc:argument count
 * @argv:argument vector
 *
 * Return:0
 */
int main(int argc, char **argv)
{
	char cmd[120];
	char *delim;

	delim = " \n";
	signal(SIGINT, sigint_handler);

	(void)argc;
	(void)argv;
	do {
		display_prompt();
		read_cmd(cmd, sizeof(cmd));
		tokenizer(cmd, delim);
		exe_cmd(cmd);

	} while (1);

	return (0);
}

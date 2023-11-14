#include"main.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	char cmd[150];
	char *delim;

	delim = " \n";
	signal(SIGINT, sigint_handler);

	(void)argc;
	(void)argv;
        do {
		display_prompt();
		tokenizer(cmd, delim);
		read_cmd(cmd, sizeof(cmd));
		exe_cmd(cmd);
	} while(1);

	return(0);
}

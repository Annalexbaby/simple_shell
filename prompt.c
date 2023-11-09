#include "main.h"



void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "GT$ ", strlen("GT$ "));
}

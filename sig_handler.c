#include "main.h"

/**
 * sigint_handler - handle signals
 * @signal: the signal
 *
 * Return: nothing
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		print_message("\n");
		display_prompt();
	}
}

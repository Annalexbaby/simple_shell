#include "main.h"
/**
 * display_prompt - displays prompt to screen
 *
 * Return:0
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$", _strlen2("$"));
}

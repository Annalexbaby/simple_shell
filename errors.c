#include "main.h"

/**
 * _puts - Prints a string to the standard output stream
 * @str: The string to print
 *
 * Return: Void
 */
void _puts(char *str)
{
	size_t len;
	ssize_t written_nums;

	len = _strlen(str);
	written_nums = write(STDOUT_FILENO, str, len);
	if (written_nums == -1)
	{
		perror("write");
	}
}

/**
 * print_error - Prints an error message to the standard error stream
 * @err: The error message to print
 *
 * Return: Void
 */
void print_error(char *err)
{
	size_t len;
	ssize_t written_nums;

	len = _strlen(err);
	written_nums = write(STDERR_FILENO, err, len);
	if (written_nums == -1)
	{
		perror("write");
	}
}

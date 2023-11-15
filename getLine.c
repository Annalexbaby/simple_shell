#include "main.h"

/**
 * get_line - Reads input from the stdin
 *
 * Return: The user input
 */

char *get_line()
{
	static char buffer[BUFFER_SIZE];
	static size_t buf_index;
	static size_t buf_size;
	size_t i, start, length;
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
	if (buf_index >= buf_size)
	{
		buf_size = fread(buffer, 1, BUFFER_SIZE, stdin);
		if (buf_size == 0)
		{
		if (line_size > 0)
		{
			return (line);
		}
		else
		{
			return (NULL);
		}
	}
	buf_index = 0;
	start = buf_index;
	while (buf_index < buf_size && buffer[buf_index] != '\n')
		buf_index++;
	length = buf_index - start;
	line = realloc(line, line_size + length + 1);
	for (i = 0; i < length; i++)
		line[line_size + i] = buffer[start + i];
	line_size += length;
	line[line_size] = '\0';
	buf_index++;

	if (buffer[buf_index - 1] == '\n')
	return (line);
	}
	}
}

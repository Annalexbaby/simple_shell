#include "main.h"

/**
 * tokenizer - splits user's inputed commands into a string of tokens
 * @cmd: the string to be tokenized
 * @delim: delimiter value
 *
 * Return: Number of tokens found.
*/
int tokenizer(char *cmd, char *delim)
{
	int token_count;
	char *token;

	token = strtok(cmd, delim);
	token_count = 1;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		token_count++;
	}
	return (token_count);
}

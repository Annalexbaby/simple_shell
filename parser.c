#include "main.h"

/**
 * tokenizer - splits user's inputed commands into a string of tokens
 * @cmd: the string to be tokenized
 * @delim: the delimiter
 *
 * Return: Number of tokens found.
*/
char **tokenizer(char *cmd, char *delim)
{
    int token_count = 0;
    char *token;
    char **tokens = NULL;

    token = strtok(cmd, delim);
    while (token != NULL)
    {
        tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
        if (tokens == NULL)
        {
            _puts("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        tokens[token_count] = strdup(token);
        if (tokens[token_count] == NULL)
        {
            _puts("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, delim);
        token_count++;
    }

    tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        _puts("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    tokens[token_count] = NULL;

    return (tokens);
}

/**
 * tokenizer - parses user input into words
 *            by splitting an array string into tokens using a delimiter.
 * @cmd: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 *
 * Return: an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **array_maker(char *str, const char *delim)
{
    char *token = strtok(str, delim);
    char **temp, **ret = NULL;
    int j, i = 0;

    while (token)
    {
        temp = realloc(ret, (i + 1) * sizeof(char *));
        if (temp == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(ret[j]);
            }
            free(ret);
            return (NULL);
        }

        ret = temp;

        ret[i] = strdup(token);
        if (ret[i] == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(ret[j]);
            }
            free(ret);
            return (NULL);
        }

        token = strtok(NULL, delim);
        i++;
    }

    temp = realloc(ret, (i + 1) * sizeof(char *));
    if (temp == NULL)
    {
        for (j = 0; j < i; j++)
        {
            free(ret[j]);
        }
        free(ret);
        return (NULL);
    }

    ret = temp;

    ret[i] = NULL;
    return (ret);
}

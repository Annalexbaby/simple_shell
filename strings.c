#include "main.h"
#include<unistd.h>
#include<stdio.h>
/**
 * _strlen2 - length of string
 * @s:string to be caluclated
 *
 * Return:0
 */
int _strlen2(const char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
	}
	return (a);
}
/**
 * print_message - print message on screen
 * @command:command to be printed
 *
 */
void print_message(const char *command)
{
	write(STDOUT_FILENO, command, _strlen2(command));
}

/**
 * _strspn - count the number of strings at a string
 * @s:string to be calculated
 * @accept:seacrh throuhg s
 *
 * Return:0
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}
/**
 * _strlen - count the length of string
 * @s:string to be counted
 *
 * Return:0
 */
int _strlen(char *s)
{
	int a;

	for (a = 0;  s[a] != '\0'; a++)
	{
	}
	return (a);
}

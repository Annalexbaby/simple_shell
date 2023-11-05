#include"main.h"
#include<unistd.h>
/**
 * _putchar - prints a characer to stdout
 * @c:character to be printed
 *
 * Return:0
 */
int _putchar(char c)
{
        return(write(1, &c, 1));
}
/**
 * _puts - prints out a string
 * @string:string to be printed
 *
 * Return:0
 */
void _puts(char *string)
{
        while(*string != '\0')
        {
                _putchar(*string);
                string++;
        }
        _putchar('\n');
}
/**
 * str_len-calculate length of string
 * @s:string to be calculated
 * Return:0
 */
int str_len(char *s)
{
        int A;
        for(A= 0; s[A] != '\0'; A++)
        {
        }
        return(A);
}

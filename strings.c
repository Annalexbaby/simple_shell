#include "main.h"
#include<unistd.h>
#include<stdio.h>

int _strlen2(const char *s)
{
        int a;
        for(a = 0; s[a]!= '\0'; a++)
        {
        }
        return(a);
}

void print_message(const char * command)
{
              write(STDOUT_FILENO, command, _strlen2(command));
}

int _strspn(char *s, char *accept)
{
        int bytes = 0;
        int index;
        while(*s)
        {
                for(index= 0; accept[index]; index++)
                {
                        if(*s == accept[index])
                        {
                                bytes++;
                                break;
                        }
                }
                s++;
        }
        return(bytes);
}
int _strlen(char *s)
{
        int a;
        for(a = 0;  s[a] != '\0'; a++)
        {
        }
        return(a);
}

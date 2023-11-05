#include"main.h"
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main(void)
{
        char *pointer_to_n;
        char *prompt = "$";
        size_t n = 0;
        do{
        _puts(prompt);
        if(getline(&pointer_to_n, &n, stdin)== -1)
        {
                break;
        }
        _puts(pointer_to_n);
        } while(1);
        free(pointer_to_n);
        return(0);
}


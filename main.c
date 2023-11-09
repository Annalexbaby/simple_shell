#include"main.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        char cmd[120];
        do
        {
		display_prompt();
                read_cmd(cmd, sizeof(cmd));
                exe_cmd(cmd);
        }while(1);
        return(0);
}

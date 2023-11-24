#include"shell.h"
#include<stdio.h>
int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		execute2(argv, envp);
	}
	return(0);
}

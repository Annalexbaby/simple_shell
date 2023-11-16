#include "main.h"

void exit_command(const char *arg) 
{
    if (arg != NULL) {
        int status = atoi(arg);
        exit(status);
    } else {
        exit(0);
    }
}


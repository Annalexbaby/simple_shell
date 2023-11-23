#include"shell.h"
#include<stdio.h>
#include<stdlib.h>
#include"shell.h"
#include<stdio.h>
#include<stdlib.h>
void execute(char **av, char **env) 
{
    char *input;
    size_t n;
    int i;
    ssize_t value;
    int status;
    char *array[] = {NULL, NULL};
    pid_t child;

    (void)av;
    input = NULL;
    n = 0;

    do {
        if (isatty(STDIN_FILENO)) {
            printf("#cisfun\n");
        }

        value = getline(&input, &n, stdin);

        if (value == -1) {
            free(input);
            exit(EXIT_FAILURE);
        }

        for (i = 0; input[i] != '\0'; i++) {
            if (input[i] == '\n') {
                input[i] = '\0';
            }
        }

        array[0] = input;

        child = fork();

        if (child == -1) {
            free(input);
            exit(EXIT_FAILURE);
        }

        if (child == 0) {
            if (execve(array[0], array, env) == -1) {
                printf("%s: no such file or directory", array[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&status);
        }
    } while (1);
}


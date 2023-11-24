#include"shell.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void execute2(char **av, char **env) {
    char *input;
    int stdout_pipe[2];
    int stderr_pipe[2];
    size_t n;
    int i;
    char buffer[4096];
            ssize_t bytesRead;
    ssize_t value;
    int status;
    char *array[] = {NULL, NULL};
    pid_t child;

    (void)av;
    (void)env;
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

        if (pipe(stdout_pipe) == -1 || pipe(stderr_pipe) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        child = fork();

        if (child == -1) {
            perror("fork");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (child == 0) {
            close(stdout_pipe[0]);
            close(stderr_pipe[0]);
            dup2(stdout_pipe[1], STDOUT_FILENO);
            dup2(stderr_pipe[1], STDERR_FILENO);
            close(stdout_pipe[1]);
            close(stderr_pipe[1]);

            if (execvp(array[0], array) == -1) {
                perror(array[0]);
                exit(EXIT_FAILURE);
            }
        } else { 
            close(stdout_pipe[1]);
            close(stderr_pipe[1]);

            printf("(stdout)");
            while ((bytesRead = read(stdout_pipe[0], buffer, sizeof(buffer))) > 0) {
                write(STDOUT_FILENO, buffer, bytesRead);
            }
            printf("(Length: %ld)\n", bytesRead);

            printf("(stderr)");
            while ((bytesRead = read(stderr_pipe[0], buffer, sizeof(buffer))) > 0) {
                write(STDOUT_FILENO, buffer, bytesRead);
            }
            printf("(Length: %ld)\n", bytesRead);

            close(stdout_pipe[0]);
            close(stderr_pipe[0]);

            waitpid(child, &status, 0);
            printf("(status)[%d]\n", WEXITSTATUS(status));
        }
    } while (1);
}

/**
*
* int main(int argc, char **argv, char **envp) {
    if (argc == 1) {
        execute(argv, envp);
    }
    return 0;
}
*/



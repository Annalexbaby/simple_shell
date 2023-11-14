#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define BUFFER_SIZE 1024

void display_prompt(void);
void print_message(const char *command);
int _strspn(char *s, char *accept);
int _strlen(char *s);
int _strlen2(const char *s);
int tokenizer(char *cmd, char *delim);
int exe_cmd(const char *cmd);
void read_cmd(char *cmd, size_t n);
void sigint_handler(int signal);
char* get_line();

#endif

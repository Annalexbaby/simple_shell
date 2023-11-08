#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void print_message(const char * prompt);
int _strspn(char *s, char *accept);
int _strlen(char *s);
int _strlen2(const char *s);
void exe_cmd(const char *cmd);
void read_cmd(char *cmd, size_t n);
#endif

#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

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
int exe_cmd(char *cmd);
void read_cmd(char *cmd, size_t n);
void sigint_handler(int signal);
char *get_line();
void exit_command(const char *arg);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);
char **tokenizer(char *cmd, char *delim);
char **array_maker(char *cmd, const char *delim);
void free_tokens(char **p);
void _puts(char *str);
void print_error(char *err);
void find_path(const char *command);
void free_tokens(char **tokens);
char *_getenv(const char *name);
int unset_env(char **arg);
int set_env(char **arg);
int all_env(void);

#endif

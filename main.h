#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void cleanup(char **args, char **PATH);
char **arg_vector(char *line);
void start_shell(char *programName, int count, int interactive);
int  fileorpath(char *s);
int check_command(char **args, char **PATH, int exitstatus, int c, char *pN);
int run_command(char **command_args, char *env[], char *path);
void exitfunction(char **args, char *PATH, int exitstatus, int c, char *pN);
void printenv(void);
int builtin(char **args, char *PATH, int exitstatus, int count, char *pN);
int getPath(char **args, char **PATH);



void intToString(int num, char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _isdigit(int c);
int isnumber(char *s);
int _atoi(char *s);

#endif

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h> /*<strtok>*/
#include <ctype.h>

extern char **environ;
/*Prototypes*/
void _execve(char *path, char **argv, char **envp);
char *_getenv(char *name);
char **tokenize(char *buffer);
char *path_check(char *command);
char **duplicate_environ();
void free_environ(char **environ);


/*Auxiliar Prototypes*/
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int checker_spaces(char *buffer);


#endif

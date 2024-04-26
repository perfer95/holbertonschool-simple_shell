#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h> /*<strtok>*/


/*Prototypes*/
void _execve(char *path, char **argv, char **envp);


/*Auxiliar Prototypes*/
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);


#endif

#include "header.h"

/**
 * _execve - function that execute the comands
 * @path: variable for the command
 * @argv: arguments for the new procces
 * @envp: enviroment variables
 * Return: empty
 */
void _execve(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
	{
		perror("Error with execve");
		exit(1);
	}
}

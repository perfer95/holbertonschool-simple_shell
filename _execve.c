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
	/*execve no print*/
	int fd;

	fd = open("/dev/null", O_WRONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDERR_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	/*execve no print*/
	if (execve(path, argv, envp) == -1)
	{
		perror("Error with execve");
		exit(1);
	}
}

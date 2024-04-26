#include "simple_shell.h"

/**
 * main - principal script for simple shell
 * Return: empty
 */
int main(void)
{
	char *buffer = NULL, *token;
	size_t buffer_size = 0;
	char **arr_token;
	pid_t child_pid;
	int i = 0, status;

	while (i == 0)
	{
		write(1, "$ ", 2);
		getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		arr_token = malloc(sizeof(char *) * 1024);
		while (token != NULL)
		{
			arr_token[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		arr_token[i] = NULL;
		if (_strcmp(arr_token[0], "^D") == 0)
			return (0);
		child_pid = fork(); /*Print error -1*/
		if (child_pid == -1)
		{
			perror("Error in FORK");
			exit(1);
		}
		if (child_pid == 0)
			_execve(arr_token[0], arr_token, NULL);
		else
			wait(&status);
		i = 0;
		free(arr_token);
	}
	return (0);
}

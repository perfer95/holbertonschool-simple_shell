#include "header.h"

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
	int i = 0, status, checker_EOF;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);
		checker_EOF = getline(&buffer, &buffer_size, stdin);/*checker_EOF*/
		if (checker_EOF == -1 && buffer != NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			break;
		}
		if (checker_spaces(buffer) == 1)
		{
			continue;
		}
		token = strtok(buffer, " \t\n");
		arr_token = malloc(sizeof(char *) * 1024);
		if (arr_token == NULL)
		{
			perror("Malloc fail");
			exit(1);
		}
		while (token != NULL)
		{
			arr_token[i++] = token;
			token = strtok(NULL, " \t\n");
		}
		arr_token[i] = NULL;
		child_pid = fork(); /*Print error -1*/
		if (child_pid == -1)
		{
			perror("Error in FORK");
			exit(1);
		}
		if (child_pid == 0)
		{
			_execve(arr_token[0], arr_token, NULL);
		}
		else
			wait(&status);
		i = 0;
		free(arr_token);
	}
	free(buffer);
	return (0);
}

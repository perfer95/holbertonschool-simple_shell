#include "header.h"

/**
 * main - principal script for simple shell
 * Return: empty
 */
int main(void)
{
	char *buffer = NULL, *dir, **arr_token;
	size_t buffer_size = 0;
	pid_t child_pid;
	int status, checker_EOF;

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
			continue;
		arr_token = tokenize(buffer);
		dir = path_check(arr_token[0]);
		if (dir == NULL)
		{
			/*write(1, "not found\n", 10);*/
			continue;
		}
		else
		{
			child_pid = fork(); /*Print error -1*/
			if (child_pid == -1)
			{
				perror("Error in FORK");
				exit(1);
			}
			if (child_pid == 0)
				_execve(dir, arr_token, NULL);
			else
				wait(&status);
		}
		free(arr_token);
		free(dir);
	}
	free(buffer);
	return (0);
}

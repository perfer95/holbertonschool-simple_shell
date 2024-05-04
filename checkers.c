#include "header.h"


/**
 * path_check - funtion to verify if there are direction for command in path.
 * @command: comand to veryfy
 * Return: NULL if dont exist and char * with the direction.
 */
char *path_check(char *command)
{
	char *path, path_cp, dir, full_path;

	if (access(command, F_OK) == 0)
		return (strdup(command));
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_cp = strdup(path); /*duplicate*/

	free(path);

	if (path_cp == NULL)
	{
		perror("strdup");
		exit(1);
	}
	dir = strtok(path_cp, ":");
	full_path = malloc(strlen(dir) + strlen(command) + 2);/*strlen*/

	if (full_path == NULL)
	{
		perror("Malloc fail");
		exit(1);
	}

	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_cp); /*Don forget free full_path in main*/
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(path_cp);
	free(full_path);
	return (NULL);
}


/**
 * checker_spaces - varify if in a string there are onli spaces.
 * @buffer: string to check.
 * Return: 0 for no only spaces and 1 for all are spaces
 */
int checker_spaces(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\n')
		{
			return (0);
		}
	}
	return (1);
}

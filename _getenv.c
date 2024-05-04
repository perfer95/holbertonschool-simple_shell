#include "header.h"

/**
 * _getenv - function that duplicate and get enviroment variables
 * @name: variable name
 * Return: a char pointer
 */
char *_getenv(char *name)
{
	int i = 0;
	char *token;
	char *val;
	char **environ_2 = duplicate_environ();

	while (environ_2[i] != NULL)
	{
		token = strtok(environ_2[i], "=");
		if (_strcmp(token, name) == 0 || strcmp(environ_2[i], name) == 0)
		{
			val = strdup(strtok(NULL, "="));
			free_environ(environ_2);
			return (val);
		}
		i++;
	}
	return (NULL);
}

/**
 * duplicate_environ - function that duplicate environ variables
 * Return: a copy of environ
 */
char **duplicate_environ()
{
	int env_count = 0, i;
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		env_count++;
		env_ptr++;
	}
	char **new_environ = malloc((env_count + 1) * sizeof(char *));

	if (new_environ == NULL)
	{
		perror("malloc");
		exit(1);
	}

	/*Copy each element*/
	for (i = 0; i < env_count; i++)
	{
		new_environ[i] = strdup(environ[i]);
		if (new_environ[i] == NULL)
		{
			perror("strdup");
			exit(1);
		}
	}

	/*Finish null*/
	new_environ[env_count] = NULL;

	return (new_environ);
}


/**
 * free_environ - Function to free de new environ varibale
 * @environ: variable to free
 * Return: void
 */
void free_environ(char **environ)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		free(environ[i]);
	}
	free(environ);
}

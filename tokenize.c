#include "header.h"

/**
 * tokenize - Funtion to tokenize
 * @buffer: string to tokenize
 * Return: double pointer with the result
 */
char **tokenize(char *buffer)
{
	char *token;
	char **arr_token_f;
	int i = 0;

	token = strtok(buffer, " \t\n");
	arr_token_f = malloc(sizeof(char *) * 1024);
	if (arr_token_f == NULL)
	{
		perror("Malloc fail");
		exit(1);
	}

	while (token != NULL)
	{
		arr_token_f[i++] = token;
		token = strtok(NULL, " \t\n");
	}

	arr_token_f[i] = NULL;

	return (arr_token_f);
}

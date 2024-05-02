#include "header.h"

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

#include "header.h"

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

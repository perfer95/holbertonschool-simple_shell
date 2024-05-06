#include "header.h"

/**
 * print_env - function to print the actual enviroment
 * Return: void
 */
void print_env(void)
{
	int fd, i;
	char buffer[4096];
	ssize_t bytes_read;

	fd = open("/proc/self/environ", O_RDONLY);
	if (fd == -1)
	{
		perror("Error to open /proc/self/environ");
		exit(1);
	}

	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		for (i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\0')
				buffer[i] = '\n';
		}
		write(STDOUT_FILENO, buffer, bytes_read);
	}

	close(fd);
}

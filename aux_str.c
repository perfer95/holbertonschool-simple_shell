#include "header.h"


/**
 * _strcmp - function that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: an integer (if val = 0 both strings are the same)
 */
int _strcmp(char *s1, char *s2)
{
	int i, val;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
	}

	val = s1[i] - s2[i];

	return (val);
}


/**
 * _strcpy - Write a function that copies the string pointed
 * to by src, including the terminating null byte (\0), to
 * the buffer pointed to by dest.
 * @dest: array which is goin to recibe the string
 * @src: string to copy
 * Return: variable dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

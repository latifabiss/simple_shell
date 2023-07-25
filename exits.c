#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x, j;
	char *s = dest;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		j = x;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int c, j;
	char *s = dest;

	c = 0;
	j = 0;
	while (dest[c] != '\0')
		c++;
	while (src[j] != '\0' && j < n)
	{
		dest[c] = src[j];
		c++;
		j++;
	}
	if (j < n)
		dest[c] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

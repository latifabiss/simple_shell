#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int q = 0;

	if (!str)
		return;
	while (str[q] != '\0')
	{
		_eputchar(str[q]);
		q++;
	}
}

/**
 * _eputchar - writes the character to stder
 * @c: The character to print
 *
 * Return: if success 1.On error, -1 is returned
 */
int _eputchar(char c)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(2, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}

/**
 * _putfd - writes the character c
 * @c: The character to print
 * @fd: The filedescriptor to write
 *
 * Return: On success 1. On error, -1 is returned
 */
int _putfd(char c, int fd)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(fd, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int e = 0;

	if (!str)
		return (0);
	while (*str)
	{
		e += _putfd(*str++, fd);
	}
	return (e);
}

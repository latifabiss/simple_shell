#include "shell.h"

/**
 * interactive - returns true if the shell is in interactive mode
 * @info: the struct address
 *
 * Return: 1 if interactive mode, 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - that checks if the character is a delimeter
 * @c: char to check
 * @del: delimeter string
 * Return: 1 if true, 0 if not
 */
int is_delim(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - that checks the alphabetic character
 * @c:  character to input
 * Return: 1 if c is alphabetic, 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to the integer
 * @s: the str to be converted
 * Return: 0 if no numbers in str, converted number otherwise
 */

int _atoi(char *s)
{
	int x, sign = 1, f = 0, output;
	unsigned int result = 0;

	for (x = 0; s[x] != '\0' && f != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			f = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

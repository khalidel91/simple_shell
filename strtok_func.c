#include "shell.h"

/**
 * check_delim - checks if a character match any char *
 * @c: character to check
 * @str: string to check
 * Return: 1 Success, 0 Failed
 */

unsigned int check_delim(char c, const char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (c == str[x])
			return (1);
	}
	return (0);
}

/**
 * _strtok - token a string into token (strtrok)
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */

char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int x;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (x = 0; ts[x] != '\0'; x++)
	{
		if (check_delim(ts[x], delim) == 0)
			break;
	}
	if (nt[x] == '\0' || nt[x] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + x;
	nt = ts;
	for (x = 0; nt[x] != '\0'; x++)
	{
		if (check_delim(nt[x], delim) == 1)
			break;
	}
	if (nt[x] == '\0')
		nt = NULL;
	else
	{
		nt[x] = '\0';
		nt = nt + x + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}

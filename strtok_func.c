#include "shell.h"

/**
 * check_delimiter - checks if a character matches any delimiter
 * @c: character to check
 * @delim: string of delimiters
 * Return: 1 if success, 0 if failed
 */
unsigned int check_delimiter(char c, const char *delim)
{
	unsigned int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
			return 1;
	}
	return 0;
}

/**
 * _strtok - tokenizes a string into tokens (strtok)
 * @str: string to tokenize
 * @delim: delimiter string
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return NULL;
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delimiter(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return NULL;
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delimiter(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return ts;
}


#include "shell.h"

/**
 * _getline - read the input by user from stdin
 * Return: input
 */

char *_getline()
{
	int idx, buffsize = BUFSIZE, rd;
	char ch = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	idx = 0;
	while (ch != EOF && ch != '\n')
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &ch, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[idx] = ch;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (idx >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
		idx++;
	}
	buff[idx] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * hashtag_handle - remove everything after #
 * @buff: input;
 * Return: void
 */

void hashtag_handle(char *buff)
{
	int idx;

	for (idx = 0; buff[idx] != '\0'; idx++)
	{
		if (buff[idx] == '#')
		{
			buff[idx] = '\0';
			break;
		}
	}
}


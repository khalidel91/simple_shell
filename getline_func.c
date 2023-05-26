#include "shell.h"

/**
* _getline - read the input by user from stdin
* Return: input
*/

char *_getline()
{
int x, buffsize = BUFSIZE, rd;
char s = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (x = 0; s != EOF && s != '\n'; x++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &s, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[x] = s;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (x >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[x] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * hashtag_handle - remove everything after #
 * @buff: input;
 * Return:void
 */

void hashtag_handle(char *buff)
{
	int x;

		for (x = 0; buff[x] != '\0'; x++)
		{
			if (buff[x] == '#')
			{
			buff[x] = '\0';
			break;
			}
	}
}

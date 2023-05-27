#include "shell.h"

/**
 * parse_cmd - parse command
 * @input: user input to be parsed
 * Return: array of char
 */

char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int x, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (x = 0; token; x++)
	{
		tokens[x] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[x] = NULL;

	return (tokens);
}

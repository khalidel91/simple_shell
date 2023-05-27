#include "shell.h"

/**
 * parse_cmd - parse line of input
 * @input: user input to parse
 * Return: array of char (parsed) or NULL if failed
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, bufsize = BUFSIZE;

	if (input == NULL)
		return NULL;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("parse_cmd");
		return NULL;
	}

	token = _strtok(input, " \t\n"); // Updated delimiter to include whitespace
	for (i = 0; token; i++)
	{
		tokens[i] = _strdup(token); // Use _strdup to allocate memory for each token
		if (!tokens[i])
		{
			perror("parse_cmd");
			free_tokens(tokens); // Free allocated memory for tokens before returning NULL
			return NULL;
		}
		token = _strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return tokens;
}


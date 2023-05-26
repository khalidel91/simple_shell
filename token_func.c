#include "shell.h"
/**
 * parse_cmd - parse a line of input
 * @input: user input to parse
 * Return: array of strings (parsed tokens)
 */
char **parse_cmd(char *input)
{
    char **tokens;
    char *token;
    int i, buffsize = BUFSIZE;
    if (input == NULL)
        return NULL;
    tokens = malloc(sizeof(char *) * buffsize);
    if (!tokens)
    {
        perror("hsh");
        return NULL;
    }
    token = _strtok(input, "\n ");
    i = 0;
    while (token)
    {
        tokens[i] = token;
        token = _strtok(NULL, "\n ");
        i++;
    }
    tokens[i] = NULL;
    return tokens;
}

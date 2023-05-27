#include "shell.h"

/**
 * _getline - read the input by user from stdin
 * Return: input
 */

char *_getline()
{
    int index, buffsize = BUFSIZE, rd;
    char c = 0;
    char *buffer = malloc(buffsize);

    if (buffer == NULL)
    {
        free(buffer);
        return (NULL);
    }

    for (index = 0; c != EOF && c != '\n'; index++)
    {
        fflush(stdin);
        rd = read(STDIN_FILENO, &c, 1);
        if (rd == 0)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        buffer[index] = c;
        if (buffer[0] == '\n')
        {
            free(buffer);
            return ("\0");
        }
        if (index >= buffsize)
        {
            buffer = _realloc(buffer, buffsize, buffsize + 1);
            if (buffer == NULL)
            {
                return (NULL);
            }
        }
    }
    buffer[index] = '\0';
    hashtag_handle(buffer);
    return (buffer);
}

/**
 * hashtag_handle - remove everything after #
 * @buffer: input;
 * Return: void
 */

void hashtag_handle(char *buffer)
{
    int index;

    for (index = 0; buffer[index] != '\0'; index++)
    {
        if (buffer[index] == '#')
        {
            buffer[index] = '\0';
            break;
        }
    }
}


#include "shell.h"
/**
 * check_delim - checks if a character matches any character in a string
 * @c: character to check
 * @str: string to check
 * Return: 1 if successful, 0 if failed
 */
unsigned int check_delim(char c, const char *str)
{
    unsigned int x = 0;
    while (str[x] != '\0')
    {
        if (c == str[x])
            return 1;
        x++;
    }
    return 0;
}
/**
 * _strtok - tokenize a string based on delimiters (strtok)
 * @str: string to tokenize
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
    static char *ts;
    static char *nt;
    unsigned int x = 0;
    if (str != NULL)
        nt = str;
    ts = nt;
    if (ts == NULL)
        return NULL;
    while (ts[x] != '\0')
    {
        if (check_delim(ts[x], delim) == 0)
            break;
        x++;
    }
    if (nt[x] == '\0' || nt[x] == '#')
    {
        nt = NULL;
        return NULL;
    }
    ts = nt + x;
    nt = ts;
    x = 0;
    while (nt[x] != '\0')
    {
        if (check_delim(nt[x], delim) == 1)
            break;
        x++;
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
    return ts;
}

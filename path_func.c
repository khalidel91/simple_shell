#include "shell.h"
/**
 * path_cmd -  search in $PATH for executable command
 * @cmd: parsed input
 * Return: 1 Failure 0 Success.
 */
int path_cmd(char **cmd)
{
    char *path, *value, *cmd_path;
    struct stat buf;
    path = _getenv("PATH");
    value = _strtok(path, ":");
    while (value != NULL)
    {
        cmd_path = build(*cmd, value);
        if (stat(cmd_path, &buf) == 0)
        {
            *cmd = _strdup(cmd_path);
            free(cmd_path);
            free(path);
            return (0);
        }
        free(cmd_path);
        value = _strtok(NULL, ":");
    }
    free(path);
    return (1);
}
/**
 * build - build command
 * @token: executable command
 * @value: directory concatenating command
 *
 * Return: parsed full path of command or NULL in case of failure
 */
char *build(char *token, char *value)
{
    char *cmd;
    size_t length;
    length = _strlen(value) + _strlen(token) + 2;
    cmd = malloc(sizeof(char) * length);
    if (cmd == NULL)
    {
        return (NULL);
    }
    memset(cmd, 0, length);
    cmd = _strcat(cmd, value);
    cmd = _strcat(cmd, "/");
    cmd = _strcat(cmd, token);
    return (cmd);
}
/**
 * _getenv - gets the value of environment variable by name
 * @name: environment variable name
 * Return: the value of the environment variable else NULL.
 */
char *_getenv(char *name)
{
    size_t name_length, value_length;
    char *value;
    int x, i, j;
    name_length = _strlen(name);
    for (x = 0; environ[x]; x++)
    {
        if (_strncmp(name, environ[x], name_length) == 0)
        {
            value_length = _strlen(environ[x]) - name_length;
            value = malloc(sizeof(char) * value_length);
            if (!value)
            {
                free(value);
                perror("unable to alloc");
                return (NULL);
            }
            j = 0;
            for (i = name_length + 1; environ[x][i]; i++, j++)
            {
                value[j] = environ[x][i];
            }
            value[j] = '\0';
            return (value);
        }
    }
    return (NULL);
}

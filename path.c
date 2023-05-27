#include "shell.h"

/**
 * search_path_cmd - search in $PATH for executable command
 * @cmd: parsed input
 * Return: 1 (Failure) or 0 (Success)
 */
int search_path_cmd(char **cmd)
{
	char *path, *dir, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	dir = _strtok(path, ":");
	while (dir != NULL)
	{
		cmd_path = build_cmd_path(*cmd, dir);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return 0;
		}
		free(cmd_path);
		dir = _strtok(NULL, ":");
	}
	free(path);

	return 1;
}

/**
 * build_cmd_path - build full path of command
 * @cmd: executable command
 * @dir: directory to concatenate with command
 * Return: parsed full path of command or NULL in case of failure
 */
char *build_cmd_path(char *cmd, char *dir)
{
	char *cmd_path;
	size_t dir_len, cmd_len, path_len;

	dir_len = _strlen(dir);
	cmd_len = _strlen(cmd);
	path_len = dir_len + cmd_len + 2;

	cmd_path = malloc(sizeof(char) * path_len);
	if (cmd_path == NULL)
	{
		return NULL;
	}

	memset(cmd_path, 0, path_len);

	cmd_path = _strcat(cmd_path, dir);
	cmd_path = _strcat(cmd_path, "/");
	cmd_path = _strcat(cmd_path, cmd);

	return cmd_path;
}

/**
 * _getenv - gets the value of environment variable by name
 * @name: environment variable name
 * Return: the value of the environment variable or NULL
 */
char *_getenv(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			value_len = _strlen(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to allocate memory");
				return NULL;
			}

			j = 0;
			for (int k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return value;
		}
	}

	return NULL;
}


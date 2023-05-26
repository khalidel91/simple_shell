#include "shell.h"
/**
 * history - fill file by user input
 * @input: user input
 * Return: -1 Fail 0 Success
 */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t file_descriptor, written;
	int length = 0;
	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);
	if (input)
	{
		while (input[length])
			length++;
		written = write(file_descriptor, input, length);
		if (written < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - free environment variable array
 * @env: environment variables.
 * Return: void
 */
void free_env(char **env)
{
	int idx;
	for (idx = 0; env[idx]; idx++)
	{
		free(env[idx]);
	}
}

#include "shell.h"

/**
 * history - save user input to a file
 * @input: user input
 * Return: -1 for failure, 0 for success
 */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t file_descriptor, bytes_written;
	int input_length = 0;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);

	if (input)
	{
		while (input[input_length] != '\0')
			input_length++;

		bytes_written = write(file_descriptor, input, input_length);
		if (bytes_written < 0)
			return (-1);
	}

	return (0);
}

/**
 * free_env - free environment variable array
 * @env: environment variables
 * Return: void
 */
void free_env(char **env)
{
	int index;

	for (index = 0; env[index] != NULL; index++)
	{
		free(env[index]);
	}
}


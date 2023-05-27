#include "shell.h"

/**
 * history - fill file by user input
 * @input: user input
 * Return: -1 Fail 0 Success
 */

int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t file_descriptor, write_result;
	int input_length = 0;

	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);
	if (input)
	{
		while (input[input_length])
			input_length++;
		write_result = write(file_descriptor, input, input_length);
		if (write_result < 0)
			return (-1);
	}
	return (1);
}

/**
 * free_env - free environment variable array
 * @env_array: environment variables.
 * Return: void
 */

void free_env(char **env_array)
{
	int index;

	for (index = 0; env_array[index]; index++)
	{
		free(env_array[index]);
	}
}


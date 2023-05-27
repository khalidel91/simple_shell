#include "shell.h"

/**
 * history_display - display history of user input in the simple shell
 * @cmd: parsed command
 * @status: status of the last execution
 * Return: 0 for success, -1 for failure
 */
int history_display(__attribute__((unused)) char **cmd, __attribute__((unused)) int status)
{
	char *filename = ".simple_shell_history";
	FILE *file_ptr;
	char *line = NULL;
	size_t line_length = 0;
	int counter = 0;
	char *error_message;

	file_ptr = fopen(filename, "r");
	if (file_ptr == NULL)
	{
		return (-1);
	}

	while ((getline(&line, &line_length, file_ptr)) != -1)
	{
		counter++;
		error_message = _itoa(counter);
		PRINTER(error_message);
		free(error_message);
		PRINTER(" ");
		PRINTER(line);
	}

	if (line != NULL)
		free(line);

	fclose(file_ptr);
	return (0);
}

/**
 * execute_echo - execute the echo command
 * @cmd: parsed command
 * Return: 0 for success, -1 for failure
 */
int execute_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}


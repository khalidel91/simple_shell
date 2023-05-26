#include "shell.h"
/**
 * history_dis - display history of user input in the simple shell
 * @c: parsed command
 * @s: status of the last execution
 * Return: 0 Success, -1 Failure
 */
int history_dis(__attribute__((unused)) char **c, __attribute__((unused)) int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t length = 0;
	int counter = 0;
	char *er;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &length, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
 * print_echo - execute normal echo
 * @cmd: parsed command
 * Return: 0 Success, -1 Failure
 */
int print_echo(char **cmd)
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
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

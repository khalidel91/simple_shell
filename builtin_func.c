#include "shell.h"

/**
 * exit_shell - Exit shell with a given status.
 * @cmd: Parsed command.
 * @input: User input.
 * @argv: Program name.
 * @c: Execution count.
 * Return: Void.
 */

void exit_shell(char **cmd, char *input, char **argv, int c)
{
	int status, x = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	for (; cmd[1][x]; x++)
	{
		if (!_isalpha(cmd[1][x++]))
		{
			status = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(status);
		}
		else
		{
			_print_error(argv, c, cmd);
			break;
		}
	}
}

/**
 * change_directory - Change directory.
 * @cmd: Parsed command.
 * @er: Status of the last executed command.
 * Return: 0 on success, 1 on failure.
 */

int change_directory(char **cmd, __attribute__((unused)) int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * display_environment - Display environment variables.
 * @cmd: Parsed command.
 * @er: Status of the last executed command.
 * Return: Always 0.
 */

int display_environment(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t x;
	int len;

	for (x = 0; environ[x] != NULL; x++)
	{
		len = _strlen(environ[x]);
		write(1, environ[x], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - Display help for built-in commands.
 * @cmd: Parsed command.
 * @er: Status of the last executed command.
 * Return: 0 on success, -1 on failure.
 */

int display_help(char **cmd, __attribute__((unused)) int er)
{
	int fd, fw, rd = 1;
	char s;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}

	while (rd > 0)
	{
		rd = read(fd, &s, 1);
		fw = write(STDOUT_FILENO, &s, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}

	_putchar('\n');
	return (0);
}

/**
 * echo_command - Execute echo command.
 * @st: Status of the last executed command.
 * @cmd: Parsed command.
 * Return: 0 on success, or execute normal echo.
 */

int echo_command(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}


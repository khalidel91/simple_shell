#include "shell.h"

/**
 * exit_bul - exit status shell
 * @args: parsed command
 * @input: user input
 * @program_name: program name
 * @execute_count: execute count
 * Return: void (exit status)
 */

void exit_bul(char **args, char *input, char **program_name, int execute_count)
{
	int status, index = 0;

	if (args[1] == NULL)
	{
		free(input);
		free(args);
		exit(EXIT_SUCCESS);
	}

	while (args[1][index])
	{
		if (_isalpha(args[1][index++]) != 0)
		{
			_prerror(program_name, execute_count, args);
			break;
		}
		else
		{
			status = _atoi(args[1]);
			free(input);
			free(args);
			exit(status);
		}
	}
}


/**
 * change_dir - change directory
 * @args: parsed command
 * @last_status: status of the last command executed
 * Return: 0 Success, 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */

int change_dir(char **args, __attribute__((unused)) int last_status)
{
	int result = -1;
	char cwd[PATH_MAX];

	if (args[1] == NULL)
		result = chdir(getenv("HOME"));
	else if (_strcmp(args[1], "-") == 0)
	{
		result = chdir(getenv("OLDPWD"));
	}
	else
		result = chdir(args[1]);

	if (result == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (result != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - display environment variable
 * @args: parsed command
 * @last_status: status of the last command executed
 * Return: Always 0
 */

int dis_env(__attribute__((unused)) char **args, __attribute__((unused)) int last_status)
{
	size_t index;
	int len;

	for (index = 0; environ[index] != NULL; index++)
	{
		len = _strlen(environ[index]);
		write(1, environ[index], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - Displaying Help For Builtin
 * @args: parsed command
 * @last_status: status of the last command executed
 * Return: 0 Success, -1 Fail
 */

int display_help(char **args, __attribute__((unused)) int last_status)
{
	int fd, fw, rd = 1;
	char s;

	fd = open(args[1], O_RDONLY);
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
 * echo_bul - execute echo cases
 * @last_status: status of last command executed
 * @args: parsed command
 * Return: Always 0 Or Execute Normal Echo
 */

int echo_bul(char **args, int last_status)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(args[1], "$?", 2) == 0)
	{
		print_number_in(last_status);
		PRINTER("\n");
	}
	else if (_strncmp(args[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");
	}
	else if (_strncmp(args[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_echo(args));

	return (1);
}


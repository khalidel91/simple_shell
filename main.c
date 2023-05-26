#include "shell.h"

/**
 * main - simple shell (Hsh)
 * @argc: Argument Counter
 * @argv: Value of Argument
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int ctr = 0, stat = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (stat)
	{
<<<<<<< HEAD
		if (execvp(args[0], args) == -1)
			perror("lsh");
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	perror("lsh");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * func_execute - execution function
 * @args: argument
 *
 * Return: integer
 */
int func_execute(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < func_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (func_launch(args));
}

/**
 * func_read_line - Read the line function
 *
 * Return: String line
 *
 */

#define _GNU_SOURCE
char *func_read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t n_char;

    n_char = getline(&line, &bufsize, stdin);
    if (n_char == -1)
    {
        if (feof(stdin))
            exit(EXIT_SUCCESS);
        else
        {
            perror("lsh: getline\n");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}


#define func_TOK_BUFSIZE 64
#define func_TOK_DELIM " \t\r\a"
=======
		ctr++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, ctr);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, ctr, argv);

		}
		free_all(cmd, input);
	}
	return (stat);
}
>>>>>>> 1f236ac7e2078bcd3bcb3e7c2f4311d2443d87e5
/**
 * check_builtin - for checking builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int x = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + x)->command)
	{
		if (_strcmp(cmd[0], (fun + x)->command) == 0)
			return (0);
		x++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int x;

	for (x = 0; environ[x]; x++)
		envi[x] = _strdup(environ[x]);
	envi[x] = NULL;
}

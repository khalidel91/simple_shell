#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int func_cd(char **args);
int func_help(char **args);
int func_exit(char **args);


char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&func_cd,
	&func_help,
	&func_exit
};

/**
 * func_num_builtins - num builtins function
 *
 *
 * Return: integer
 */
int func_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * func_cd - change directory function
 *
 * @args: arguments
 * Return: always 1
 */
int func_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("lsh");
	}
	return (1);
}

/**
 * func_help - help function
 * @args: arguments
 *
 * Return: always 1
 */
int func_help(char **args)
{
	int i;

	(void) args;
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < func_num_builtins(); i++)
		printf("  %s\n", builtin_str[i]);
	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * func_exit - exit function
 *
 * @args: argument
 * Return: always 1
 */
int func_exit(char **args)
{
	(void) args;
	return (0);
}
/**
 * func_launch - launch function
 * @args: arguments
 * Return: always 1
 */
int func_launch(char **args)
{
	pid_t pid;
	int status;

	(void) args;

	pid = fork();
	if (pid == 0)
	{
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
char *func_read_line(void)
{
	#ifdef func_USE_STD_GETLINE
		char *line = NULL;
		ssize_t bufsize = 0;

		if (getline(&line, &bufsize, stdin) == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				perror("lsh: getline\n");
				exit(EXIT_FAILURE);
			}
		}
		return (line);
#else
#define func_RL_BUFSIZE 1024
int bufsize = func_RL_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;
		if (!buffer)
		{
			fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
		}
		while (1)
		{
			c = getchar();
			if (c == EOF)
				exit(EXIT_SUCCESS);
			else if (c == '\n')
			{
				buffer[position] = '\0';
				return (buffer);
			}
			else
				buffer[position] = c;
			position++;
			if (position >= bufsize)
			{
				bufsize += func_RL_BUFSIZE;
				buffer = realloc(buffer, bufsize);
				if (!buffer)
				{
					fprintf(stderr, "lsh: allocation error\n");
					exit(EXIT_FAILURE);
				}
			}
		}
	#endif
}
#define func_TOK_BUFSIZE 64
#define func_TOK_DELIM " \t\r\n\a"
/**
 * func_split_line - split entry line
 *
 * @line: entry line
 * Return: Tokens
 */
char **func_split_line(char *line)
{
	int bufsize = func_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, func_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += func_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, func_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * func_loop - loop function
 *
 */
void func_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
	printf("> ");
	line = func_read_line();
	args = func_split_line(line);
	status = func_execute(args);
	free(line);
	free(args);
	} while (status);
}
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: alwayas success
 */
int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	func_loop();
	return (EXIT_SUCCESS);
}

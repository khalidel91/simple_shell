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

int func_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

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

int func_exit(char **args)
{
	(void) args;
	return (0);
}

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

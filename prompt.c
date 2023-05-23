#include "head.h"
/**
 * prompt - Display a prompt and wait for the user to type a command
 * @av: argument vector
 * @env: environment variables
 *
 */
void prompt(char **av, char **env)
{
	char *s = NULL;
	size_t n = 0;
	int i = 0, status;
	ssize_t n_char;
	char *argv[] = {NULL, NULL};
	pid_t c_pid;

	for (;;)
	{
		if (isatty(STDIN_FILENO == 1))
			printf("cisfun$: ");
		n_char = getline(&s, &n, stdin);
		if (n_char == -1)
		{
			free(s);
			exit(EXIT_FAILURE);
		}
		for (i = 0; s[i]; i++)
		{
			if (s[i] == '\n')
				s[i] = 0;
		}
		argv[0] = s;
		c_pid = fork();
		if (c_pid == -1)
		{
			free(s);
			exit(EXIT_FAILURE);
		}
		if (c_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}

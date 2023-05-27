#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	PRINTER("$ ");
}

/**
 * display_error - Display an error message based on the command and shell loop count
 * @input: User input
 * @counter: Shell loop count
 * @argv: Program name
 * Return: Void
 */
void display_error(char *input, int counter, char **argv)
{
	char *counter_str;

	PRINTER(argv[0]);
	PRINTER(": ");
	counter_str = _itoa(counter);
	PRINTER(counter_str);
	free(counter_str);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}


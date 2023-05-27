#include "shell.h"

/**
 * print_error - print custom error message
 * @argv: program name
 * @count: error count
 * @cmd: command
 * Return: void
 */
void _prerror(char **argv, int count, char **cmd)
{
	char *error_count = _itoa(count);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(error_count);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");

	free(error_count);
}


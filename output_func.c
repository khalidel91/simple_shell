#include "shell.h"
/**
 * _prerror - print custom error
 * @argv: program name
 * @c: error count
 * @cmd: command
 * Return: void
 */
void _prerror(char **argv, int c, char **cmd)
{
    char *er = _itoa(c);
    int i = 0;
    PRINTER(argv[0]);
    PRINTER(": ");
    PRINTER(er);
    PRINTER(": ");
    PRINTER(cmd[0]);
    PRINTER(": Illegal number: ");
    while (cmd[1][i] != '\0')
    {
        PRINTER(cmd[1][i]);
        i++;
    }
    PRINTER("\n");
    free(er);
}

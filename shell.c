#include "head.h"

/**
 * main - main function
 *
 * @ac: number of arguments
 * @av: argument vector
 * @env: environment variables
 *
 * Return: always 0
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}

#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copy a string
 * @dest: destination string
 * @src: source string
 * @n: number of characters to copy
 * Return: pointer to the destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int index;

	for (index = 0; index < n && src[index]; index++)
		dest[index] = src[index];

	for (; index < n; index++)
		dest[index] = '\0';

	return (dest);
}

/**
 * _strlen - length of a string
 * @s: input string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int length;

	for (length = 0; s[length] != '\0'; length++)
		continue;

	return (length);
}

/**
 * _atoi - convert a string to an integer
 * @s: input string
 * Return: converted integer
 */

int _atoi(char *s)
{
	int index, sign, result;

	index = sign = result = 0;
	while ((s[index] < '0' || s[index] > '9') && (s[index] != '\0'))
	{
		if (s[index] == '-')
			sign *= -1;
		index++;
	}

	while ((s[index] >= '0') && (s[index] <= '9'))
	{
		result = (result * 10) + sign * ((s[index]) - '0');
		index++;
	}

	return (result);
}

/**
 * _puts - print a string
 * @str: input string
 * Return: void
 */

void _puts(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
		_putchar(str[index]);

	_putchar('\n');
	return;
}


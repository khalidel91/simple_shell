#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _strncpy - copy a string
 * @dest: destination string
 * @src: source string
 * @n: number of characters to copy
 * Return: pointer to destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}

	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}

	return (dest);
}

/**
 * _strlen - length of string
 * @str: input string
 * Return: length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
	{
		continue;
	}

	return (len);
}

/**
 * _atoi - convert to an integer
 * @str: input string
 * Return: converted integer value
 */

int _atoi(char *str)
{
	int i = 0, j = 0, num = 0, sign = 1;

	while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	j = i;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		num = (num * 10) + (i * ((str[j]) - '0'));
		j++;
	}

	return (num * sign);
}

/**
 * _puts - print a string
 * @str: input string
 * Return: void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}


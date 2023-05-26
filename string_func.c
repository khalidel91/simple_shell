#include "shell.h"

/**
 * _strcpy - copy source to destination char
 * @dest: destination
 * @src: source
 * Return: copy of char
 */

char *_strcpy(char *dest, char *src)
{
	int x;

	x = 0;

	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

/**
 * _strcat - concanate two string
 * @dest: first string
 * @src: second string
 * Return: first string + second string char
 */

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strchr - Locate Charactere In String
 * @s:String Search In
 * @c:Char To Search For
 * Return: Pointer To Char*
 */

char *_strchr(char *s, char c)
{

	do	{
		if (*s == c)
		{
			break;
		}
	}	while (*s++);

	return (s);
}

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	if (s1 == NULL)
		return (-1);
	for (x = 0; x < n && s2[x]; x++)
	{
		if (s1[x] != s2[x])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */

char *_strdup(char *str)
{
	size_t len, x;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (x = 0; x <= len; x++)
	{
		str2[x] = str[x];
	}

	return (str2);
}

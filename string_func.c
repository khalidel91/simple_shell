#include "shell.h"

/**
 * string_copy - Copy source string to destination string.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the destination string.
 */

char *string_copy(char *dest, char *src)
{
	for (int index = 0; src[index]; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';
	return dest;
}

/**
 * string_concatenate - Concatenate two strings.
 * @dest: First string.
 * @src: Second string.
 * Return: Pointer to the concatenated string.
 */

char *string_concatenate(char *dest, char *src)
{
	char *result = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	for (; *src != '\0'; dest++, src++)
	{
		*dest = *src;
	}
	*dest = '\0';
	return result;
}

/**
 * string_find_char - Locate character in string.
 * @s: String to search in.
 * @c: Character to search for.
 * Return: Pointer to the character in the string.
 */

char *string_find_char(char *s, char c)
{
	do
	{
		if (*s == c)
		{
			break;
		}
	} while (*s++);

	return s;
}

/**
 * string_compare - Compare n characters of two strings.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of characters to compare.
 * Return: 1 if the strings don't match, 0 otherwise.
 */

int string_compare(const char *s1, const char *s2, size_t n)
{
	for (size_t index = 0; index < n && s2[index]; index++)
	{
		if (s1[index] != s2[index])
		{
			return 1;
		}
	}
	return 0;
}

/**
 * string_duplicate - Duplicate a string.
 * @str: String to duplicate.
 * Return: Pointer to the duplicated string, or NULL if failed.
 */

char *string_duplicate(char *str)
{
	size_t len = string_length(str);
	char *duplicate = malloc(sizeof(char) * (len + 1));
	if (!duplicate)
	{
		return NULL;
	}

	for (size_t index = 0; index <= len; index++)
	{
		duplicate[index] = str[index];
	}

	return duplicate;
}

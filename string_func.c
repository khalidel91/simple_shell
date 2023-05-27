#include "shell.h"

/**
 * _strcpy - copy source to destination char
 * @dest: destination
 * @src: source
 * Return: copy of char
 */

char *_strcpy(char *destination, char *source)
{
    int index = 0;

    while (source[index])
    {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
    return destination;
}

/**
 * _strcat - concatenate two strings
 * @dest: first string
 * @src: second string
 * Return: concatenated string
 */

char *_strcat(char *destination, char *source)
{
    char *result = destination;

    while (*destination != '\0')
    {
        destination++;
    }

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return result;
}

/**
 * _strchr - Locate Character In String
 * @str: String to search in
 * @c: Character to search for
 * Return: Pointer to char*
 */

char *_strchr(char *str, char c)
{
    do
    {
        if (*str == c)
        {
            break;
        }
    } while (*str++);

    return str;
}

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */

int _strncmp(const char *string1, const char *string2, size_t n)
{
    size_t index;

    if (string1 == NULL)
        return (-1);
    for (index = 0; index < n && string2[index]; index++)
    {
        if (string1[index] != string2[index])
        {
            return (1);
        }
    }
    return (0);
}

/**
 * _strdup - Duplicate A String
 * @str: String
 * Return: Duplicate String (NULL if failed)
 */

char *_strdup(char *string)
{
    size_t length, index;
    char *duplicate;

    length = _strlen(string);
    duplicate = malloc(sizeof(char) * (length + 1));
    if (!duplicate)
    {
        return (NULL);
    }

    for (index = 0; index <= length; index++)
    {
        duplicate[index] = string[index];
    }

return duplicate;
}


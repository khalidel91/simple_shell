#include "shell.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if identical, otherwise the difference
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}

	return (cmp);
}

/**
 * _isalpha - check if a character is alphabetic
 * @c: character
 * Return: 1 if true, 0 if not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - convert an integer to a string
 * @n: integer to convert
 * Return: pointer to the resulting string
 */
char *_itoa(unsigned int n)
{
	int length = 0, i = 0;
	char *s;

	length = intlen(n);
	s = malloc(length + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, length);
	s[i + 1] = '\0';
	return (s);
}

/**
 * array_reverse - reverse an array
 * @arr: array to reverse
 * @len: length of the array
 * Return: void (reverse the array in-place)
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * int_len - determine the length of an integer
 * @num: given integer
 * Return: length of the integer
 */
int int_len(int num)
{
	int length = 0;

	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}


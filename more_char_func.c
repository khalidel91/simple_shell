#include "shell.h"

/**
 * _strcmp - compare two string
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if identical otherwise how much diffrent
 */

int _strcmp(char *s1, char *s2)
{
int cmp = 0, x, len1, len2;
len1 = _strlen(s1);
len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (x = 0; s1[x]; x++)
	{
		if (s1[x] != s2[x])
		{
			cmp = s1[x] - s2[x];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - check if alphabetic
 *@c: character
 * Return: 1 if true 0 if not
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
 * _itoa - convert integer to char
 * @n: int to convert
 * Return: char pointer
 */

char *_itoa(unsigned int n)
{
	int length = 0, x = 0;
	char *s;

	length = intlen(n);
	s = malloc(length + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[x] = (n % 10) + '0';
		n /= 10;
		x++;
	}
	s[x] = (n % 10) + '0';
	array_rev(s, length);
	s[x + 1] = '\0';
	return (s);
}

/**
 * array_rev - reverse array
 * @arr: array to reverse
 * @len: length of array
 * Return: void(reverse array)
 */

void array_rev(char *arr, int len)
{
	int x;
	char tmp;

	for (x = 0; x < (len / 2); x++)
	{
		tmp = arr[x];
		arr[x] = arr[(len - 1) - x];
		arr[(len - 1) - x] = tmp;
	}
}

/**
 * intlen - determine length of int
 * @num: given int
 * Return: length of int
 */

int intlen(int num)
{
	int length = 0;

	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

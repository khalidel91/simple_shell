#include "shell.h"

/**
 **_realloc -  reallocates a memory block using malloc and free
 *@ptr: pointer
 *@old_size: previous size of the pointer
 *@new_size: new size of the pointer
 *Return: void pointer rellocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}

/**
 * free_all - free array of char pointer and char pointer
 * @cmd: array pointer
 * @line: char pointer
 * Return: void
 */

void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copy byte from source to destination
 * @dest: destination pointer
 * @src: source pointer
 * @n: size (how much to copy)
 *Return: void pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}

/**
 * fill_an_array - fill an array by constant byte
 * @a: void pointer
 * @el: int
 * @len: length int
 *Return: void pointer
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int x = 0;

	while (x < len)
	{
		*p = el;
		p++;
		x++;
	}
	return (a);
}
/**
 * _calloc -  allocates memory for an array, using malloc.
 * @size: size
 * Return: void pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int x;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (x = 0; x < size; x++)
	{
		a[x] = '\0';
	}
	return (a);
}

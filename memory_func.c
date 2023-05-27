#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: previous size of the pointer
 * @new_size: new size of the pointer
 * Return: void pointer to the reallocated memory
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
	}
	else
	{
		memcpy(result, ptr, old_size);
		free(ptr);
	}

	return (result);
}

/**
 * free_all - free array of char pointers and a char pointer
 * @cmd: array pointer
 * @line: char pointer
 * Return: void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
}

/**
 * _memcpy - copy bytes from source to destination
 * @dest: destination pointer
 * @src: source pointer
 * @n: number of bytes to copy
 * Return: void pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * fill_array - fill an array with a constant byte
 * @array: array pointer
 * @value: constant byte value
 * @size: size of the array
 * Return: void pointer
 */
void *fill_an_array(void *array, int value, unsigned int size)
{
	char *ptr = array;
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		ptr[i] = value;
	}

	return (array);
}

/**
 * _calloc - allocates memory for an array, using malloc
 * @size: size of the array
 * Return: void pointer to the allocated memory
 */
void *_calloc(unsigned int size)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		array[i] = '\0';
	}

	return (array);
}


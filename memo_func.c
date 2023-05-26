#include "shell.h"
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: previous size of the pointer
 * @new_size: new size of the pointer
 * Return: void pointer reallocated memory
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
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		copy_mem(result, ptr, old_size);
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
 * copy_mem - copy bytes from source to destination
 * @dest: destination pointer
 * @src: source pointer
 * @n: size (how much to copy)
 * Return: void pointer
 */
char *copy_mem(char *dest, char *src, unsigned int n)
{
	unsigned int x;
	for (x = 0; x < n; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}
/**
 * fill_array - fill an array with a constant byte
 * @arr: void pointer to the array
 * @value: int value to fill
 * @size: size of the array
 * Return: void pointer
 */
void *fill_array(void *arr, int value, unsigned int size)
{
	char *ptr = arr;
	unsigned int x = 0;
	while (x < size)
	{
		*ptr = value;
		ptr++;
		x++;
	}
	return (arr);
}
/**
 * _calloc - allocates memory for an array, using malloc
 * @size: size
 * Return: void pointer
 */
void *_calloc(unsigned int size)
{
	char *arr;
	unsigned int x;
	if (size == 0)
		return (NULL);
	arr = malloc(size);
	if (arr == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
	{
		arr[x] = '\0';
	}
	return (arr);
}

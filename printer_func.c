#include "shell.h"

/**
 * print_number - print unsigned int putchar
 * @n: unisigned Integer
 * Return: void
 */

void print_number(unsigned int n)
{
	unsigned int i = n;

	if ((i / 10) > 0)
		print_number(i / 10);

	_putchar(i % 10 + '0');
}

/**
 * print_number_in - print number putchar
 * @n: integer
 * Return: void
 */

void print_number_in(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}
	if ((i / 10) > 0)
		print_number(i / 10);

	_putchar(i % 10 + '0');
}

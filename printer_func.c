#include "shell.h"

/**
 * print_unsigned_number - print unsigned integer using putchar
 * @num: unsigned integer
 * Return: void
 */
void print_unsigned_number(unsigned int num)
{
	unsigned int digit = num;

	if ((digit / 10) > 0)
		print_unsigned_number(digit / 10);

	_putchar(digit % 10 + '0');
}

/**
 * print_number - print number using putchar
 * @num: integer
 * Return: void
 */
void print_number(int num)
{
	unsigned int digit;

	if (num < 0)
	{
		_putchar('-');
		digit = -num;
	}
	else
	{
		digit = num;
	}

	if ((digit / 10) > 0)
		print_unsigned_number(digit / 10);

	_putchar(digit % 10 + '0');
}


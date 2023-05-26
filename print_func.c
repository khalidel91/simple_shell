#include "shell.h"
/**
 * print_number - print unsigned int putchar
 * @n: unsigned integer
 * Return: void
 */
void print_number(unsigned int n)
{
    unsigned int num = n;
    if ((num / 10) > 0)
        print_number(num / 10);
    _putchar(num % 10 + '0');
}
/**
 * print_number_in - print number putchar
 * @n: integer
 * Return: void
 */
void print_number_in(int n)
{
    unsigned int num = n;
    if (n < 0)
    {
        _putchar('-');
        num = -num;
    }
    if ((num / 10) > 0)
        print_number(num / 10);
    _putchar(num % 10 + '0');
}

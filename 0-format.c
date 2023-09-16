#include <unistd.h>

/**
 * printc - write c as format specifier'
 *
 * Return: 0 
 */

void printc(char c)
{
	return (write(1, &c, 1));
}


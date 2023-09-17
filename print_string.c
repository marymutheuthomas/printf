#include"main.h"
/**
* print_string - function to print string
* @str: the string to be printed
* Return: count
*/

int print_string(char *str)
{
    int count = 0;
    /*check if string points to null 1st*/
    if (str)
    {
        while (*str != '\0')
        {
            putchar(*str);
            str++;
            count++;
        }
        return count;
    }
    else
    {
        return (-1);
    }
}

#include "main.h"

/**
 * flush_buffer - Flush the buffer
 *@buffer: buffer
 *@buffer_index: buffer_index
 * Return: 0
 **/
void flush_buffer(char *buffer, int *buffer_index)
{
	if (*buffer_index > 0)
	{
	write(STDOUT_FILENO, buffer, *buffer_index);
	*buffer_index = 0;
	}
}

/**
 * append_to_buffer - Append a character to the buffer
 *@buffer: buffer
 *@buffer_index: buffer_index
 *@c: char c
 * Return: 0
 **/
void append_to_buffer(char *buffer, int *buffer_index, char c)
{
	if (*buffer_index >= BUFFER_SIZE - 1)
	{
		flush_buffer(buffer, buffer_index);
	}
	buffer[(*buffer_index)++] = c;
}


#include "main.h"

/** Flush the buffer */
void flush_buffer(char *buffer, int *buffer_index) {
    if (*buffer_index > 0) {
        write(STDOUT_FILENO, buffer, *buffer_index);
        *buffer_index = 0;
    }
}

/** Append a character to the buffer */
void append_to_buffer(char *buffer, int *buffer_index, char c) {
    if (*buffer_index >= BUFFER_SIZE - 1) {
        flush_buffer(buffer, buffer_index);
    }
    buffer[(*buffer_index)++] = c;
}


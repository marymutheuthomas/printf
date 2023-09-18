#include"main.h"
/* Function to manage the buffer*/
void flush_buffer(char *buffer, char **bufptr) {
    if (*bufptr - buffer >= BUFFER_SIZE) {
        write(STDOUT_FILENO, buffer, BUFFER_SIZE);
        *bufptr = buffer;
    }
}


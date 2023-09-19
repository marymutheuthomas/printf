#include"main.h"

/* Function to find the handler for a given format specifier*/
int find_handler(char specifier, FormatHandler *handlers, int num_handlers) {
    int i;
    for (i = 0; i < num_handlers; i++) {
        if (handlers[i].specifier == specifier) {
            return i;
        }
    }
    return -1; /* Not found */
}


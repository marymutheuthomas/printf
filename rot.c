#include "main.h"

/**
 * rot13 - Perform the ROT13 transformation on a string.
 * @str: The input string to be transformed.
 *
 * This function modifies the input string in-place, applying the ROT13
 * transformation to alphabetic characters while leaving non-alphabetic
 * characters unchanged.
 */
void rot13(char *str) {
    while (*str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            char base = (*str >= 'a' && *str <= 'z') ? 'a' : 'A';
            *str = ((*str - base + 13) % 26) + base;
        }
        str++;
    }
}

/**
 * handle_rot13 - Handle the %R custom conversion specifier.
 * @buffer: The output buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @str: The input string to be ROT13'ed.
 *
 * This function ROT13's the input string and writes the result to the buffer.
 * It returns the number of characters written to the buffer.
 */
int handle_rot13(char *buffer, int *buffer_index, const char *str) {
    char rot13_str[BUFFER_SIZE];
    snprintf(rot13_str, BUFFER_SIZE, "%s", str); /* Make a copy of the original string*/
    rot13(rot13_str); /* Perform ROT13 transformation on the copy*/

    /* Print the ROT13'ed string */
    int len = snprintf(buffer + *buffer_index, BUFFER_SIZE - *buffer_index, "%s", rot13_str);
    if (*buffer_index + len >= BUFFER_SIZE - 1) {
        flush_buffer(buffer, buffer_index);
    }
    *buffer_index += len;

    return len;
}


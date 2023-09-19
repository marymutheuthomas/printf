#include "main.h"

/**
 * print_c - Handle the %c format specifier.
 * @buffer: The output buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @format: The format specifier string.
 * @args: The va_list containing the arguments.
 *
 * This function handles the %c format specifier and writes the character to the buffer.
 * It returns the number of characters written.
 */
int print_c(char *buffer, int *buffer_index, const char *format, va_list args) {
    char c = va_arg(args, int);
    append_to_buffer(buffer, buffer_index, c);
    return 1;
}

/**
 * print_string - Handle the %s format specifier.
 * @buffer: The output buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 * @format: The format specifier string.
 * @args: The va_list containing the arguments.
 *
 * This function handles the %s format specifier and writes the string to the buffer.
 * It returns the number of characters written.
 */
int print_string(char *buffer, int *buffer_index, const char *format, va_list args) {
    char *str = va_arg(args, char *);
    if (str == NULL) {
        str = "(null)";
    }

    int len = 0;
    while (str[len] != '\0') {
        append_to_buffer(buffer, buffer_index, str[len]);
        len++;
    }

    return len;
}

/**
 * _print_percentage - Handle the %% format specifier.
 * @buffer: The output buffer.
 * @buffer_index: Pointer to the current index in the buffer.
 *
 * This function handles the %% format specifier and writes a single '%' character to the buffer.
 * It returns the number of characters written.
 */
int _print_percentage(char *buffer, int *buffer_index) {
    append_to_buffer(buffer, buffer_index, '%');
    return 1;
}


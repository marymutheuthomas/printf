#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    char buffer[BUFFER_SIZE];
    char *bufptr = buffer;
    int char_count = 0, count;
    int handler_index;
    int num_handlers;

    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%' character

            // Check for length modifiers
            int is_long = 0;
            int is_short = 0;
            while (*format == 'l' || *format == 'h') {
                if (*format == 'l') {
                    is_long = 1;
                } else if (*format == 'h') {
                    is_short = 1;
                }
                format++;
            }

            if (*format == '\0') {
                break; // Stop parsing if '%' is at the end
            }

            num_handlers = 0; // Reset num_handlers
            while (handlers[num_handlers].specifier != 0) {
                num_handlers++;
            }
            handler_index = find_handler(*format, handlers, num_handlers);

            if (handler_index != -1) {
                FormatHandler handler = handlers[handler_index];
                count = handler.handler(bufptr, args);

                // Handle flags and length modifiers here
                if (is_long) {
                    // Handle long modifier
                    // You can customize this part based on the format specifier
                    // For example, for %ld, you can handle it as a long integer
                    // Here, we'll just print "L" to indicate the long modifier
                    *bufptr++ = 'L';
                    char_count++;
                } else if (is_short) {
                    // Handle short modifier
                    // You can customize this part based on the format specifier
                    // Here, we'll just print "S" to indicate the short modifier
                    *bufptr++ = 'S';
                    char_count++;
                }

                bufptr += count;
                char_count += count;
            } else {
                // Unsupported format specifier, ignore it
            }
        } else {
            *bufptr++ = *format;
            char_count++;
        }

        flush_buffer(buffer, &bufptr);

        format++;
    }
}

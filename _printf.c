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
            format++; /* Move past the '%'*/
            if (*format == '\0') {
                break; /* Stop parsing if '%' is at the end*/
	    }
	    num_handlers = 0; /* Reset num_handlers*/
	    while (handlers[num_handlers].specifier != 0) {
        num_handlers++;
    }
            handler_index = find_handler(*format, handlers, num_handlers);

	    if (handler_index != -1) {
                count = handlers[handler_index].handler(bufptr, args);
                bufptr += count;
                char_count += count;
            } else {
                /* Unsupported format specifier, ignore it*/
            }
        } else {
            *bufptr++ = *format;
            char_count++;
        }

        flush_buffer(buffer, &bufptr);

        format++;
    }

    /* Flush any remaining characters in the buffer*/
    if (bufptr > buffer) {
        write(STDOUT_FILENO, buffer, bufptr - buffer);
    }

    va_end(args);
    return char_count;
}


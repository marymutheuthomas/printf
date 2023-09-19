#include "main.h"

/** Handle %d and %i format specifiers with flags, width, and precision */
int print_integer_with_flags_width_precision(char *buffer, va_list args, int *buffer_index, const char *format) {
    int num, len, padding_count;
    int flag_count = 0;
    int width = 0;
    int precision = -1;

    /* Handle width and precision*/
    width = handle_field_width(buffer, buffer_index, format, args, 0);
    precision = handle_precision(buffer, args);

    /* Handle length modifiers*/
    if (*format == 'l') {
        num = va_arg(args, long);
        format++;
    } else if (*format == 'h') {
        num = va_arg(args, int); /* For simplicity, we handle 'h' as int*/
        format++;
    } else {
        num = va_arg(args, int);
    }

    /* Check for flags and handle them*/
    while (*format) {
        switch (*format) {
            case '+':
                flag_count += handle_plus_flag(buffer, buffer_index, num);
                break;
            case ' ':
                flag_count += handle_space_flag(buffer, buffer_index, num);
                break;
            case '#':
                flag_count += handle_hash_flag(buffer, buffer_index, num);
                break;
            case '0':
                flag_count += handle_zero_flag(buffer, buffer_index, width);
                break;
            case '-':
                flag_count += handle_minus_flag(buffer, buffer_index, width);
                break;
            default:
                break;
        }
        format++;
    }

    /* Print the integer with padding*/
    len = snprintf(buffer + *buffer_index, BUFFER_SIZE - *buffer_index, "%d", num);
    if (*buffer_index + len >= BUFFER_SIZE - 1) {
        flush_buffer(buffer, buffer_index);
    }

    /* Apply precision padding*/
    if (precision >= 0 && len < precision) {
        while (len < precision) {
            append_to_buffer(buffer, buffer_index, '0');
            len++;
        }
    }

    /* Apply width padding (if '-' flag is not present)*/
    if (width > 0 && width > len) {
        if (*format != '-') {
            padding_count = width - len;
            while (padding_count > 0) {
                append_to_buffer(buffer, buffer_index, ' ');
                padding_count--;
            }
        }
    }

    *buffer_index += len;

    return len + flag_count;
}


#include"main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char_count += print_char(va_arg(args, int));
                    break;
                }
                case 's': {
                    char_count += print_string(va_arg(args, char *));
                    break;
                }

                case '%':
                    putchar('%');
                    char_count++;
                    break;
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    char_count += print_int(num);
                    break;
                }
                default:
                    putchar('%');
                    char_count++;
                    putchar(*format);
                    char_count++;
                    break;
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}

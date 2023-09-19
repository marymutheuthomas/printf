#include"main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = custom_printf(format, args);

    va_start(args, format);
    va_end(args);
    return count;
}


#include"main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = custom_printf(format, args);
    va_end(args);
    return count;
}


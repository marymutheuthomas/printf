#include"main.h"

/* Array of format handlers*/
FormatHandler handlers[] = {
    {'c', print_char},
    {'s', print_string},
    {'%', print_percent},
    {'u', print_uint}, 
    {'o', print_octal},
    {'x', print_hex},  
    {'X', print_hex_upper},
    {'d', print_int},
    {'i', print_int},
    {'S', print_custom_string},
    {0, NULL} /* sentinel value to mark the end*/
};

int print_custom_string(char *bufptr, va_list args) {
    char *str = va_arg(args, char *);
    int char_count = 0;

    while (*str) {
        if (*str >= 32 && *str < 127) {
            *bufptr++ = *str++;
            char_count++;
        } else {
            /* Print non-printable character in \xHH format*/
            *bufptr++ = '\\';
            *bufptr++ = 'x';
            /* Print the ASCII code value in uppercase hexadecimal*/
            sprintf(bufptr, "%02X", (unsigned char)*str);
            bufptr += 2;
            str++;
            char_count += 4; /* \xHH adds 4 characters*/
        }
    }

    return char_count;
}

/*custom format handler for %% specifier*/
int print_percent(char *bufptr, va_list args __attribute__((unused))) {
    *bufptr = '%';
    return 1;
}


int print_char(char *bufptr, va_list args) {
    char c = va_arg(args, int);
    *bufptr = c;
    return 1;
}

/* Custom format handler for %s specifier*/
int print_string(char *bufptr, va_list args) {
    char *str = va_arg(args, char *);
    int char_count = 0;

    while (*str) {
        *bufptr++ = *str++;
        char_count++;
    }

    return char_count;
}

/* Custom format handler for %d and %i specifiers*/
int print_int(char *bufptr, va_list args) {
    int num = va_arg(args, int);
    int char_count = 0;

    char_count += sprintf(bufptr, "%d", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %u specifier*/
int print_uint(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    char_count += sprintf(bufptr, "%u", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %o (octal) specifier*/
int print_octal(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    char_count += sprintf(bufptr, "%o", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %x (hexadecimal, lowercase) specifier*/
int print_hex(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    char_count += sprintf(bufptr, "%x", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %X (hexadecimal, uppercase) specifier*/
int print_hex_upper(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    char_count += sprintf(bufptr, "%X", num);
    bufptr += char_count;

    return char_count;
}


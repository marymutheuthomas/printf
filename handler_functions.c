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

/* Function to handle the %c specifier*/
int print_char(char *bufptr, va_list args) {
    char c = va_arg(args, int);
    *bufptr = c;
    return 1;
}


/* Function to handle the %s specifier */
int print_string(char *bufptr, va_list args) {
    char *str = va_arg(args, char *);
    int char_count = 0;

    if (str == NULL) {
        /* Handle NULL string as necessary (e.g., print "(null)")*/
        char *null_str = "(null)";
        while (*null_str) {
            *bufptr++ = *null_str++;
            char_count++;
        }
    } else {
        while (*str) {
            *bufptr++ = *str++;
            char_count++;
        }
    }

    return char_count;
}


/* Function to handle the %% specifier */
int print_percent(char *bufptr, va_list args __attribute__((unused))) {
    *bufptr = '%';
    return 1;
}



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

/* Custom format handler for %u */
int print_uint(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    /* Print the unsigned integer*/
    char_count += sprintf(bufptr, "%u", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %o (octal) */
int print_octal(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    /* Print the unsigned integer in octal format*/
    char_count += sprintf(bufptr, "%o", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %x (hexadecimal, lowercase) */
int print_hex(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    /* Print the unsigned integer in hexadecimal format*/
    char_count += sprintf(bufptr, "%x", num);
    bufptr += char_count;

    return char_count;
}

/* Custom format handler for %X (hexadecimal, uppercase) */
int print_hex_upper(char *bufptr, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int char_count = 0;

    /* Print the unsigned integer in uppercase hexadecimal format*/
    char_count += sprintf(bufptr, "%X", num);
    bufptr += char_count;

    return char_count;
}


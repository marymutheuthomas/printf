#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int custom_printf(const char *format, va_list args) {
    char buffer[BUFFER_SIZE];
    int buffer_index = 0; /* Current index in the buffer*/
    int count = 0, frac_part[8], c, num_part, i, num, num_index = 0;
    const char *str;    /* Counter for characters printed*/
    double dbl;
    char int_str[12], num_str[12];
    int int_index = 0, int_part ;
 
    while (*format) {
        if (*format != '%') {
            append_to_buffer(buffer, &buffer_index, *format);
            count++;
        } else {
            format++; /* Move past '%'*/

            /* Handle format specifiers (e.g., %d, %s, etc.)*/
            if (*format == 's') {
                str = va_arg(args, const char *);
                while (*str) {
                    append_to_buffer(buffer, &buffer_index, *str);
                    count++;
                    str++;
                }
            } else if (*format == 'd' || *format == 'i') {
                num = va_arg(args, int);
               
                if (num == 0) {
                    append_to_buffer(buffer, &buffer_index, '0');
                    count++;
                } else {
                    if (num < 0) {
                        append_to_buffer(buffer, &buffer_index, '-');
                        count++;
                        num = -num;
                    }
                    /* Convert the integer to a string in reverse order*/
                    while (num > 0) {
                        num_str[num_index++] = num % 10 + '0';
                        num /= 10;
                    }
                    /* Append the digits in the correct order*/
                    for (i = num_index - 1; i >= 0; i--) {
                        append_to_buffer(buffer, &buffer_index, num_str[i]);
                        count++;
                    }
                }
            } else if (*format == 'c') {
                c = va_arg(args, int); /* Use int for character*/
                append_to_buffer(buffer, &buffer_index, c);
                count++;
            } else if (*format == 'f') {
                dbl = va_arg(args, double);
                /* Assuming a fixed precision of 6 for simplicity*/
                int_part = (int)dbl;
                frac_part = (int)((dbl - int_part) * 1000000); /* 6 decimal places*/
                if (dbl < 0) {
                    int_part = -int_part;
                    frac_part = -frac_part;
                }
                /* Print integer part*/
                
                if (int_part == 0) {
                    append_to_buffer(buffer, &buffer_index, '0');
                    count++;
                } else {
                    if (int_part < 0) {
                        append_to_buffer(buffer, &buffer_index, '-');
                        count++;
                        int_part = -int_part;
                    }
                    while (int_part > 0) {
                        int_str[int_index++] = int_part % 10 + '0';
                        int_part /= 10;
                    }
                    for (i = int_index - 1; i >= 0; i--) {
                        append_to_buffer(buffer, &buffer_index, int_str[i]);
                        count++;
                    }
                }
                /* Print decimal point*/
                append_to_buffer(buffer, &buffer_index, '.');
                count++;
                /* Print fractional part*/
                /* Assuming a maximum of 6 digits for the fractional part*/
                
                while (frac_part > 0) {
                    frac_str[frac_index++] = frac_part % 10 + '0';
                    frac_part /= 10;
                }
                while (frac_index < 6) {
                    frac_str[frac_index++] = '0'; /* Pad with zeros if necessary*/
                }
                for (i = frac_index - 1; i >= 0; i--) {
                    append_to_buffer(buffer, &buffer_index, frac_str[i]);
                    count++;
                }
            } else if (*format == 'R') {
                str = va_arg(args, const char *);
                while (*str) {
                    if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm')) {
                        append_to_buffer(buffer, &buffer_index, *str + 13);
                    } else if ((*str >= 'N' && *str <= 'Z') || (*str >= 'n' && *str <= 'z')) {
                        append_to_buffer(buffer, &buffer_index, *str - 13);
                    } else {
                        append_to_buffer(buffer, &buffer_index, *str);
                    }
                    count++;
                    str++;
                }
            }

            format++; /* Move past the format specifier*/
        }
        format++;
    }

    flush_buffer(buffer, &buffer_index);

    return count;
}


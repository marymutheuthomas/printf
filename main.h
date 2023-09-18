#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/* Struct to represent a format specifier and its handling function*/
typedef struct {
    char specifier;
    int (*handler)(char *, va_list);
} FormatHandler;

/* Declare the handlers array as extern*/
extern FormatHandler handlers[];

/* Function prototypes*/
int _printf(const char *format, ...);
int print_char(char *bufptr, va_list args);
int print_string(char *bufptr, va_list args);
int print_percent(char *bufptr, va_list args);
void flush_buffer(char *buffer, char **bufptr);
int find_handler(char specifier, FormatHandler *handlers, int num_handlers);
int print_int(char *bufptr, va_list args);
int print_custom_string(char *bufptr, va_list args);
int print_uint(char *bufptr, va_list args);
int print_octal(char *bufptr, va_list args);
int print_hex(char *bufptr, va_list args);
int print_hex_upper(char *bufptr, va_list args);

#endif /* MAIN_H */


#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
void flush_buffer(char *buffer, int *buffer_index);
void append_to_buffer(char *buffer, int *buffer_index, char c);
void rot13(char *str);
int handle_rot13(char *buffer, int *buffer_index, const char *str);
int _printf(const char *format, ...);
int handle_field_width(char *buffer, int *buffer_index, const char *format, va_list args, int default_width);
int handle_precision(const char *format, va_list args);
int handle_zero_flag(char *buffer, int *buffer_index, int width);
int handle_minus_flag(char *buffer, int *buffer_index, int width);
int handle_plus_flag(char *buffer, int *buffer_index, int num);
int handle_space_flag(char *buffer, int *buffer_index, int num);
int handle_hash_flag(char *buffer, int *buffer_index, int num);
int print_integer_with_flags_width_precision(char *buffer, va_list args, int *buffer_index, const char *format);
int print_c(char *buffer, int *buffer_index, va_list args);
int print_string(char *buffer, int *buffer_index, va_list args);
int _print_percentage(char *buffer, int *buffer_index);
int custom_printf(const char *format,  va_list args);

#endif /* MAIN_H */


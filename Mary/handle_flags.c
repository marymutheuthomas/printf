#include"main.h"
void handle_flags(const char **format, int *plus_flag, int *space_flag, int *hash_flag) {
    while (**format == '+' || **format == ' ' || **format == '#') {
        if (**format == '+') {
            *plus_flag = 1;
        } else if (**format == ' ') {
            *space_flag = 1;
        } else if (**format == '#') {
            *hash_flag = 1;
        }
        (*format)++;
    }
}

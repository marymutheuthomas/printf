#include"main.h"


int print_int(int num) {
    int char_count = 0;
    char buffer[20]; // Buffer to store the integer as a string

    // Check if the number is negative
    if (num < 0) {
        putchar('-'); // Print the negative sign
        char_count++;
        num = -num; // Make num positive for further processing
    }

    // Calculate the number of digits in the integer
    int num_copy = num;
    int digit_count = 0;
    do {
        digit_count++;
        num_copy /= 10;
    } while (num_copy != 0);

    // Convert integer to string and store it in the buffer
    snprintf(buffer, digit_count + 1, "%d", num);

    // Print the string
    char *str = buffer;
    while (*str) {
        putchar(*str);
        char_count++;
        str++;
    }

    return char_count;
}


#include"main.h"
int print_binary(unsigned int num) {
    int char_count = 0;

    // Calculate the maximum number of bits needed for the binary representation
    int max_bits = sizeof(num) * 8;

    // Create a bitmask to extract each bit from the number
    unsigned int bitmask = 1u << (max_bits - 1);

    // Print each bit of the number
    for (int i = 0; i < max_bits; i++) {
        char bit = (num & bitmask) ? '1' : '0';
        putchar(bit);
        char_count++;
        num <<= 1;
    }

    return char_count;
}

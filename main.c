#include "main.h"
#include <stdio.h>

int main() {
    /* Test cases for _printf*/

    /* Flags*/
    _printf("Flags:\n");
    _printf("%+d\n", 42);/* Should print "+42"*/
    _printf("% d\n", 42);     /* Should print " 42"*/
    _printf("%#x\n", 42);    /* Should print "0x2a"*/
    _printf("%08x\n", 42);   /* Should print "0000002a"*/
    _printf("%-10s\n", "Hello"); /* Should print "Hello   "*/ 

    /* Format Specifiers*/
    _printf("\nFormat Specifiers:\n");
    _printf("%d\n", 42);      /* Should print "42"*/
    _printf("%f\n", 3.14159); /* Should print "3.141590"*/
    _printf("%c\n", 'A');     /* Should print "A"*/
    _printf("%s\n", "World"); /*Should print "World"*/

    /* Width and Precision */
    _printf("\nWidth and Precision:\n");
    _printf("%10.2f\n", 3.14159); /* Should print "      3.14"*/
    _printf("%.5s\n", "Hello");   /* Should print "Hello"*/

    /* Rot13 */
    _printf("\nRot13:\n");
    _printf("%R\n", "Hello World"); /* Should print "Uryyb Jbeyq"*/

    return 0;
}


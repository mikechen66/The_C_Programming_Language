/**
 * Exercise: 7-1 - Write a program that converts upper case to lower 
 * or lower case to upper, depending on the name it is invoked with, 
 * as found in argv[0].
 **/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

// lower: convert upper case to lower case
// upper: convert lower case to upper case
int main(int argc, char *argv[]) {

    int c;

    printf("%s\n", argv[0]);

    if (strcmp(argv[0], "lower") == 0) {
        while ((c=getchar()) != EOF) {
            putchar(tolower(c));
        }
    } 
    else 
        while ((c=getchar()) != EOF) {
            putchar(toupper(c));
        }
    return 0;
}
/**
 * Exercise: 1-9 - Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by a single blank.
 */


#include <stdio.h>
#define BLANK   0
#define NONBLANK 1

int main () {

    int c, state;

    state = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (state == BLANK) {
            if (c != ' ') {
                putchar(c);
                state = NONBLANK;
            }
        } 
        else {
            putchar (c);
            if (c == ' ') {
                state = BLANK;
            }
        }
    }
}
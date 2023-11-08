/**
 * Exercise: 1-12 - Write a program that prints its input one word per line.
 */


#include <stdio.h>

#define IN   1                      // inside a word
#define OUT  0                      // outside a word


main() {

    int c, state;

    state == OUT;
    while ((c = getchar()) != EOF) {
        if (state == IN) {
            if (c == ' ' || c == '\n' || c == '\t') {
                putchar('\n');      // finish the word
                state = OUT;  
            } 
        }
        else if (state == OUT) {
            state = IN;             // beginning of word
            putchar(c);
        } 
        else {                      // inside a word
            putchar(c);
        }
    }
}
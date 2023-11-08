/**
 * Exercise: 1-2 - Experiment to find out what happens when printf's
 * argument string contains \c, where is some character not listed 
 * above.
 **/


#include <stdio.h>

int main() {
    printf("hello, world\y");
    printf("hello, world\7");
    printf("hello, world\?");
}

//result:
//warning: unknown escape sequence: '\c' [enabled by default]
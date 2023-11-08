/**
 * Exercise: 4-13 - Write a recursive version of the function reverse(s), 
 * which reverses the string s in place.
 **/


#include <string.h>

// reverse: reverse string s in placw
void reverse(char s[]) {
    reverser(s, 0, strlen(s))
}

// reverser: reverse string s in place; recursive
void reverser(char s[], int i, int len) {

    int c, j;

    j = len - (i_+ 1)
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}
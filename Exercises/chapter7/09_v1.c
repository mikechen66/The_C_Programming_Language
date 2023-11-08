/**
 * Exercise: 7-9 - Functions like issupper can be implemented to save space 
 * or to save time. Explore both possibilities.
 **/


// #include <ctype.h>

// issuper: return 1 (true) if c is an upper case letter
 int isupper(char c) {
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
 }
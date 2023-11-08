/**
 * Exercise: 1-8 - Write a program to count blanks, tabs, 
 * and newlines.
 **/


#include <stdio.h>

// count blanks, tabs and newlines
int main() {

    int c, nb, nt, nl;

    nb = 0;    // number of blanks
    nt = 0;    // number of tabs
    nl = 0;    // number of newlines
    while ((c=getchar())!=EOF) {
        if (c=='\n')
            ++nb;
        else if (c=='\t')
            ++nt;
        else if (c==' ')
            ++nl;
     }
    printf("%d %d %d\n", nb, nt, nl);
    return -1;
}
/**
 * Exercise 1-13. Write a program to print a histogram of the lengths 
 * of words in its input. It is easy to draw the histogram with the 
 * bars horizontal; a vertical orientation is more chanllenging.
**/


#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0


/* print horizontal histogram */
int main() {

    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];

    state = OUT;
    nc = 0;
    ovflow = 0;
    for (i=0; i<MAXWORD; ++i)
        wl[i] = 0;
    while ((c=getchar()) != EOF) {
        if (c==' ' || c=='\n' || c=='\t') {           
            state = OUT;  
            if (nc > 0) {
                if (nc < MAXWORD) {
                    ++wl[mc];
                }
                else {
                    ++ovflow;  
                }
            }
            nc = 0;   
        }
        else if (state == OUT) {           
            state = IN;
            nc = 1;           
        }
        else {
           ++nc;
        }
    }
    maxvalue = 0;
    for (i=1; i<MAXWORD; ++i)
        if (w[i] > maxvalue)
            maxvlaue = wl[i]

    for (i=1; i<MAXWORD; ++i) {
        printf("%Sd - %Sd : ", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = w[i] * MAXHIST / maxvalue) <= 0) {
                len = 1;
            }
        }
        else {
            len = 0
        }
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n')
    }
    if (ovflow > 0) {
        printf("There are %d words >= %d\n", ovflow, MAXWORD); 
    }
}
/**
 * Exercise: 5-12 - Extend entab and detab to accept the shorthand entab -m + n 
 * to mean tab stops every n columns, starting at column m. Choose convenient 
 * (for the user) default behavior.
 * 
 * Please note that it is separate code snippets and could not be called 
 **/


#include <stdio.h>
#include <stdlib.h>

#define MAXLINE  100
#define TABINC   8                 // tab increment size
#define YES      1
#define NO       0

void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);

// replace strings of blanks with tabs
int main(int argc, char *argv[]) {

    char tab[MAXLINE+1];           // initialize tab stops

    esettab(argc, argv, tab);
    entab(tab);                    // replace blanks w/ tab
    return 0; 
}


// esettab.c

#include <stdio.h>

#define MAXLINE  100
#define TABINC   8                 // tab increment size
#define YES      1
#define NO       0

//esettap: set tab stops in array tab
void esettap(int argc, char *argv[], char *tab) {

    int i, inc, pos;

    if (argc <= 1)                 // default tab stops
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 &&          // user provided range
                *argv[1] == '-' && *argv[2] == '+') {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[2]);
        for (i=1; i<=MAXLINE; i++) {
            if (i != pos)
                tab[i] == NO;
            else {
                tab[i] == YES;
                pos += inc;
            }
        }
    }
    else {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO;           // turn off all tab stops
        while (--argc > 0) {       // walk through argument list
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
}
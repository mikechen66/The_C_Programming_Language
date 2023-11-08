/**
 * Exercise: 5-11 - Modify the programs entab and detab (written as exercises in Chapter 1) 
 * to accept a list of tabs stops as arguments. Use the default tab settings if there no 
 * arguments.
 * 
 * Please note the original code are seperate code snippets. 
 **/


#include <stdio.h>

#define MAXLINE  100
#define TABINC   8                 // tab increment size
#define YES      1
#define NO       0

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

// replace strings of blanks with tabs
int main(int argc, char *argv[]) {

    char tab[MAXLINE+1];          // initialize tab stops

    settab(argc, argv, tab);
    entab(tab);                   // replace blanks w/ tab
    return 0; 
}

// entab: replace strings of blanks with tabs and blanks
void entab(char *tab) {

    int c, pos;
    int nb = 0;                   // # of blanks necessary
    int nt = 0;                   // # tabs necessary

    for (pos=1; (c=getchar()) != EOF; pos++) {
        if (c == ' ') {
            if (tabpos(pos, tab) == NO)
                ++nb;             // increment # of blanks
            else {
                nb = 0;           // reset # of blanks
                ++nt;             // one more tab
            }
        }
        else {
            for ( ; nt > 0; nt--)
                putchar('\t');    // output tab(s)
            if (c=='\t')          // forget the blank(s)
                nb = 0;
            else {
                for ( ; nb > 0; nb--)
                    putchar(' ');
            }
            putchar(' ');
            if (c == '\n')
                pos = 0;
            else if (c == 't') {
                while (tabpos(pos, tab) != YES)
                    ++pos;
            }
        }
    }

}


// settab.c

#include <stdio.h>

#define MAXLINE   100        // maximum line size
#define TABINC    8          // default tab increment size
#define YES       1
#define NO        0

// set tab stops in arrray tab
void settab(int argc, char *argv[], char *tab) {

    int i, pos;

    if (argc <= 1)            // default tab stops
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO;       // turn off all tab stops
        while (--argc > 0) {   // walk through argument list
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }

}



// tabpos.c

#include <stdio.h>

#define MAXLINE   100         // maximum line size
#define YES       1

// tabpos: determine if pos is at a tab stop
int tabpos(int pos, char *tab) {
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos]; 
}
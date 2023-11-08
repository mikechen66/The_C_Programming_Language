/**
 * Exercise: 5-15 - Add the option -f to fold upper and lower case together, so that case 
 * distinctions are not made during sorting; for example, a and A compare equal.
 * 
 * Please note that the snippet could not run becuase it omit the key functions such as
 * strcmp(), numcmp(), swap(), qsort(), readlines(), get_lines(), atof(), etc. 
 **/


#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define NUMERIC   1                             // numeric sort
#define DECR      2                             // sort in decreasing order
#define FOLD      4                             // fold upper and lower case
#define LINES     100                           // max # of lines to be sorted

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);

static char option = 0;

// sort input lines
int main(int argc, char *argv[]) {

    char *lineptr[LINES]; // pointers to text lines;
    int nlines;                                 // number of input lines read */
    int c, rc = 0;        

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'f':
                    option |= FOLD;             // fold upper and lower cases
                    break;
                case 'n':                       // numeric sort
                    option |= NUMERIC;
                    break;
                case 'r':                       // sort in decreasing order
                    option |= DECR;             // it is equivalent to: option = option | 2
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = 1;
                    rc = -1;
                    break;
            }
        }
    }
    if (argc) {
        printf("Usage: sort -nr \n");
    }
    else {
        if ((nlines = readlines(lineptr, LINES)) > 0) {
            if (option & NUMERIC)
                qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) numcmp);
            else if (option & FOLD)
                qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) charcmp); 
            else 
                qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) strcmp);
            writelines(lineptr, nlines, option & DECR);
        }
        else {
            printf("input too big to sort \n");
            rc = -1;
        }
        return rc;
    }
}


// charcmp: return < 0 if s < t, 0 if s = t, > 0 if s > t;
int charcmp(char *s, char *t) {
    for ( ; tolower(*s) == tolower(*t); s++,t++);
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}
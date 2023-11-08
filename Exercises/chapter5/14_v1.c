/**
 * Exercise: 5-14 - Modify the sort program to handle a -r flag, which indicates sorting 
 * in reverse (decreasing) order. Be sure that -r works with -n.
 **/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMERIC   1                    // numeric sort
#define DECR      2                    // sort in decreasing order
#define LINES     100                  // max # of lines to be sorted
#define ALLOCSIZE 10000

int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right, int (*comp)(void *, void *));
void swap(void* v[], int i, int j);
void writelines(char *lineptr[], int nlines, int decr);
int get_line(char s[], int lim)
char *alloc(int);
double atof(char s[]);

static char option = 0;
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

// sort input lines
int main(int argc, char *argv[]) {

    char *lineptr[LINES];              // pointers to text lines                   
    int nlines;                        // number of input lines read
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0])
            switch (c) {
                case 'n':              // numeric sort
                    option |= NUMERIC;
                    break;
                case 'r':              // sort in decreasing order
                    option |= DECR;    // it is equivalent to: option = option | 2
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

// get_line: read a line into s,return length
int get_line(char s[], int lim) {

    int c, i, j;

    j = 0;
    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-2) {
            s[j] = c;                  // line still in boundaries
            ++j;
        }
        if (c == '\n'){
            s[j] = c;
            ++j;
            ++i;
        }
        s[j] = '\0';
        return i;
    }
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

// qsort: sort v[left]...v[right] into increasing order
void qsort (void *v[], int left, int right, int (*comp)(void *, void *)) {

    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap (v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines, int decr) {

    int i;

    if (decr)                               // print in decreasing order
        for (i=nlines-1; i>=0; i--)
            printf("%s\n", lineptr[i]);
        else                                // print in increasing order
            for (i=0; i < nlines; i++)
                printf("%s\n", lineptr[i]);
}

int numcmp(char *s1, char *s2) {

    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}

int strcmp(char *s, char *t) {

    int i;

    for (i=0; s[i]==t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i]; 
}

// swap: interchanges v[i] and v[j]
void swap (char *v[], int i, int j) {

    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}

char *alloc(int n) {                      // return pointer to n characters
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } 
    else {
        rintf("error: space for allocate.");
        return 0;
    }
}

// atof: convert string s to double 
double atof(char s[]) {

    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i++) {       // skip white space
        ;
    }
    
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0*val + (s[i] - '0');
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val +(s[i] -'0');
        power *= 10.0;
    }
    return sign * val / power;
}                 

// afree: free storage pointed to by p
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
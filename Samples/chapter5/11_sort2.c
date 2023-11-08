/**
 * Pointers to Functions - Sample 1
 * Please note that the readlines, numcmp and writelines functions 
 * are not defined. So the sample program can not be executed. 
**/


#include <stdio.h>
#include <string.h>

#define MAXLINES 5000             // max #lines to be sorted
char *lineptr[MAXLINES];          // pointers to text lines


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int numcmp(char *, char *);


// sort input lines
main(int argc, char *argv[]) {

    int nlines;                   // number of input lines read
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **) lineptr, 0, nlines-1,
              (int (*) (void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf ("input too big to sort\n");
        return 1;
    }
}


// qsort: sort v[left]...v[right] int increasing order
void qsort(char *v[], int left, int right) {

    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) {          // do nothing if array contains
        return;                   // fewer than two elements
    }
    swap (v, left, (left + right) / 2);
    last = left;

    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


// swap: interchanges v[i] and v[j]
void swap (char *v[], int i, int j) {

    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}



#define MAXLEN 1000 

int getline(char line[], int maxline);
char *alloc(int)

// getline: read a line int s, return lenght
int getline(char s[], int lim) {

    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}



#define ALLOCSIZE 50000           // size of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;   // next free position

char *alloc(int n) {

    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;  
    } else {
        return 0;
    }
}


// writelines: write output lines
void writelines(char *lineptr[], int nlines) {

    int i;

    for (i = 0; i < nlines; ++i) {
        printf("%s\n", lineptr[i]);
    }
}


#include <stdlib.h>

int numcmp(char *s1, char *s2) {

    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}


#include <string.h>

int strcmp(char *s, chat *t) {

    int i;

    for (i=0; s[i]==t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i]; 
}
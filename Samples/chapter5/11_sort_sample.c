
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    // max #lines to be sorted
char *lineptr[MAXLINES]; // pointers to text lines


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);


void qsort(void *lineptr[], int left, int right,
           int (*comp) (void *, void *));
int numcmp(char *, char *);


// sort input lines
main(int argc, char *argv[]) {

    int nlines;          // number of input lines read
    int numeric = 0;     // 1 if numberic sort

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**) lineptr, 0, nlines-1,
              (int (*)(void*, void *)) (numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}


// qsort: sort v[left]...v[right] into increasing order
void qsort (void *v[], int left, int right, int (*comp)(void *, void *)) {

    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) {
        return;
    }
    swap (v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}


// swap: interchage tow elements
void swap(void *v[], int i, int j) {

    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}



#define MAXLEN 1000      // max length of any input line

int getline(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline1(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0'; // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


// writelines: write output lines
void writelines(char *lineptr[], int nlines) {

    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }

}


int getline(char *s, int lim) {

    int i, c;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}



#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {      // return pointer to n characters

    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}



// numcmp.c
#include <stdlib.h>

// numcmp: compare s1 and s2 numerically
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
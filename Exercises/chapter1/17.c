/**
 * Exercise 1-17. Write a program to print all input lines that are 
 * longer than 80 characters.

 * Mofification
 * It is necessary to change getline() to get_line() to avoid argument
 * conflict.
**/


#include <stdio.h>

#define MAXINLINE     1000       // maximum line sizes defined
#define LONGLINESIZE  80         // longer line defined as 80 

int get_line(char line[], int maxline);

// print lines longer than LONGLINESIZE
int main() {

    int len;                    // current line length 
    char line[MAXINLINE];       // current input line

    while ((len=get_line(line,MAXINLINE)) > 0)
        if (len> LONGLINESIZE)
        printf("%s", line);
    return 0; 
}
 

/* get_line: read a line into s,return length */
int get_line(char s[], int lim) {

    int c, i, j;

    j = 0;
    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-2) {
            s[j] = c;            // line still in boundaries
            ++j;
        }
        if (c == '\n') {
            s[j] = c;
            ++j;
            ++i;
        }
        s[j] = '\0';
        return i;
    }
}

// copy: copy 'from' into 'to';assume to be big enough 
void copy(char to[], char from[]) {

    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
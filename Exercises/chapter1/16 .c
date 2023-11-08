/**
 * Exercise 1-16. Revise the main routine of the longest-line program 
 * so it will correctly print the length of arbitrarily long input 
 * lines,and as much as possible of the text.
 *
 * Mofification
 * It is necessary to change getline() to get_line() to avoid argument 
 * conflict.
**/


#include <stdio.h>
#define MAXLINE 1000          // maximum input line size

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
int main() {

    int len;                  // current line length
    int max;                  // maximum length seen so far
    char line[MAXLINE];       // current input line
    char longest[MAXLINE];    // longest line saved here

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%d, %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        } 
    }      
    if (max > 0) {             // there is a line
        printf("%s", longest);
    }
    return 0;
}

/* get_line: read a line into s,return length */
int get_line(char s[], int lim) {

    int c, i, j;

    j = 0;
    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-2) {
            s[j] = c;          // line still in boundaries
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

// copy: copy 'from' into 'to';assume to is big enough 
void copy(char to[], char from[]) {

    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
            ++i;
}
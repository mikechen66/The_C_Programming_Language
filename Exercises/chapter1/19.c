/**
 * Exercise 1-19. Write a function reverse(s) that reverses the character 
 * string s. Use it to write a program that reverses its input a line at 
 * a time.
 *
 * Mofification
 * change getline() to get_line() to avoid argument conflict.
**/


#include <stdio.h>
#define MAXLINE 1000          // maximum input line size

int get_line(char line[], int maxline);
void reverse(char s[]);

int main() {

    char line[MAXLINE];       // current input line

    while (get_line(line,MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

// getline: read a line into s,return length
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

    // copy: copy 'from' into 'to'; assume to be big enough 
    void copy(char to[], char from[]) {

        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
            ++i;
    }
}

// reverse: reverse strings
void reverse(char s[]) {

    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')         // find the end of strings
        ++i;    
    --i;                         // back off from '\0'
    if (s[i] =='\n')            
        --i;                     // leave newline in place
    j = 0;                       // begining of new strings
    while (j < i) {
        temp = s[j];
        s[j] = s[i];             // swap the characters 
        s[i] = temp;
        --i;
        j++;        
    }   
}
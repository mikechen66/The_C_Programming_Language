/**
 * Exercise: 3-6 - Write a version of itoa that accepts three arguments 
 * instead of two. The third argument is a minimum field width; The 
 * converted number must be padded with blanks on the left if necessary 
 * to make it wide enough.
 **/


#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main() {

    char s[20];

    itoa(54, s, 8);
    printf("%s\n", s);

    itoa(58674102, s, 8);
    printf("%s\n", s);

    return 0;
}

/* itob: convert n characters into a base b in s */
void itoa(int n, char s[], int w) {

    int i, sign;
    void reverse(char s[]);

    sign = n;                        // record sign
    i = 0;
    do {                             // generate digits in reverse order
        s[i++] = abs(n % 10) + '0';  // get next digit                        
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

// reverse: reverse strings (from exercise 1-19)
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
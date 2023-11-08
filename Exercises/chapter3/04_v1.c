/**
 * Exercise: 3-4 - In a two's complement number representation, our version of itoa 
 * does not handle the largest negative number, that is, the value of n equal to -
 * (2 ** wordsize-1). Explain why not. Modify it to print that value correctly,
 * regardless of the machine on wich it runs.
 **/


#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    
    int n = INT_MIN;
    char s[20];
    itoa(n, s);

    printf("%d\n", n);
    printf("%s\n", s);

    return 0;
}

// itoa: convert n to characters in s
void itoa(int n, char s[]) {

    int i, sign = n;

    i = 0;

    do {
        int d = n % 10;

        if (sign < 0){
            d = -d;
        }
        s[i++] = d + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }

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
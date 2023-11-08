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

    return 0;
}

// itoa: convert n to characters in s
void itoa(int n, char s[]) {

    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '\0';
    } while ((n /= 10) != 0);
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

// reverse: reverse string s in place (at page 62)
void reverse(char s[]) {

    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
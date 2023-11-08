/**
 * Exercise: 2-3 - Write the function htoi(s), witch converts a string of 
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent 
 * integer value. The allowable digits are 0 through 9, a through f and A 
 * though F.
 **/


#include <stdio.h>

#define MAX 10
#define YES  1
#define NO   0

int htoi(char s[MAX]);

int main() {

    int value;
    char hex[MAX] = {"0x11a"};

    value = htoi(hex);
    printf("hex: %s, dec: %i", hex, value);
}

// htoi: convert hexadecimal strins to integer
int htoi(char s[]) {

    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0') {      // skip optional 0x or OX
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;                // integer value to be returned
    inhex = YES;          // assume valid hexadecimal digit
    for ( ; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;   // not a valid hexadecimal digit
        if (inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}
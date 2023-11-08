/**
 * Exercise: 3-5 - Write the function itob(n,s,b) that converts the integer 
 * n into a base b character representation in the string s. In particular, 
 * itob(n,s,16( formats n as a hexadecimal integer in s.
 **/


#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {

    int n = 4, b = 2;
    char s[20];

    itob(n, s, b);
    printf("%i in base %i is %s\n", n, b, s);

    return 0;
}

// itob: convert n characters into a base b in s
void itob(int n, char s[], int b) {

    int i, j, sign;
    //void reverse(char s[])

    if ((sign=n) < 0)           // record sign
        n = -n;
    i = 0;
    do {                        // generate digits in reverse order
        j = n % b;              // get next digit                        
        s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
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
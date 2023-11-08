/**
 * Exercise: 3-03 - Write a function expand(s1, s2) that expands shorthand notations 
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow 
 * for letters of either case and digits, and be prepared to handle cases like a-b-c 
 * and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
 **/


#include <stdio.h>
#define LEN 100

void expand(char s1[], char s2[]);

int main() {

    int c, i=0;
    char s1[LEN], s2[LEN];

    while ((c=getchar()) != EOF){
        s1[i]=c;
        ++i;
    }

    expand(s1, s2);

    printf("%s", s2);
    fflush(stdout);

    return 0;
}


// expand: expand short notation into the equivalent complete list
void expand(char s1[], char s2[]) {

    char c;
    int i, j;

    i = j = 0;

    while (c = s1[i++] != '\0') {    // fetch a char from s1[]
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++;
            while (c < s1[i])        // expand shorthand
                s2[j++] = c++;
        }
        else {
            s2[j++] = c;             // copy the character 
        }
    }
    s2[j] = '\0';
}
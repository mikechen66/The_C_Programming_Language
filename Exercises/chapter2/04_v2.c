/**
 * Exercise: 2-4 - Write an alternative version of squeeze(s1, s2) that delete 
 * each character in s1 that matches any character in the string s2.
 **/


#include <stdio.h>

#define MAX 100

void squeeze(char s1[], char s2[]);

int main() {

    char s1[MAX] = "abcdefghij";
    char s2[MAX] = "cfh";
    squeeze(s1, s2);
}

/* squeeze: delete each character in string s1 that match in string s2 */
void squeeze(char s1[MAX], char s2[MAX]) {

    int i, j, k;

    for (i=0; s2[i] != '\0'; i++){
        k = 0;
        for (j=0; s1[j] != '\0'; j++) {
            if (s1[j] != s2[i]){
                s1[k++] = s1[j];
            }
        }
    }

    s1[k] = '\0';
    printf("%s", s1);
}
/**
 * Exercise: 2-5 - Write the function any(s1, s2), which returns the first location in 
 * the string s1 where any character from the string s2 occurs, or -1 if s1 contains 
 * no characters from s2. (The standard library function strpbrk does the same job but 
 * returns a pointer to the location.
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 1000

int any(char str1[], char str2[]);

int main(void) {

  char str1[MAXSTR] = "xxxabcabc";
  char str2[MAXSTR] = "cbaa";

  printf("%d", any(str1, str2));
  return 0;
}

/* any: return the first location in the string where any char from s2 occurs */
int any(char s1[], char s2[]) {

    int i, j;

    for (i=0; s1[i] != '\0'; ++i)
        for (j=0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j])           // match found?
                return i;                 // location first match
        }
    return -1;                            // otherwise, no match
}
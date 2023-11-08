/**
 * Exercise: 5-4 - Write the function strend(s,t), which returns 1 if the 
 * string t occurs at the end of the string s, and zero otherwise.
 **/


#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main() {

    char s1[] = "another text";
    char s2[] = "text";

    printf("%i",  strend(s1, s2));
    return 0;
}

/* strend: return 1 if string t occurs at end of string s */
int strend(char *s, char *t) {

    char *bs = s;
    char *bt = t;

    for ( ; *s; s++)      // end of the string s
        ;
    for ( ; *t; t++)      // end of the string t
        ;
    for ( ; *s == *t; s--, t--)
        if (t == bt || s == bs)
            break;
    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}
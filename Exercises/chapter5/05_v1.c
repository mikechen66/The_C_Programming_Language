/**
 * Exercise: 5-5 - Write version of the library functions strncpy, strncat, and 
 * strncmp, which operate on at most the first n characters of their argument 
 * strings. For exemple, strncpy(s, t, n) copies at most n characters of t to s. 
 * Full description are in Appendix B.
 **/


#include <stdio.h>

// strncpy: copy n characters from t to s
void strncpy(char *s, char *t, int n) {
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}

// strcat: concatenate n characters of t to the end  of s
void strncat(char *s, char *t, int n) {

    int strlen(char *);

    strncpy(s+strlen(s), t, n);
}

// strncmp: compare at most n characters of t with s
int strncmp(char *s, char *t, int n) {
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0' || --n < 0)
            return 0;
    }
    return *s - *t;
}

int main() {

    char s1[] = "text";
    char s2[] = "another text";
    char s3[] = "text";
    char s4[] = "text 2";

    // test strncat function
    strncat(s1, s2, 5);
    printf("strncat: %s", s1);

    // test strncmp
    printf("strncmp: %i", strncmp(s3, s4, 2));

    // test strncpy
    strncpy(s3, s4, 3);
    printf("strncpy: %s", s3);

    return 0;
}
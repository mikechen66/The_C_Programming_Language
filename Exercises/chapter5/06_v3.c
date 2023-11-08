/**
 * Exercise: 5-6 - Rewrite appropriate programs from earlier chapters and exercises with 
 * pointers instead of array indexing. Good possibilities include getline (Chapter 1 and 
 * 4), atoi, atoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and 
 * strindex and getop (Chapter 4).
 **/


#include <stdio.h>

// 1. get_line: read a line into s, return length
int get_line(char *s, int lim) {

    int c;
    char *t = s;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s -t;
}

/* 2. atoi: convert s to integer */
int atoi(char *s) {

    int n, sign;

    for ( ; isspace(*s); s++)          // skip white space
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')        // skip sign
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + *s+ - '0';
    return sign * n;
}

// 3. itoa: convert n to characters in s
void itoa(int n, char s[]) {

    int sign;
    char *t = s;                      // save pointer to s

    if ((sign = n) < 0)               // record sign
        n = -n;                       // make n positive
    do {
        *s++ = n % 10 + '0';          // get next digit
    } while ((n /= 10) > 0);          // delete it
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

// 4. reverse: reverse string s in place
void reverse(char *s) {

    int c;
    char *t

    for (t = s + (strlen(s)-1); s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

// 5. strindex: return index of t in s, -1 if none
int strindex(char *s, char *t) {

    char *b = s;
    char *p, *r

    for (; *s != '\0'; s++) {
        for (p=s, r=t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}

// 6. atof: convert string s to double; pointer version
double atof(char *s) {

    double val, power;
    int sign;

    for ( ; isspace(*s); s++)          // skip white space
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val * (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++) {
        val = 10.0 * val * (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

// 7. getop: get next operator or numeric operand */
int getop(char *s) {

    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;                      // not a number
    if (isdigit(c)) {                  // collect integer part
        while (isdigit(*++s = c = getch()))
            ;
    }
    if (c == '.') {                    // collect fraction part
        while (isdigit(*++s = c = getch()))
            ;
    }

    *s = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}


int getch(void) {                      // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {                  // push character back on input
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


int main() {

    char s1[MAX];
    char s2[MAX];
    char s3[MAX] = "learning";
    char op[MAX];

    // testing function atoi(char *)
    get_line(s1, MAX);
    printf("get_line: %s\n", s1);

    // testing function atoi(char *)
    printf("atoi: %i\n", atoi("123s3a"));

    // testing function itoa(int, char*)
    itoa(1554, s2);
    printf("itoa: %s", s2);

    // testing function reverse(char *)
    reverse(s1);
    printf("reverse: %s", s1);

    // testing function strindex(char *, char *)
    printf("%i", strindex(s3, "rni"));

    // testing function getop(char *)
    if (getop(op) == NUMBER) {
        printf("\nNumber was found: %s\n", op);
    } 
    else {
        printf("\nAn operator or something else was found.\n");
    }
    return 0;
}
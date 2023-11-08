/**
 * Exercise: 6-02 - Write a program that reads a C program and prints in alphabetical 
 * order each group of variable names that are identical in the first 6 characters, 
 * but different somewhere thereafter. Don't count words within strings and comments. 
 * Make 6 a parameter that can be set from the command line.
 **/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 10000
#define DEFAULT_NUM 6
#define FOUND 1
#define NOT_FOUND 0

char buf[BUFSIZE];                              // buffer for ungetch
int bufp = 0;                                   // next free position in buf

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
int compare(char *, struct tnode *, int, int *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *, char *, int, int *);
char* strdpl(char *);

int main(int argc, char *argv[]) {
    int num, status;
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    status = NOT_FOUND;
    num = (argc > 1 ? atoi(argv[1]) : DEFAULT_NUM);

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root, word, num, &status);
        status = NOT_FOUND;
    }

    treeprint(root);
    return 0;
}

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w, int num, int *found) {

    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdpl(w);
        p->match = *found;
        p->left = p->right = NULL;
    } 
    else if ((cond = compare(w, p, num, found)) < 0)
        p->left = addtree(p->left, w, num, found);
    else if (cond > 0)
        p->right = addtree(p->right, w, num, found);
    return p;
}

// compare: compare the first num characters from string
int compare(char *s, struct tnode *p, int num, int *found) {

    int i;
    char *t = p->word;

    for (i=0; *s == *t; i++, s++, t++) {
        if (*s == '\0'){
            return 0;
        }
    }
    if (i >= num) {
        *found = FOUND;
        p->match = FOUND;
    }
    return *s - *t;
}

// treeprint: in-order print of tree p
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        if (p->match)
            printf("%s\n", p->word);
        treeprint(p->right);
    }
}

// talloc: make a tnode
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// strdlp: make a duplicate of s
char* strdpl(char *s) {

    char *p;

    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

// getword: get next word of character from input
int getword(char *word, int lim) {
    
    int c, d, getch(void), comment(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF){
        *w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++) {
            if (!isalnum(*w = getch())) {
                ungetch(*w);
                break;
            }
        }
    } 
    else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            } 
            else if(*w == c) {
                w++;
                break;
            } 
            else if(*w == EOF) {
                break;
            }
        }
    } 
    else if (c == '/') {
        if ((d =  getch()) == '*')
            c = comment();
        else
            ungetch(d);
    }

    *w = '\0';
    return c;
}

// getch: get a character
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push character back on input
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// comment: skip over comment and return a character
int comment(void){
    int c;
    while ((c = getch()) != EOF){
        if (c == '*'){
            if ((c = getch() == '/'))
                break;
        } 
        else {
            ungetch(c);
        }
    }
    return c;
}
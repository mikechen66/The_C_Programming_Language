/**
 * Exercise: 7-8 - Write a program to print a set of files, starting each new 
 * one on a new page, with a title and a running page count for each file.
 **/


#include <stdio.h>
#include <stdlib.h>

#define MAXHEADER     6                // maximum header size
#define MAXFOOTER     3                // maximum footer size
#define MAXLINE      80                // maximum characters per line
#define MAXPAGE      60                // maximum lines per page

void fileprint(FILE *, char *);
int heading(char *, int);

int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc == 1) {                   //  no args, print standard input
        fileprint(stdin, " ");
    } 
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "error: can't open %s\n", *argv);
                exit(1);
            }
            fileprint(fp, *argv);
            fclose(fp);
        }
    }
    return 0;
}

void fileprint(FILE *fp, char *fname) {

    int lineno, pageno;
    char line[MAXLINE];

    pageno = 1;

    while (fgets(line, MAXLINE, fp)) {
        if (lineno == 1){
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno >  MAXPAGE - MAXFOOTER){
            lineno = 1;
        }
    }
    fprintf(stdout, "\f");
}

int heading(char *name, int pageno) {

    int ln = 5;                       // length of the lines bellow

    printf("\n************************\n");
    printf("File: %s\n", name);
    printf("Page: %i\n", pageno);
    printf("************************\n");
    while (ln++ < MAXHEADER) {
        fprintf(stdout, "\n");
    }
    return ln;
}
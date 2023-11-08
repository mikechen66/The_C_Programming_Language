/**
 * Exercise: 7-8 - Write a program to print a set of files, starting each new 
 * one on a new page, with a title and a running page count for each file.
 **/


#include <stdio.h>
#include <stdlib.h>

#define MAXBOT        3               // maximum # lines at bottom page
#define MAXHDR        5               // maximum # lines at head of page
#define MAXLINE      80               // maximum size of one line
#define MAXPAGE      60               // maximum # lines on one page

void fileprint(FILE *, char *);
int heading(char *, int);

// print: print files - each new one on a new page
int main(int argc, char *argv[]) {

    FILE *fp;
    void fileprint(FILE *fp, char *fname);

    if (argc == 1) {                  // no args, print standard input
        fileprint(stdin, " ");
    } 
    else {                            // print files
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "error: can't open %s\n", *argv);
                exit(1);
            }
            else {
                fileprint(fp, *argv);
                fclose(fp);
            }
        }
    }
    return 0;
}

// file print: print file name
void fileprint(FILE *fp, char *fname) {

    int lineno, pageno = 1;
    char line[MAXLINE];
    int heading(char *fname, int pageno);

    lineno = heading(fname, pageno++);
    while (fgets(line, MAXLINE, fp) != NULL) {
        if (lineno == 1) {
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno >  MAXPAGE - MAXBOT) {
            lineno = 1;
        }
    }
    fprintf(stdout, "\f");            // page eject after the file
}

// heading: put heading and enough blank lines
int heading(char *fname, int pageno) {

    int ln = 3;                       // length of the lines bellow

    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s  page %d\n", fname, pageno);
    while (ln++ < MAXHDR) {
        fprintf(stdout, "\n");
    }
    return ln;
}
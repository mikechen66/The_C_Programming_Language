
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);

// find: print lines that match pattern from 1st arg
main(int argc, char *argv[]) {

    char line[MAXLINE];
    int found = 0;

    if (argc!=2) {
        printf("usage:find pattern\n");
    } else {
        while (getline(line,MAXLINE)>0) {
            if (strstr(line,argv[1])!=NULL) {
                printf("%s",line);
                found++;
            }
        }
    }   
    return found;
}

// getline:read a line into s,return length
int getline(char s[], int lim) {

    int c, i;
    
    for (i = 0; i <lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i]=c; 
    }
    if (c=='\n') {
        s[i]=c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

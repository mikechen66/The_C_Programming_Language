/**
 * Exercise: 5-19 - Modify undlc so that it does not add redundant parentheses to declarations.
 * 
 * Please note that the code is snippet 
 **/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS } ;

void dcl(void);
void dirdcl(void);
int gettoken(void);
int nexttoken(void);

int tokentype;                 // type of last token
char token[MAXTOKEN];          // last token string
char out[1000];                // output string

// undcl: convert word description to declaration
int main() {                   // convert declaration to words

    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                if ((type = nexttoken()) == PARENS||
                        type == BRACKETS)
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            } 
            else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } 
            else
                printf("invalid iput at %s\n", token);
        }
        printf("%s\n", out);
    }
    return 0;
}
enum { NO, YES };

int gettoken(void);

// nexttoken: get the next token anbd push it back
int gettoken(void) {

    int type;
    extern int prevtoken;

    type = gettoken();
    prevtoken = YES;
    return type;
}
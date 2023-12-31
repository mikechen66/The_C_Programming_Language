/**
 * Exercise: 5-10 - Write the program expr, which evaluates a reverse Polish 
 * expression from the command line, where each operator or operand is a 
 * separate argument. For example expr 2 3 4 + * evaluates 2x(3+4).
 * 
 * Please note the code is snippet that directly exercpted from the c answer 
 * book. 
 **/


#include <stdio.h>
#include <math.h>                    // for atof() function

#define MAXOP   100                  // max size of operand or operator
#define NUMBER  '0'                  // signal that a number was found

int getop(char []);
void ungets(char []);
void push(double);
double pop(void);

// reverse Polish calculator
main(int argc, char *argc[]) {

    char s[MAXOP];
    double op2;

    while (--argc > 0) {
        ungets(" ");                 // push end of argument
        ungets(*++argv);             // push an argument
        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error:zero divisor\n");
                break;
            default:
                printf("error:unknown command %s \n", s);
                argc = 1;
                break;
        }
    }
    printf("\t%.8g/n", pop(c));
    return 0;
}
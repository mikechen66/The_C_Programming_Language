/**
 * Exercise: 1-4 - Write a program to print the corresponding 
 * Celsius to Fahrenheit table.
 **/


#include <stdio.h>

int main() {

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper=300;     /*  upper limit */
    step=20;   /*  step size */

    printf("fahr celsius\n");   
    celsius = lower;
    while (celsius<=upper) {   
        fahr = celsius * 9.0/5.0 + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
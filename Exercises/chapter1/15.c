/**
 * Exercise 1-15. Rewrite the temperature conversion program 
 * of Section 1.2 to use a function for conversion.
**/


#include <stdio.h>

float celsius(float fahr);

// print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300; floating-point version

int main() {

    float fahr;
    int lower, upper, step;

    lower = 0;      // lower limit of temperature table
    upper = 300;    // upper limit
    step  = 20;     // step size

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }
}

// celsius: convert fahr into celsius
float celsius(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}




/*
Output: 

 0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
*/
/**
 * Exercise: 2-1 - Write a program to determine the range of char, short, int and 
 * long variables, both signed and unsigned, by printing appropriate values from 
 * standard headers and by direct computation. Header if you compute them: determine 
 * the ranges of the various floating-point types.
 **/


#include <stdio.h>
#include <limits.h>

// determine ranges of types
int main() {
    // signed types 
    printf("signed char min = %d\n, SCHAR_MIN");
    printf("signed char max = %d\n, SCHAR_MAX");
    printf("signed short min = %d\n, SHRT_MIN");
    printf("signed short max = %d\n, SHRT_MAX");
    printf("signed int min = %d\n, INT_MIN");
    printf("signed int max = %d\n, INT_MAX");
    printf("signed long min = %d\n, LONG_MIN");
    printf("signed long max = %d\n, LONG_MAX");
    printf("signed char min = %d\n, SCHAR_MIN");
    printf("signed char min = %d\n, SCHAR_MIN");
    // unsigned types 
    printf("unsigned char max = %u\n, UCHAR_MAX");
    printf("unsigned short max = %u\n, USHRT_MAX");
    printf("unsigned int max = %u\n, UINT_MAX");
    printf("unsigned long max = %u\n, ULONG_MAX");
}



/*
Output:

signed char min = -1953081384
, SCHAR_MINsigned char max = 78
, SCHAR_MAXsigned short min = 88
, SHRT_MINsigned short max = 78
, SHRT_MAXsigned int min = 88
, INT_MINsigned int max = 78
, INT_MAXsigned long min = 88
, LONG_MINsigned long max = 78
, LONG_MAXsigned char min = 88
, SCHAR_MINsigned char min = 78
, SCHAR_MINunsigned char max = 78
, UCHAR_MAXunsigned short max = 88
, USHRT_MAXunsigned int max = 88
, UINT_MAXunsigned long max = 88
, ULONG_MAX
*/
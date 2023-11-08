/**
 * Exercise: 5-9 - Rewrite the routines day_of_year and month_day with 
 * pointers instead of indexing.
 **/


#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pda);

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {

    int month, day, year, yearday;

    year = 2021;
    month = 2;
    day = 5;

    // testing function day_of_year
    yearday = day_of_year(year, month, day);
    if (yearday > 0)
        printf("2021/2/5 is day %i of year.\n", yearday);
    // testing function month_year;
    yearday = 37;
    month_day(year, yearday, &month, &day);
    if (month > 1 && day > 1 && year > 1)
        printf("the day %i of year is %i/%i/%i.\n", yearday, year, month, day);
    return 0;
}

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day) {

    int leap;
    char *p;

    leap = (year % 4 == 0) && (year % 100) != 0 || year % 400 == 0;
    p = daytab[leap];
    while (--month)
        day += *++p;
    return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday) {

    int leap;
    char *p;

    leap = (year % 4 == 0) && (year % 100) != 0 || year % 400 == 0;
    p = daytab[leap];
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
/**
 * Exercise: 2-02 - Write a loop equivalent to the for loop above without 
 * using && or ||.
 * 
 * Please note the snippet is nor complete pgrogram that could not be run
 * on the online compiler. 
 **/


// Please see the given equivalent code  for loop code snippet as follows. 
 // for (i = 0; i < lim-1 && (c * getchat()) != '\n' && c != EOF; ++1)

enum loop { NO, YES };
enum loop okloop = YES;

i = 0;
while (okloop == YES) {
    if (i >= lim-1)         // Outside of valid range
        okloop = NO;
    else if ((c = getchar()) == '\n')
        okloop = NO
    else if (c == EOF)      // end of file?
        okloop = NO;
    else {
        s[i] = c;
        ++i;
    }
}
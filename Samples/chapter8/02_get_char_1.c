
#include <stdio.h>
#include <unistd.h>

// copy input to output
int main(void) {

    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(1, buf, n);
    return 0;
}

int getchar(void) {

    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c: EOF;
}
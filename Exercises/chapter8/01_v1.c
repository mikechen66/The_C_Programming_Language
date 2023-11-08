/**
 * Exercise: 8-1 - Rewrite the program cat from Chapter 8 using read, write, 
 * open and close instead of their standard library equivalents. Perform 
 * experiments to determine the relative speeds of the two versions.
 **/


#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"

#define BUFSIZE 1024

// cat : concatenate files - read / write / open / close
main(int argc, char *argv[]) {

    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1) {               // no args, copy standard input
        filecopy(0, 1)
    }
    else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                error("cat: can't open %s", *argv);
            }
            else {
                filecopy(fd, 1);
                close(fd);
            }
        }
    }
    return 0;
}

// filecopy: copy file ifp to file ofp
void filecopy(int ifd, int ofd) {

    int n;
    char buf[BUFSIZE];

    while ((n = read(ifd, buf, BUFSIZE)) > 0) {
        if (write(ofd, buf, n) != n) {
            printf("cat: write error");
        }
    }
}
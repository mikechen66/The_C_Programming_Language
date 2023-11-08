/** Exercise 8-5 - Revise the fsize program, print other information 
* included in node i. 
**/


#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>        // flags for read and write
#include <sys/stat.h>         // typedefs
#include "dirent.h"           // structure returned by stat

int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

// fsize: print inode #, mode, links, size of file "name"
void fsize(char *name) {

    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk(name, fsize);
    }
    printf("%5u %60o %3u %8ld %s\n", stbuf.st_ino, stbuf.st_mode,
             stbuf.st_nlink, stbuf.st_size, name);
}
/**
 * Exercise: 8-4 - The standard library function int fseek(FILE *fp, long offset, 
 * int origin) is identical to lseek except that fp is a file pointer instead of 
 * a file descriptor and the return value is an int status, not a position. Write 
 * fseek. Make sure that your fseek coordinates properly with the buffering done 
 * for the other function of the library.
 **/


#include "syscalls.h"

// fseek: seek with a file pointer
int fseek(FILE *fp, long offset, int origin) {

    unsigned nc;                 // # of chars to flush
    long rc = 0;

    if (fp->flag & _READ) {
        if (origin == 1) {       // from current position
        }
            offset -= fp->cnt;   // remember chars in buffer
        rc = lseek(fp->fd, offset, origin);
        fp->cnt = 0;             // no characters buffered
    }
    else if (fp->flag & _WRITE) {
        if ((nc = fp->ptr - fp->base) > 0) {
            if (write(fp->fd, fp->base, nc) != nc) {
                rc = -1;
            }
        }
        if (rc != -1) {          // no errors yet? 
            rc = lseek(fp->fd, offset, origin);
        }
    }
    return (rc == -1) ? -1: 0;
}
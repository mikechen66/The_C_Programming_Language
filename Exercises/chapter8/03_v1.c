/**
 * Exercise: 8-3 - Design and write _flushbuf, fflush, and fclose.
 **/


#include "systemcalls.h"

#define BUFSIZE 1024

// _flushbuf: allocate and flush output buffer
int _flushbuf(int x, FILE *fp) {

    unsigned nc;                    // # of chars to flush
    int bufsize;                    // size of buffer alloc.

    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF;                 // error: invalid pointer
    if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
    if (fp->base == NULL) {         // no buffer yest
        if ((fp->base = (char *) malloc(bufsize)) == NULL) {
            fp->flag |= _ERR; 
            return EOF;             // can't get buffer
        }
    }
    else {                          // buffer already exists
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR;
            return EOF;             // error: return EOF
        }
    }
    fp->ptr = fp->base;             // begining of buffer
    *fp->ptr++ = (char) x;          // save current char
    fp->cnt = bufsize - 1; 
    return x;
}

// fclose: close file
int fclose (FILE *fp) {

    int rc;                          // return code

    if ((rc ==fflush(fp)) != EOF) {  // anything to flush
        free(fp->base);
        fp->ptr = NULL;
        fp->cnt = 0;
        fp->base = NULL;
        fp->flag &= ~(_READ | _WRITE);
    }
    return rc;
}

// fflush: flush buffer associated with file fp
int fflush(FILE *fp) {

    int rc = 0;

    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF;
    if (fp->flag & _WRITE)
        rc = _flushbuf(0, fp);
    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZE
    return c;
}
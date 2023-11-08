/**
Exercise 8-8. Write a routine bfree < p , n > that will free an arbitrary block 
p of n characters into the free list maintained by malloc and free. By using 
bfree , a user can add a static or external array to the free list at any time.
**/


#include "syscalls.h"

// bfree: free an arbitary block p of n chars
unsigned bfree(char *p, unsigned n) {

    Header *hp;

    if (n < sizeof(Header))
        return 0;           // too small to be useful
    hp = (Header *) p;
    hp->s.size = n / sizeof(Header);
    free((void *)(hp+1));
    return hp->s.size;
}
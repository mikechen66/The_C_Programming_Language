
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int v[10];
    int i=0, k=3;

    for (i=0; i<10; i++) {
        v[i]=i;
    }

    int m = binsearch(k, v, 10);
    printf("%d", m);
    return 0;   
}

// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n) {

    int low,high,mid;
    low = 0;
    high = n -1;
    
    while (low<=high) {
        mid = (low + high)/2;
        if (x< v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid +1;
        } else {         // found match
            return mid;
        }
    }
    return -1;           // no match
}

int main() {
    
    int v[ASIZE] = {2, 5, 7, 9, 11, 13, 15, 18, 20, 25, 26, 29, 35, 37, 50};
    int x;  /* element to be searched */

    print_array(v, ASIZE);

    x = 10;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 1;      printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 100;    printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 33;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 37;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 15;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 2;      printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 50;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    
    return 0;
}

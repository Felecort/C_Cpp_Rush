#include <stdio.h>


int main(){
    unsigned char d = 10;

    unsigned char *ptr_d = &d; // or...
    // unsigned char *ptr_d;
    // ptr_d = &d;

    printf("ptr_d = %p\n*ptr_d  = %d\nd = %d\npointer for d = %p\nPointer for pointer %p\n\n",
            ptr_d,      *ptr_d,       d,      &d,                 &ptr_d);
    *ptr_d = 250;
    printf("ptr_d = %p\n*ptr_d  = %d\nd = %d\npointer for d = %p\nPointer for pointer %p\n\n",
            ptr_d,      *ptr_d,       d,      &d,                 &ptr_d);
    
    return 0;
}
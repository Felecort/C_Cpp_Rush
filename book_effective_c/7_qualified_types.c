#include <stdio.h>
#include <stdlib.h>

void f(unsigned int n, int * restrict p, int * restrict q);

int main(void){
    // Const
    int i = 12;
    const int j = 12;

    const int *ip = &i;
    const int *jp = &j;

    *(int *)ip = 42; // Ok
    *(int *)jp = 42; // undefined behaviour. can change conts, but not always

    // Volatile
    volatile int port;
    port = port;

    

    return EXIT_SUCCESS;
}


void f(unsigned int n, int * restrict p, int * restrict q){
    while (n-- > 0)
        *p++ = *q++;
}
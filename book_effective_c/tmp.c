#include <stdio.h>
#include <stdlib.h>


int main(void){
    int n = 10;
    int *n_ptr = &n;

    printf("pointer: %p, val: %d\n", n_ptr, *n_ptr);
    n_ptr++;
    printf("pointer: %p, val: %d\n", n_ptr, *n_ptr);
    n_ptr--;
    printf("pointer: %p, val: %d\n", n_ptr, *n_ptr);

    return EXIT_SUCCESS;
}

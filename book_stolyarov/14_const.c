#include <stdio.h>


int main(){
    // constant are noy so constantly
    const int iterations = 12;
    int *ptr_iter = &iterations;
    printf("%d\n", iterations);
    *ptr_iter = 45678;
    printf("%d\n", iterations);

    // Pointer for unmutable memory cell
    // Not an ummutable pointer
    const int *ptr;
    // Unmutable pointer
    int x = 10;
    int * const ptr_x = &x;
    return 0;
}
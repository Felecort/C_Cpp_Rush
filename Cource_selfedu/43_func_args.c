#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap_2(int * a, int * b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}


int main(void){
    char string[] = "Hello, func";
    int x = 5, y = 10;
    printf("a = %d, b = %d\n", x, y);
    swap_2(&x, &y);
    printf("a = %d, b = %d\n", x, y);

    return EXIT_SUCCESS;
}
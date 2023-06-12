#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

int globe;

int max(int a, int b){
    return a > b ? a : b;
}

int f(void){
    return globe + 10;
}

int g(void){
    globe = 42;
    return globe;
}


int main(void)
{
    int max_value;
    max_value = max(f(), g());
    printf("max = %d\n", max_value);
    // int i = CHAR;
    globe = 0;
    max_value = max(g(), f());
    printf("max = %d\n", max_value);

    return EXIT_SUCCESS;
}
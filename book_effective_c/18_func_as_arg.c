#include <stdio.h>
#include <stdlib.h>

#define LEN 3
int mult(int a, int b)
{
    return a * b;
}

int sum(int a, int b)
{
    return a + b;
}

void handler(int a[], int b[], int (*func)(int, int))
{
    int total_pure_call = 0;
    int total_ptr_call = 0;
    for (int i = 0; i < LEN; i++){
        total_pure_call += func(a[i], b[i]);
        total_ptr_call += (*func)(a[i], b[i]);
    }
    printf("pure: %d \nptr: %d\n", total_pure_call, total_ptr_call);
}

int main(void){
    int a[LEN] = {2, 3, 4};
    int b[LEN] = {2, 3, 4};
    handler(a, b, mult);
    handler(a, b, sum);
    printf("func: %p\nfunc ptr: %p\nfunc data: %p", mult, &mult, *mult);
    return EXIT_SUCCESS;
}

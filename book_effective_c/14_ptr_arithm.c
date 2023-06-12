#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN 5

int m[LEN] = {1, 2, 3, 4, 5};

int sum_m_elems(void){
    int j = 0;
    for (int *pi = &m[0]; pi < &m[LEN]; pi++)
        j += *pi;
    return j;
}


int main(void){
    int res = sum_m_elems();
    printf("res = %d \n", res);

    return EXIT_SUCCESS;
}
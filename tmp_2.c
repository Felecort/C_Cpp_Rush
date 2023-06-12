#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char name[] = "variables";
double big_arr[10];

int main(void)
{
    for (int i = 0; i < 10; ++i){
        printf("%d ", big_arr[i]);
    }

    return EXIT_SUCCESS;
}
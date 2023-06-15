#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int is_even(int x)
{
    return x % 2 == 0;
}

typedef int (*PTR_FUNC)(int);
typedef char (*PTR_ARR)[4];

int main(void)
{
    // Are equal 
    PTR_FUNC func_even = is_even;
    int (*func_even_2)(int) = is_even;
    printf("%d, %d", func_even_2(23), func_even(23));

    // Are equal
    char arr_2d[5][4] = {0};
    PTR_ARR ptr_arr = arr_2d;
    char (*ptr_arr_2)[4] = arr_2d;


    return EXIT_SUCCESS;
}
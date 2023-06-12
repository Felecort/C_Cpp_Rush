#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10


void filter(int dst[], size_t size_dts,
            const int src[], size_t size_src,
            int (* is_correct) (int) )
{
    for (int i = 0; i < size_dts; ++i)
        dst[i] = 0;
    
    for (int i = 0, j = 0; i < size_src; ++i){
        if (is_correct(src[i])){
            dst[j] = src[i];
            j++;
        }
    }
}


int is_even(int x)
{
    return (x % 2) == 0;
}

int is_odd(int x)
{
    return !(x % 2) == 0;
}

int is_positive(int x)
{
    return x > 0;
}

int main(void)
{
    int digits[] = {-3, 4, 5, 6, -5, -3};
    int result[SIZE];
    int (*criterials[]) (int) = {is_even, is_odd, is_positive};

    printf("%d\n", sizeof(criterials));
    for (int idx = 0; idx < sizeof(criterials) / sizeof(criterials[0]); idx++){
        filter(result, SIZE, digits, sizeof(digits) / sizeof(digits[0]), criterials[idx]);

        for (int i = 0; i < SIZE; ++i)
            printf("%d ", result[i]);
        printf("\n");
    }
     


    return EXIT_SUCCESS;
}
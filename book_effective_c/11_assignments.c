#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int main(void)
{
    signed char c;
    int i = INT_MAX;
    long k;
    k = (c = i);
    printf("c = %d, i = %d, k = %d \n", c, i, k);

    i = 7;
    int res = ++i + ++i;
    printf("i++ + i++ = %d \n", res);

    return EXIT_SUCCESS;
}
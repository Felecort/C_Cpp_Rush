#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int p = 1;
    int n = 7;
    for (register int i = 2; i <= n; ++i){
        p *= i;
    }
    printf("p = %d", p);

    return EXIT_SUCCESS;
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int main(void)
{
    signed char c_result, c1, c2, c3;
    c1 = 100; c2 = 3; c3 = 4;
    // c_result = (c1 * c2) / c3;
    c_result = c1 * c2;
    printf("%d\n", c_result);
    c_result /= c3;
    printf("%d\n", c_result);

    unsigned int ui = UINT_MAX;
    signed char c = -1;
    if (c == ui){
        puts("-1 = 4 billions");
        printf("%d, %d", c, ui);
    }

    return EXIT_SUCCESS;
}
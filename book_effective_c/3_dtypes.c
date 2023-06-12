#include <stdio.h>
#include <stdlib.h>
// Contain booleans
#include <stdbool.h>
// Contain limits for int dtype
#include <limits.h>
// like a config
#include <stdint.h>
#include <inttypes.h>



int main(void){
    _Bool flag1 = 0;
    bool flag2 = false;
    unsigned char symbol = 0;
    for (; symbol < 255; symbol++)
        printf("%c", symbol);

    return EXIT_SUCCESS;
}
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    unsigned int ui = UINT_MAX;
    ui++;
    printf("%u\n", ui);
    ui--;
    printf("%u\n", ui);

    // int n = 4;
    // for(unsigned int i = n; i >= 0; --i){} // infinity loop

    int sum = 225;
    unsigned int counter = UINT_MAX - 500;
    // Good way to check overflow
    if (ui > UINT_MAX - sum){}
        // call some func
    else
        sum += counter;
    return EXIT_SUCCESS;
}
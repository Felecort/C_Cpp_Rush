#include <stdio.h>

// leksemas
#define PRINTF_2    "%d, %d\n"
#define PRINTF_D printf("digit %d\n", digit)

#define int 1
#undef int

int main(){

    int x, y;
    x = 10;
    y = 11;
    printf(PRINTF_2, x, y);

    int digit = 10;
    PRINTF_D;
    return 0;
}
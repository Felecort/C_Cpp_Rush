#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    char str[32];
    double n;
    n = 30 * (2 * M_PI) / 360;
    sprintf(str, "%.7f", n);
    printf(str);

    return 0;
}
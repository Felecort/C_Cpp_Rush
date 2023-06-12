#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main(){
    double *k;
    int degrees = 360;
    k = malloc(degrees * sizeof(double));

    for (int i = 0; i < degrees; i++){
        k[i] = sin((2 * M_PI / 360) * (double)i);
        printf("degree: %i, sin: %.5lf\n", i, k[i]);
    }

    free(k);
    return 0;
}
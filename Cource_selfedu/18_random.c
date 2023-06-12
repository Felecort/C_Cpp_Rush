#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(){
    time_t t = time(NULL);
    srand(t);

    int r1 = rand();
    int r2 = rand();
    printf("time = %d\nr1 = %d\nr2 = %d\n%d\n", t, r1, r2, rand());

    int range = 10;
    r1 = (rand() % 10) - 5;
    r2 = (rand() % 10) - 5;
    double r_float = (double)rand() / (double)RAND_MAX;
    printf("r1 = %d\nr2 = %d\nr_float = %.2f\n", r1, r2, r_float);

    return 0;
}
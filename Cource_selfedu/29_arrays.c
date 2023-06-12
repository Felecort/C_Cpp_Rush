#include <stdio.h>
#include <math.h>
#define TOTAL_LENGTH 30

int main(){
    double y_sin[TOTAL_LENGTH];
    y_sin[0] = 0;
    y_sin[5] = 0;
    
    for (int i = 0; i < TOTAL_LENGTH; i++){
        printf("%d ", y_sin[i]);
    }

    return 0;
}
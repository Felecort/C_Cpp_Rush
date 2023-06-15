#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
    time_t t = time(NULL);
    srand(t);
    int size = rand() % 10;
    int array[size]; // is a VLA
    printf("elements: %d, real: %d \n", sizeof(array) / sizeof(array[0]), size);
    
    memset(array, 'a', size - 2);
    printf("%s", array);
    // int input = getchar();
}
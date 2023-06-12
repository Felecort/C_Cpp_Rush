#include <stdio.h>

// a and b are pointer, not pure variables
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


int main(){
    int *null_pointre = NULL;

    int a = 10, b = 45;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
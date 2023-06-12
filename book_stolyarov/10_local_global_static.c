#include <stdio.h>

void next_number(){
    static int n = 0; // Define only once
    printf("%d\n", n);
    n++;
}


int main(){
    next_number();
    next_number();
    next_number();
    next_number();
    return 0;
}
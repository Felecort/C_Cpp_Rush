#include <stdio.h>


int main(){
    // Array of pointers
    int *ptr_arr[20];
    int a;
    a = 27;
    ptr_arr[5] = &a;
    printf("\n%p, %d\n", ptr_arr[5], ptr_arr[5][0]);

    return 0;
}
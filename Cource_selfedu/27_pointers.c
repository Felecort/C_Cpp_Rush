#include <stdio.h>


int main(){
    int arg = 777;
    int *ptr_arg;
    char *ptr;

    ptr_arg = &arg;
    ptr = ptr_arg; // DIFFERENT TYPES
    ptr = (char *)ptr_arg; // Sometimes it's useful

    printf("*ptr = %d, arg = %d\n", *ptr, arg);
    *ptr = 0;
    // *ptr_arg = 100;
    printf("*ptr = %d, arg = %d\n", *ptr, arg);

    int *p;
    *p = 4567; // Compile time error!
    printf("%p\n", p);

    int *p2 = NULL; // Mean: do not use!
    if (p2 == NULL){
        printf("DO NOT USE P2 POINTER");
    }

    return 0;
}
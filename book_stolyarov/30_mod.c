#include "30_mod.h"


// Visible from everywhere
extern int very_bad_global_var = 3.14;

// Can use only in current file
static void invisible_func(){
    printf("\n");
}


void print_arr(const char *arr, int length){
    int i;
    for (i = 0; i < length; i++)
        printf("%c", arr[i]);
    invisible_func();
}

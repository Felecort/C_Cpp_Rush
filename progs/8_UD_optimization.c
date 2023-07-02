#include <stdio.h>
#include <stdlib.h>

void foo(int *ptr)
{
    int d = *ptr;
    if(ptr == NULL)
        return;
    *ptr = 777;
}


int main(void)
{
    int var = 9;
    int *ptr_var = &var;
    foo(ptr_var); 
    return EXIT_SUCCESS;
}
#include <stdio.h>

typedef long double lld;

int simple_function(int x)
{
    return 0;
}

lld complex_function(lld a, lld b, lld c, lld d, lld e, lld f, lld g){
    return 1.2;
}

int main(void)
{
    char simple_var;
    char *simple_ptr;
    simple_ptr = &simple_var;
    printf("char ptr: %p, size: %d \n", &simple_var, sizeof(simple_var));
    printf("simple ptr: %p, size: %d \n", simple_function, sizeof(simple_function));
    printf("complex ptr: %p, size: %d \n", complex_function, sizeof(complex_function));

    printf("lld: %d \n", sizeof(lld));
    char *test_ptr;
    printf("non init ptr: %p", test_ptr);

    return 0;
}
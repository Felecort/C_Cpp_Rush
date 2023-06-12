#include <stdio.h>


int main(void)
{
    int var_i = 1003;
    printf("int = %d \n", var_i);
    printf("hex = %x \n", var_i);
    printf("int = %X \n", var_i);
    printf("int = %f \n\n", var_i);

    long long value = 12345678901234;
    printf("val = %d \n", value);
    printf("val = %ld \n", value);
    printf("val = %lld \n\n", value);

    int var_j = -1233;
    double var_d = 54.5433;
    printf("[%-10d]\n", var_j);
    printf("[%-10f]\n", var_d);
    return 0;




}
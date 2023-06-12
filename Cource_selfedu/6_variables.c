#include <stdio.h>


int main(void)
{
    int var, size;
    size = var = 100;
    int abobre = 10;

    int dec = 100, hex = 0x1FA, oct = 0123;

    int var_new = 100UL;
    int ch = 'a';
    printf("ch = %c, code = %d\n", ch, ch);

    double d1, d2, d3, d4;
    d1 = 10.0;
    d2 = -7;
    d3 = 1e2;
    d4 = 5e-5f;
    int size_double = sizeof(d4);
    printf("%d", size_double);

    int a = 10;
    int b = 7;
    double var = (double)a / (double)b;
    return 0;
}
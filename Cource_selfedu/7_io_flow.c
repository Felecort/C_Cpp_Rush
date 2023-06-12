#include <stdio.h>


int main(void)
{
    int input = getchar();
    int res = putchar(input);
    printf("\ninput %d, %c\n", input, input);
    printf("output %d, %c", res, res);
    return 0;
}
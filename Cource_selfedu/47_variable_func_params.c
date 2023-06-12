#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

int sum(int count, ...)
{
    int s = 0;
    va_list arg;
    va_start (arg, count);

    for (int i = 0; count > i; ++i){
        s += va_arg(arg, int);
    }
    va_end(arg);
    return s;
}


int main(void)
{

    int res = 0;
    res = sum(4, 12, 23, 43, 54);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}
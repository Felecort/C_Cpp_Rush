#include <stdarg.h>


int sum(int c, ...)
{

    va_list vl;
    int s = c, k;
    va_start(vl, c);

    while ((k = va_arg(vl, int)) != 0)
        s += k;
    va_end(vl);
    return s;
}

int main()
{


    return 0;
}
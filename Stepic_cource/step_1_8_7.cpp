#include <iostream>

#define MAX(x, y, r) r = (x); if (r < (y)) r = (y);
int main(void)
{
    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a += b, b, c);
    std::cout << c << std::endl;


}
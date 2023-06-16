#include <iostream>

using std::cout;
using std::endl;
#define MAX(x, y, r) r = (x); if (r < (y)) r = (y);

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a += b, b, c);
    cout << c << endl;


}
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename Num>
Num square(Num x) {return x * x;}

int main(void)
{
    int a = 5;
    int b = square(a);
    
    
    return 0;
}
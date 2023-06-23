#include <iostream>

using std::cout;
using std::cin;
using std::endl;



int foo(int n) {
    cout << "foo call" << endl;
    if (n <= 0)
        return 1;
    return foo((n * 2) / 3) + foo(n - 2);
}

int main(void)
{
    
    foo(3);
    return 0;
}
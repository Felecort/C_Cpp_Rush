#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ref_type(int &x){ // Takes a lvalue
    cout << "lvalue " << endl;
}

void ref_type(int &&x){ // Takes a rvalue
    cout << "rvalue " << endl;
}
int main(void)
{
    auto x = 1;
    ref_type(x);
    ref_type(1);
    ref_type(x + 2);

    return 0;
}
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int foo()
{
    int * m[1];
    cout << "Hello" << endl;
    m[2] = m[3];
    return 2;
}

int bar()
{

    int *m[1] = {0};
    m[3] = m[2];
    m[2] = (int *)foo;
    return 0;
}

int main(void)
{
    bar();
    return 0;
}
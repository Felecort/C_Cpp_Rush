#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct IntArray2D {
    int &get(size_t i, size_t j) {
        return data[i * b + j];
    }
    size_t a;
    size_t b;
    int *data;
};

int main(void)
{
    
    IntArray2D m = foo();
    
    return 0;
}
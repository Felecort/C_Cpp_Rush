#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Obj
{
    int i;
    char get_c() const {
        return 'h';
        }
};


int main(void)
{
    int i = 10;
    int j = 45;
    const int * const_i_ptr = &i;
    int const * i_const_ptr = &i;

    const_i_ptr = &j;
    i_const_ptr = &j;

    int * const i_ptr_const = &j;
    const int * const const_i_ptr_const = &i;

    const int const * const const_i_const_ptr_const = &j;  // No sence



    return 0;
}
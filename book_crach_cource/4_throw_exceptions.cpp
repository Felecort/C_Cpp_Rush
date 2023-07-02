#include <iostream>
#include <stdexcept>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

struct Groucho {
    void forget(int x){
        if (x == 0xFACE) {
            throw std::runtime_error{"I'd be glad to make an exception. \n"};
        }
        printf("Forgot 0x%X\n", x);
    }
};

int main(void)
{
    Groucho g;
    g.forget(0xC0FFEE);   
    g.forget(0xFACE);   
    
    return 0;
}
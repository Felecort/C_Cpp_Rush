#include <iostream>
#include <stdexcept>

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
    try {
        g.forget(0xC0DE);
        g.forget(0xFACE);
        // Will not execute
        g.forget(0xC0FFEE);
    } catch (const std::runtime_error& e) {
        cout << "Exceprion caught with message " << e.what(); 
    }
    
    
    return 0;
}
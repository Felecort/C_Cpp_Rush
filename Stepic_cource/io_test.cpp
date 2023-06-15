#include <iostream>

int main(void)
{
    int i = 42;
    double d = 3.14;
    const char *s = "C-style string";
    std::cout << "int " << i << std::endl;
    std::cout << "double " << d << std::endl;
    std::cout << "str " << s << std::endl;
}
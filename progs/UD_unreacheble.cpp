#include <iostream>

int main()
{
    while(1);
}

// Clang will call this function
void unreacheble()
{
    std::cout <<" Hello ";
}
#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::endl;


int main(void)
{
    std::list<std::string> l = {"One", "Two", "Three"};
    std::list<std::string>::iterator i = l.begin();
    for(; i != l.end(); ++i){
        if(*i == "Two")
            break;
    }
    
    return 0;
}
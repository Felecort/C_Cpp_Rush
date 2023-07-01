#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


int main(void)
{
    
    std::vector<std::string> v = {"one", "two"};
    v.reserve(100);
    v.push_back("three");
    v.emplace_back("Four");
    cout << v[2] << endl;
    
    return 0;
}
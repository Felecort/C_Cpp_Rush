#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;


int main(void)
{
    std::map<std::string, int> phonebook;
    phonebook.emplace("Lisa", 8764467);
    phonebook.emplace("Marina", 994935);
    phonebook.emplace("Polina", 34567);
    
    
    
    return 0;
}
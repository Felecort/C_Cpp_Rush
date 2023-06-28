#include <iostream>
#include <tuple>

using std::cout;
using std::cin;
using std::endl;

std::tuple<std::string, int, int> getUnitInfo(int id){
    if(id == 0) return std::make_tuple("Elf", 60, 9);
    if(id == 1) return std::make_tuple("Dwarf", 80, 6);
    if(id == 2) return std::make_tuple("Orc", 30, 3);
}

int main(void)
{
    auto ui0 = getUnitInfo(0);
    cout << "race: " << std::get<0>(ui0) << endl;
    cout << "hp: " << std::get<1>(ui0) << endl;
    cout << "iq: " << std::get<2>(ui0) << endl;
    
    
    return 0;
}
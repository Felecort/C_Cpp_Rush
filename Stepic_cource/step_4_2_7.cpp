#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

struct String {
    String(char const *s){
        size = strlen(s);
        str = new char[size + 1];
        for (size_t i = 0; i < size + 1; i++){
            str[i] = s[i];
        } 
    }
    char & at(size_t idx)       {
        return str[idx]; }
    char   at(size_t idx) const {
        return str[idx]; }
    size_t size;
    char *str;
};



int main(void)
{
    String greet("Hello");
    char ch1 = greet.at(0);
    String const const_greet("Hello, Const!");
    char const &ch2 = const_greet.at(0);

    return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    std::string s1 = "hello";
    cout << s1.size() << endl;

    std::string s2 = ", world!";

    s1 = s1 + s2;

    if (s1 == s2){
        cout << "s1 == s2" << endl;
    }
    
    
    return 0;
}






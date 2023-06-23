#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct Person {
    string name() const {return name_;}
    int age() const {return age_;}
private:
    string name_;
    int age_;
};

struct Student : Person {
    string university() const {return uni_;}
private:
    string uni_;
};


int main(void)
{
    
    
    
    return 0;
}
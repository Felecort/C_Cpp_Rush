#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct Person {
    Person(string name, int age) : name_(name), age_(age)
    {}

    string name() const {return name_;}
    int age() const {return age_;}
private:
    string name_;
    int age_;
};

struct Student : Person {
    Student(string name, int age, string uni)
        : Person(name, age), uni_(uni)
    {}

    string university() const {return uni_;}
private:
    string uni_;
};


int main(void)
{
    Student s("Alex", 25, "Foxford");
    Person &l = s; // Student & -> Person &
    Person *r = &s;// Student * -> Person *

    Person p = s; // Person("Alex", 25)
    
    
    return 0;
}
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Person_1 {
    Person_1(string s) : name_(s) {};
    string name() const {return name_;}
    string name_;
};

struct Person_2 {
    Person_2(string s) : name_(s) {};
    virtual string name() const {return name_;}
    string name_;
};

struct Professor_1 : Person_1 {
    Professor_1(string s) : Person_1(s) {};
    string name() const {
        return "Prof. " + Person_1::name(); // Explisit call method `name`
    }
};

struct Professor_2 : Person_2 {
    Professor_2(string s) : Person_2(s) {};
    string name() const {
        return "Prof. " + Person_2::name(); // Explisit call method `name`
    }
};

int main(void)
{
    
    Professor_1 pr_1("Stroustrup");
    Person_1 *p_1 = &pr_1;
    // Choose in compiletime
    cout << p_1->name() << endl; // Strousturp. Not Prof.

    Professor_2 pr_2("Stroustrup");
    // Choose in runtime
    Person_2 *p_2 = &pr_2;
    cout << p_2->name() << endl; // Prof. Strousturp.
    
    return 0;
}
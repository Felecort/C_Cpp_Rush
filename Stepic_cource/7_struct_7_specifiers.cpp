#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct Point{
    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}
    double x;
    double y;
};



int main(void)
{
    Point p1; // construct by default
    Point p2(); // Function defenition

    double k = 4.4;
    Point p3(int(k)); // Function defenition
    Point p4((int)(k)); // variable defenition
    
    return 0;
}
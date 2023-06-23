#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Vector {
    Vector(double x, double y) : x(x), y(y)
    {}
    double x;
    double y;
};

std::istream& operator>>(std::istream &is, Vector &p){
    is >> p.x >> p.y;
    return is;
} 

std::ostream& operator<<(std::ostream &os, Vector const &p){
    os << p.x << " " << p.y;
    return os;
} 

int main(void)
{
    Vector point(23, 44);
    cout << point << endl;
    
    
    return 0;
}
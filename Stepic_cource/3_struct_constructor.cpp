#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Point{
    Point() {
        x = y = 0;
    }
    Point (double x, double y){
        this->x = x;
        this->y = y;
    }
    double x;
    double y;
};

int main(void)
{
    Point p1;
    cout << "x = " << p1.x << " y = " << p1.y << endl;

    Point p2(2.3, 5.4);    
    cout << "x = " << p2.x << " y = " << p2.y << endl;
    
    return 0;
}
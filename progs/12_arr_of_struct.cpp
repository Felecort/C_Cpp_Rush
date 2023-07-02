#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Point {
    Point(int x=0, int y=0) : x(x), y(y)
    {
        cout << "Constructor called" << endl;
        dims = new int[2]{0, 0};
    }
    ~Point(){
        delete [] dims;
        cout << "Detructor called" << endl;
    }
    int x;
    int y;
    int *dims;
};


int main(void)
{
    Point *arr_of_points = new Point[2]{{1, 2}, {3, 4}};
    cout << arr_of_points[0].x << endl;
    delete [] arr_of_points;

    cout << "------------------------------------\n" << endl;
    {
        Point p = {1, 4};
    }

    return 0;
}
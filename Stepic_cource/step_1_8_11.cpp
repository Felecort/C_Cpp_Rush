#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int lines = 0;
    int value;
    cin >> lines;
    int res;
    int power = 1;
    for (int i = 0; i < lines; i++){
        cin >> value;
        value++;
        res = 2;
        power = 1;
        while (res < value){
            res *= 2;
            power++;
        }
        power--;
        cout << power << endl;
    }
    return 0;
}